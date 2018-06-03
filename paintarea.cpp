#include "paintarea.h"

PaintArea::PaintArea(QWidget *parent) : QGraphicsScene(parent), isPressed(false)
{

}

PaintArea::~PaintArea() {}

void PaintArea::paintEvent(QPaintEvent *p)
{
    qDebug() << "paint event";
    QPainter painter;
    QPen pen;
    pen.setColor(Qt::darkBlue);
    pen.setWidth(5);
    painter.setPen(pen);
    //qDebug() << line_list.size();
    for (vector<Line>::iterator it = line_list.begin(); it != line_list.end(); it++)
    {
        MyItem myitem(it->start, it->end);
        this->addItem(&myitem);
        myitem.setPos(0, 0);
    }
    //line_list.clear();
    //this->setScene(scene);
    //this->show();
}

void PaintArea::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    //if (isPressed && e->scenePos().x() >= 0 && e->scenePos().y() >= 0)
    if (isPressed)
    {
        end = event->scenePos();
        /*
        QPoint s, e;
        s.setX(int(start.x()));
        s.setY(int(start.y()));
        e.setX(int(end.x()));
        e.setY(int(end.y()));
        Line l = {s, e};
        line_list.push_back(l);*/

        qDebug() << "paint event" << start.x() << start.y() << end.x() << end.y();
        MyItem *myitem = new MyItem(start, end);
        myitem->setPos(0, 0);
        this->addItem(myitem);

        this->update();
        start = end;
        QGraphicsScene::mouseMoveEvent(event);
    }
}

void PaintArea::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    isPressed = true;
    start = end = e->scenePos();
    qDebug() << "pressed";
    qDebug() << start.x() << start.y();
    QGraphicsScene::mousePressEvent(e);

}

void PaintArea::mouseReleaseEvent(QGraphicsSceneMouseEvent *e)
{
    isPressed = false;
    qDebug() << "released";
    QGraphicsScene::mouseReleaseEvent(e);
}
