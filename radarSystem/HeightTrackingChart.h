#ifndef HEIGHTTRACKINGCHART_H
#define HEIGHTTRACKINGCHART_H

#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>

QT_CHARTS_USE_NAMESPACE

    class HeightTrackingChart : public QChartView {
    Q_OBJECT

public:
    HeightTrackingChart(QWidget *parent = nullptr);

public slots:
    void addHeightDataPoint(float height);

private:
    QLineSeries *series;
    qint64 startTime;
};

#endif // HEIGHTTRACKINGCHART_H
