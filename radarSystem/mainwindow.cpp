#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , r(445.0)
    , angleOffset(0.05)
    , laserActive(false)
    , autoMode(false)
    , previousAutoMode(false)
    , previousSliderState(true)
    , calibrationFactor(1.0)
    , calibrationOffset(0.0)
{
    ui->setupUi(this);

    // Load bg image (radar)
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    pix = QPixmap(":/src/radar.png");
    scene->addPixmap(pix);

    // Set up QSerialPort
    arduino = new QSerialPort;
    arduino_is_available = false;
    radarSerial = "COM9";

    // Initialize needle at 0 degrees
    QPen blackpen(Qt::black);
    QBrush graybrush(Qt::gray);
    t_up = angleOffset;
    t_lo = -angleOffset;
    triangle.append(QPointF(r * qCos(t_up) + 505, -r * qSin(t_up) + 495));
    triangle.append(QPointF(505, 495));
    triangle.append(QPointF(r * qCos(t_lo) + 505, -r * qSin(t_lo) + 495));
    needle = scene->addPolygon(triangle, blackpen, graybrush);
    needle->setOpacity(0.30);

    // Check which port the Arduino is on
    foreach (const QSerialPortInfo &serialPortInfo, QSerialPortInfo::availablePorts()) {
        if (serialPortInfo.hasVendorIdentifier() && serialPortInfo.hasProductIdentifier()) {
            if (serialPortInfo.vendorIdentifier() == arduino_uno_vendorID) {
                if (serialPortInfo.productIdentifier() == arduino_uno_productID) {
                    radarSerial = serialPortInfo.portName();
                    arduino_is_available = true;
                    qDebug() << "Port available!";
                }
            }
        }
    }

    // Setup port if available
    if (arduino_is_available) {
        arduino->setPortName(radarSerial);
        arduino->open(QSerialPort::ReadWrite);
        arduino->setBaudRate(QSerialPort::Baud115200);
        arduino->setDataBits(QSerialPort::Data8);
        arduino->setParity(QSerialPort::NoParity);
        arduino->setStopBits(QSerialPort::OneStop);
        arduino->setFlowControl(QSerialPort::NoFlowControl);
        QObject::connect(arduino, SIGNAL(readyRead()), this, SLOT(readSerial()));
    } else {
        QMessageBox::warning(this, "Port error", "Couldn't find Arduino");
    }

    autoMode = false;
    ui->button_auto->setText("Start Auto");

    autoTimer = new QTimer(this);
    connect(autoTimer, &QTimer::timeout, this, &MainWindow::updateServoAuto);

    laserActive = false;
    laserTimer = new QTimer(this);
    connect(laserTimer, &QTimer::timeout, this, &MainWindow::deactivateLaser);

    resumeTimer = new QTimer(this);
    connect(resumeTimer, &QTimer::timeout, this, &MainWindow::resumeOperation);

    // Initialize 3D visualization
    visualization3D = new Radar3DVisualization(this);
    ui->layout3D->addWidget(visualization3D);

    // Initialize height tracking chart
    heightChart = new HeightTrackingChart(this);
    ui->layoutHeightChart->addWidget(heightChart);

    // Add calibration button
    QPushButton *calibrateButton = new QPushButton("Calibrate", this);
    ui->layout()->addWidget(calibrateButton);
    connect(calibrateButton, &QPushButton::clicked, this, &MainWindow::performCalibration);
}

void MainWindow::readSerial() {
    QByteArray data = arduino->readAll();
    serialBuffer.append(QString::fromUtf8(data));

    while (serialBuffer.contains('\n')) {
        int lineEnd = serialBuffer.indexOf('\n');
        QString line = serialBuffer.left(lineEnd).trimmed();
        serialBuffer = serialBuffer.mid(lineEnd + 1);

        if (line.contains(',')) {
            processRadarData(line);
        } else if (line == "LASER_ACTIVATED") {
            handleLaserStatus("LASER_ACTIVATED");
        } else if (line == "LASER_DEACTIVATED") {
            handleLaserStatus("LASER_DEACTIVATED");
        }
    }
}

