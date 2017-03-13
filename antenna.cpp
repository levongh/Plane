#include "antenna.h"

#include <QGraphicsSceneMouseEvent>

Antenna::Antenna(float x, float y, float z, unsigned int id)
    : _x(x)
    , _y(y)
    , _z(z)
    , m_radius(5)
    , m_id(id)
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);

    m_bRect = QRect(_x - m_radius/2, _y + m_radius/2, m_radius, m_radius);
}

void Antenna::set2DPos(QPointF pos)
{
    _x = pos.x();
    _y = pos.y();
    setPos(pos);
}

QPointF Antenna::get2DPos()const
{
    return scenePos();
  //  return QPointF(_x, _y);
}
QRectF Antenna::boundingRect() const
{
    return m_bRect;
}

void Antenna::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::red, 3));
    painter->setBrush(Qt::red);
    painter->drawEllipse(m_bRect);
    painter->drawText(m_bRect, Qt::AlignCenter, QString(m_id));
}

void Antenna::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsItem::mouseMoveEvent(event);
}
