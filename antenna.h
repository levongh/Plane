#pragma once

#include <QGraphicsItem>
#include <QGraphicsEllipseItem>
#include <QWidget>
#include <QPainter>

class QGraphicsSceneMouseEvent;

class Antenna : public QGraphicsItem
{
public:
    Antenna(float x = 0.0, float y = 0.0, float z = 0.0, unsigned id = 0);

public:
    void set2DPos(QPointF pos);

    QPointF get2DPos() const;

    inline unsigned get_id()const
    {
        return m_id;
    }

protected:

     QRectF boundingRect()const override;
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
     void mouseMoveEvent(QGraphicsSceneMouseEvent *event)override;

private:
    float _x;
    float _y;
    float _z;
    const unsigned m_radius;
    unsigned int m_id;
    QRectF m_bRect;
};
