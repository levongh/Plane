#include <math.h>
#include <QTimer>
#include <QGraphicsSceneMouseEvent>
#include <QTransform>

#include "graphicsScene.h"
#include "antenna.h"
#include "plane.h"


graphicsScene::graphicsScene(QObject* parent)
    : QGraphicsScene(parent)
    , m_circle(nullptr)
    , m_plane(nullptr)
    , m_timer(nullptr)
    , m_step(20.0)
{
    setBackgroundBrush(Qt::Dense7Pattern);
    m_timer = new QTimer(this);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(updateCirclePos()));

    m_antenasVector.resize(5);
    for (int i = 0; i < 5; ++i) {
        m_antenasVector[i] = new Antenna(i * 3, i * 3, i * 3, i);
        addItem(m_antenasVector[i]);
        emit antenaPosChanged(QPointF(i * 3, i * 3), i);
    }
    m_plane = new Plane(100, 100, 10);
    addItem(m_plane);
}

void graphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);
}

void graphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mouseReleaseEvent(event);
}

void graphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (Antenna* obj = dynamic_cast<Antenna*>(itemAt(event->scenePos(), QTransform()))) {
        obj->set2DPos(event->scenePos());
        emit antenaPosChanged(event->scenePos(), obj->get_id());
    } else if (Plane* obj = dynamic_cast<Plane*>(itemAt(event->scenePos(), QTransform()))) {
        obj->set2DPos(event->scenePos());
        emit planePosChanged(event->scenePos());
    }

    QGraphicsScene::mouseMoveEvent(event);
}

void graphicsScene::wheelEvent(QGraphicsSceneWheelEvent *event)
{
    if (Qt::ControlModifier == event->modifiers() && event->orientation() == Qt::Vertical) {
        emit zoomChanged(event->delta());
    }
    update();
    QGraphicsScene::wheelEvent(event);
}

#include <QDebug>

void graphicsScene::startPlaying()
{
    m_timer->start(500);
}

void graphicsScene::updateCirclePos()
{
    qreal current_radius = m_step;
    if (m_circle != nullptr) {
        delete m_circle;
        m_circle = nullptr;
    }
    m_circle = new QGraphicsEllipseItem(m_plane->get2DPos().x() + m_plane->getRadius()/2 - current_radius/2,
                                                        m_plane->get2DPos().y() - m_plane->getRadius()/2 - current_radius/2,
                                                        current_radius,
                                                        current_radius);
    addItem(m_circle);
    if (all_in(current_radius / 2)) {
        m_timer->stop();
        m_step = 20.0;
    } else {
        m_step += 20.0;
    }
}

bool graphicsScene::all_in(qreal radius)
{
    for (const auto it : m_antenasVector) {
        qreal dx = std::abs(it->get2DPos().x() - m_plane->get2DPos().x());
        qreal dy = std::abs(it->get2DPos().y() - m_plane->get2DPos().y());
        qreal dist = sqrt((dx * dx) + (dy *dy));
        if (dist >= radius) {
            return false;
        }
    }
    return true;
}

graphicsScene::~graphicsScene()
{

}
