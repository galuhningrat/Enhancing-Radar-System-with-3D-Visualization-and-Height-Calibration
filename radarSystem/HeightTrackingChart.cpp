#include "HeightTrackingChart.h"
#include <QtCharts/QDateTimeAxis>
#include <QtCharts/QValueAxis>

HeightTrackingChart::HeightTrackingChart(QWidget *parent) : QChartView(parent) {
    series = new QLineSeries();

    QChart *chart = new QChart();
    chart->addSeries(series);

    QDateTimeAxis *axisX = new QDateTimeAxis;
    axisX->setTitleText("Time");
    chart->addAxis(axisX, Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis;
    axisY->setTitleText("Height (cm)");
    chart->addAxis(axisY, Qt::AlignLeft);
    series->attachAxis(axisY);

    setChart(chart);
    setRenderHint(QPainter::Antialiasing);

    startTime = QDateTime::currentMSecsSinceEpoch();
}

void HeightTrackingChart::addHeightDataPoint(float height) {
    qint64 now = QDateTime::currentMSecsSinceEpoch();
    qreal timeInSeconds = (now - startTime) / 1000.0;
    series->append(timeInSeconds, height);

    if (series->count() > 100) {
        series->remove(0);
    }

    QValueAxis *axisX = static_cast<QValueAxis*>(chart()->axes(Qt::Horizontal).at(0));
    axisX->setRange(series->at(0).x(), timeInSeconds);

    QValueAxis *axisY = static_cast<QValueAxis*>(chart()->axes(Qt::Vertical).at(0));
    axisY->setRange(0, qMax(100.0, series->at(series->count() - 1).y() * 1.1));

    chart()->update();
}
