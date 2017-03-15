#pragma once

#include <QGraphicsScene>
#include <QVector>

class QTimer;
class Antenna;
class Plane;

class TwoDimentionalScene : public QGraphicsScene
{
    Q_OBJECT
public:
    TwoDimentionalScene(QObject* parent = nullptr);
    virtual ~TwoDimentionalScene();

public slots:
    void startPlaying();
    void updateCirclePos();

signals:
    void zoomChanged(double);
    void antenaPosChanged(QPointF pos, unsigned int id);
    void planePosChanged(QPointF pos);

protected:
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent * event) override;
    virtual void wheelEvent(QGraphicsSceneWheelEvent *event) override;

private:
    bool all_in(qreal radius);

private:
    QVector<Antenna*> m_antenasVector;
    QGraphicsEllipseItem *m_circle;
    Plane *m_plane;
    QTimer *m_timer;
    qreal m_step;
};
