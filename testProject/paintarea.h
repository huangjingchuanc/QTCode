#ifndef PAINTAREA_H
#define PAINTAREA_H

#include<QFrame>
#include<QPen>
class PaintArea : public QFrame
{
    Q_OBJECT
public:
    enum Shape{LINE,RECTANGLE,ROUNDRECT,EILLIPSE,POLYGON,
              POLYLINE,POINTS,ARC,PATH,TEXT,PIXMAP};
    explicit PaintArea(QWidget* parent=nullptr);
    ~PaintArea();
    void paintEvent(QPaintEvent *);
    void setPenStyle(QPen&pen);
    void setBrushStyle(QBrush&brush);
    void setShapeStyle(Shape shape);
    QPen& getPen();
private:
    QPen pen;
    QBrush brush;
    Shape shape;
};

#endif // PAINTAREA_H