void MainWindow::processRadarData(const QString &data) {
    QStringList parts = data.split(',');
    if (parts.size() == 3) {
        float angle = parts[0].toFloat();
        float distance = parts[1].toFloat();
        float rawHeight = parts[2].toFloat();
        float height = getCalibratedHeight(rawHeight);

        updateDetectionPoint(angle, distance, height);
        visualization3D->updatePoint(angle, distance, height);
        heightChart->addHeightDataPoint(height);

        // Update labels
        ui->angleLabel->setText(QString("%1°").arg(angle, 0, 'f', 1));
        ui->rangeLabel->setText(QString("%1 cm").arg(distance, 0, 'f', 1));
        ui->heightLabel->setText(QString("%1 cm").arg(height, 0, 'f', 1));

        // Update status based on distance
        if (distance >= LASER_ACTIVATION_MIN_RANGE && distance <= LASER_ACTIVATION_MAX_RANGE) {
            ui->detectionStatusLabel->setText("Object Detected (Laser Range)");
            ui->detectionStatusLabel->setStyleSheet("color: red;");
            if (!laserActive) {
                handleLaserActivation();
            }
        } else {
            ui->detectionStatusLabel->setText(distance > LASER_ACTIVATION_MAX_RANGE && distance <= MAX_DETECTION_RANGE ? "Object Detected" : "No Object");
            ui->detectionStatusLabel->setStyleSheet(distance > LASER_ACTIVATION_MAX_RANGE && distance <= MAX_DETECTION_RANGE ? "color: orange;" : "color: green;");
        }
    }
}

void MainWindow::setSliderEnabled(bool enabled) {
    ui->verticalSlider->setEnabled(enabled);
    for (QPushButton* button : {ui->button0, ui->button45, ui->button90, ui->button135, ui->button180}) {
        button->setEnabled(enabled);
    }
}

void MainWindow::handleLaserStatus(const QString &status) {
    if (status == "LASER_ACTIVATED") {
        laserActive = true;
        updateLaserStatus("Laser: On");
        laserTimer->start(2000);
        if (autoMode) {
            autoTimer->stop();
        }
    } else if (status == "LASER_DEACTIVATED") {
        laserActive = false;
        updateLaserStatus("Laser: Off");
        laserTimer->stop();
        if (autoMode) {
            autoTimer->start(50);
        }
    }
}

void MainWindow::deactivateLaser() {
    laserActive = false;
    updateLaserStatus("Laser: Off");
    arduino->write("LASER_OFF\n");
    laserTimer->stop();
    resumeTimer->start(0);  // Timer to resume normal operation immediately
}

void MainWindow::handleLaserActivation() {
    laserActive = true;
    updateLaserStatus("Laser: On");
    arduino->write("LASER_ON\n");
    laserTimer->start(2000);
}

void MainWindow::resumeOperation() {
    resumeTimer->stop();
    if (autoMode) {
        arduino->write("AUTO\n");
    } else {
        arduino->write("MANUAL\n");
    }
}

void MainWindow::updateLaserStatus(const QString &status) {
    ui->textEdit->setPlainText(status);
}

void MainWindow::updateServo(QString command) {
    if (arduino->isWritable()) {
        arduino->write(command.toUtf8());
    } else {
        qDebug() << "Couldn't write to serial!";
    }
}

void MainWindow::updateServoAuto() {
    if (!laserActive) {
        static int angle = 0;
        static bool increasing = true;
        static const int stepSize = 2;

        if (increasing) {
            angle += stepSize;
            if (angle >= 180) {
                angle = 180;
                increasing = false;
            }
        } else {
            angle -= stepSize;
            if (angle <= 0) {
                angle = 0;
                increasing = true;
            }
        }

        updateServo(QString::number(angle) + "\n");
        ui->verticalSlider->setValue(angle);
    }
}

