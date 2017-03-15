#include "plane.h"

Plane::Plane(float x, float y, float z)
    : _x(x)
    , _y(y)
    , _z(z)
    , m_radius(3)
{
    setFlag(ItemIsMovable);
    setFlag(ItemIsSelectable);

    m_bRect = QRectF(_x - m_radius/2, _y + m_radius/2, m_radius, m_radius);
}

QRectF Plane::boundingRect() const
{
    return m_bRect;
}

void Plane::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::blue, 3));
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(m_bRect);
}

void Plane::set2DPos(QPointF pos)
{
    _x = pos.x();
    _y = pos.y();
}

QPointF Plane::get2DPos() const
{
    return QPointF(_x, _y);
}
