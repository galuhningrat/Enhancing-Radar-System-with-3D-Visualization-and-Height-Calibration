#include "Radar3DVisualization.h"

Radar3DVisualization::Radar3DVisualization(QWidget *parent) : QWidget(parent) {
    QVBoxLayout *layout = new QVBoxLayout(this);

    series = new QScatter3DSeries;
    series->setItemLabelFormat(QStringLiteral("@xLabel, @yLabel, @zLabel"));
    series->setMesh(QAbstract3DSeries::MeshSphere);
    series->setItemSize(0.1f);

    scatter = new Q3DScatter();
    scatter->addSeries(series);
    scatter->setAspectRatio(1.0);
    scatter->setHorizontalAspectRatio(1.0);

    QWidget *container = QWidget::createWindowContainer(scatter);
    container->setMinimumSize(400, 400);
    container->setMaximumSize(600, 600);
    container->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    layout->addWidget(container);

    // Set up axes
    scatter->axisX()->setTitle("X");
    scatter->axisY()->setTitle("Y");
    scatter->axisZ()->setTitle("Height");

    scatter->axisX()->setRange(-200, 200);
    scatter->axisY()->setRange(-200, 200);
    scatter->axisZ()->setRange(0, 100);
}

void Radar3DVisualization::updatePoint(float angle, float distance, float height) {
    float x = distance * qCos(qDegreesToRadians(angle));
    float y = distance * qSin(qDegreesToRadians(angle));

    QScatterDataItem item(QVector3D(x, y, height));
    series->dataProxy()->addItem(item);

    // Remove old points if there are too many
    if (series->dataProxy()->itemCount() > 100) {
        series->dataProxy()->removeItems(0, 1);
    }
}
