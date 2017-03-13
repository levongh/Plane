#pragma once

#include <QWidget>
#include <QPainter>
#include <QGraphicsItem>
#include <QGraphicsEllipseItem>


class Plane : public QGraphicsItem
{
public:
    Plane(float x = 0.0, float y = 0.0, float z = 0.0);

public:
    void set2DPos(QPointF pos);
    QPointF get2DPos() const;

public:
    inline const unsigned getRadius() const
    {
        return m_radius;
    }

protected:
    virtual QRectF boundingRect()const override;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    float _x;
    float _y;
    float _z;
    const unsigned m_radius;
    QRectF m_bRect;
};
