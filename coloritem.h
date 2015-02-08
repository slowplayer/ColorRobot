#ifndef COLORITEM_H
#define COLORITEM_H
#include <QGraphicsItem>
class ColorItem:public QGraphicsItem
{
public:
    ColorItem();

    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *e);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *e);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e);
private:
    QColor color;

};

#endif // COLORITEM_H
