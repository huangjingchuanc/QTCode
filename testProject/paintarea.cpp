#include "paintarea.h"
#include<QPainter>
PaintArea::PaintArea(QWidget *parent):QFrame(parent)
{

}

PaintArea::~PaintArea()
{

}

void PaintArea::paintEvent(QPaintEvent *)
{
    QPainter paint(this);
    paint.setPen(pen);
    paint.setBrush(brush);

    QPoint pos[4]={QPoint(100,100),QPoint(200,300),QPoint(100,300),QPoint(300,200)};
    switch(shape)
    {
    case LINE:
        paint.drawLine(50,100,300,300);
        break;
    case RECTANGLE:
        paint.drawRect(pos[0].x(),pos[0].y(),200,200);
        break;
    case ROUNDRECT:
        break;
    case EILLIPSE:
        break;
    case POLYGON:
        break;
    case POLYLINE:
        break;
    case POINTS:
        break;
    case ARC:
        break;
    case PATH:
        break;
    case TEXT:
        break;
    case PIXMAP:
        break;
    default:
        break;
    }
}

void PaintArea::setPenStyle(QPen &pen)
{
    this->pen=pen;
    this->update();
}

void PaintArea::setBrushStyle(QBrush &brush)
{
    this->brush=brush;
    this->update();
}

void PaintArea::setShapeStyle(PaintArea::Shape shape)
{
    this->shape=shape;
    this->update();
}

QPen &PaintArea::getPen()
{
    return pen;
}
