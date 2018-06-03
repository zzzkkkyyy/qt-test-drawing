#ifndef PAINTAREA_H
#define PAINTAREA_H

#include <QGraphicsView>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QString>
#include <QPen>
#include <QPointF>
#include <vector>
#include <QDebug>
#include <QGraphicsScene>
#include <QGraphicsItem>
#include <QRectF>
#include <QDebug>
#include <QWidget>

using namespace std;

typedef struct Line
{
    QPoint start;
    QPoint end;
}Line;

class MyItem : public QGraphicsItem
{
public:
    MyItem(QPointF pt1, QPointF pt2) : pt_start(pt1), pt_end(pt2)
    {
        painter = new QPainter;
        QPen *pen = new QPen;
        pen->setColor(Qt::red);
        pen->setWidth(10);
        painter->setPen(*pen);
        //qDebug() << pt_start.x() << pt_start.y() << ", " << pt_end.x() << pt_end.y();
    }
    MyItem(QPointF pt1, QPointF pt2, QPainter *pter) : pt_start(pt1), pt_end(pt2)
    {
        painter = new QPainter;
        QPen *pen = new QPen;
        pen->setColor(Qt::red);
        pen->setWidth(10);
        painter->setPen(*pen);
        //qDebug() << pt_start.x() << pt_start.y() << ", " << pt_end.x() << pt_end.y();
    }
    virtual QRectF boundingRect() const
    {
        return QRectF(0, 0, 360, 600);
    }
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget * widget = 0)
    {
        painter->drawLine(pt_start, pt_end);
    }

private:
    QPointF pt_start, pt_end;
    QPainter *painter;
};

class PaintArea : public QGraphicsScene
{
    Q_OBJECT

public:
    PaintArea(QWidget *parent);
    ~PaintArea();

protected:
    virtual void paintEvent(QPaintEvent *p);
    virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    virtual void mousePressEvent(QGraphicsSceneMouseEvent *e);
    virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);

private:
    QPointF start, end;
    bool isPressed;
    vector<Line> line_list;
};

#endif // PAINTAREA_H