void MainWindow::updateDetectionPoint(float angle, float distance, float height) {
    if (distance > 0 && distance <= MAX_DETECTION_RANGE) {
        float radAngle = qDegreesToRadians(angle);

        // Scale the distance to fit within the radar display
        float scaledDistance = (distance / MAX_DETECTION_RANGE) * r;

        float x = scaledDistance * qCos(radAngle);
        float y = scaledDistance * qSin(radAngle);

        QGraphicsRectItem* point = scene->addRect(505 + x, 495 - y, 3, 3, QPen(Qt::red), QBrush(Qt::red));
        detectionPoints.append(point);

        clearOldDetectionPoints();
    }

    // Update needle position (always update, even if no object detected)
    float radAngle = qDegreesToRadians(angle);
    float t_up = radAngle + angleOffset;
    float t_lo = radAngle - angleOffset;
    QPolygonF newTriangle;
    newTriangle.append(QPointF(r * qCos(t_up) + 505, -r * qSin(t_up) + 495));
    newTriangle.append(QPointF(505, 495));
    newTriangle.append(QPointF(r * qCos(t_lo) + 505, -r * qSin(t_lo) + 495));
    needle->setPolygon(newTriangle);
}

void MainWindow::clearOldDetectionPoints() {
    while (detectionPoints.size() > 50) {
        QGraphicsRectItem* point = detectionPoints.takeFirst();
        scene->removeItem(point);
        delete point;
    }
}

void MainWindow::performCalibration() {
    QMessageBox::information(this, "Calibration", "Place an object at a known height and click OK.");

    float knownHeight = QInputDialog::getDouble(this, "Calibration", "Enter the known height (cm):", 0, 0, 1000, 2);

    // Measure the height multiple times and take the average
    float measuredSum = 0;
    int measurementCount = 10;

    for (int i = 0; i < measurementCount; ++i) {
        // Wait for the next measurement
        QEventLoop loop;
        QTimer::singleShot(100, &loop, &QEventLoop::quit);
        loop.exec();

        // Assuming the last measured height is stored in a member variable
        measuredSum += ui->heightLabel->text().toFloat();
    }

    float averageMeasuredHeight = measuredSum / measurementCount;

    // Calculate calibration factor and offset
    calibrationFactor = knownHeight / averageMeasuredHeight;
    calibrationOffset = 0; // You might want to add an offset if needed

    QMessageBox::information(this, "Calibration Complete",
                             QString("Calibration factor: %1\nCalibration offset: %2")
                                 .arg(calibrationFactor).arg(calibrationOffset));
}

float MainWindow::getCalibratedHeight(float rawHeight) {
    return rawHeight * calibrationFactor + calibrationOffset;
}

void MainWindow::on_button0_clicked() {
    if (!autoMode) {
        updateServo("0\n");
        ui->verticalSlider->setValue(0);
    }
}

void MainWindow::on_button45_clicked() {
    if (!autoMode) {
        updateServo("45\n");
        ui->verticalSlider->setValue(45);
    }
}

void MainWindow::on_button90_clicked() {
    if (!autoMode) {
        updateServo("90\n");
        ui->verticalSlider->setValue(90);
    }
}

void MainWindow::on_button135_clicked() {
    if (!autoMode) {
        updateServo("135\n");
        ui->verticalSlider->setValue(135);
    }
}

void MainWindow::on_button180_clicked() {
    if (!autoMode) {
        updateServo("180\n");
        ui->verticalSlider->setValue(180);
    }
}

void MainWindow::on_verticalSlider_valueChanged(int value) {
    if (!autoMode && !laserActive) {
        updateServo(QString::number(value) + "\n");
    }
}

void MainWindow::on_button_auto_clicked() {
    autoMode = !autoMode;

    if (autoMode) {
        autoTimer->start(50);
        ui->button_auto->setText("Stop Auto");
        setSliderEnabled(false);
        arduino->write("AUTO\n");
    } else {
        autoTimer->stop();
        ui->button_auto->setText("Start Auto");
        setSliderEnabled(true);
        arduino->write("MANUAL\n");
    }
}

MainWindow::~MainWindow() {
    if (arduino->isOpen()) {
        arduino->close();
    }
    delete ui;
}
