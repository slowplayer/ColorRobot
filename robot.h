#ifndef ROBOT_H
#define ROBOT_H

#include <QGraphicsItem>

class QGraphicsSceneMouseEvent;
class QParallelAnimationGroup;

class RobotPart:public QGraphicsObject
{
public:
    RobotPart(QGraphicsItem *parent=0);
protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *e);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *e);
    void dropEvent(QGraphicsSceneDragDropEvent *e);

    QColor color;
    bool dragOver;
};
class RobotHead:public RobotPart //头部
{
public:
    RobotHead(QGraphicsItem *parent=0);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
protected:
    void dragEnterEvent(QGraphicsSceneDragDropEvent *e);
    void dropEvent(QGraphicsSceneDragDropEvent *e);
private:
    QPixmap pixmap;
};
class RobotTorso:public RobotPart //躯干
{
public:
    RobotTorso(QGraphicsItem *parent=0);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
class RobotLimb:public RobotPart //四肢
{
public:
    RobotLimb(QGraphicsItem *parent=0);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

class Robot:public RobotPart //四肢
{
public:
    Robot(QGraphicsItem *parent=0);
    QRectF boundingRect()const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // ROBOT_H
