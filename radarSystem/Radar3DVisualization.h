#ifndef RADAR3DVISUALIZATION_H
#define RADAR3DVISUALIZATION_H

#include <QtWidgets>
#include <QtDataVisualization/Q3DScatter>
#include <QtDataVisualization/QScatter3DSeries>
#include <QtDataVisualization/QScatterDataProxy>

using namespace QtDataVisualization;

class Radar3DVisualization : public QWidget {
    Q_OBJECT

public:
    Radar3DVisualization(QWidget *parent = nullptr);

public slots:
    void updatePoint(float angle, float distance, float height);

private:
    Q3DScatter *scatter;
    QScatter3DSeries *series;
};

#endif // RADAR3DVISUALIZATION_H
