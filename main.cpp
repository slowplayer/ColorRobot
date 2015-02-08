#include "robot.h"
#include "coloritem.h"
#include <QtWidgets>
#include <math.h>

class GraphicsView:public QGraphicsView
{
public:
    GraphicsView(QGraphicsScene *scene):QGraphicsView(scene)
    {

    }
protected:
    virtual void resizeEvent(QResizeEvent *)
    {

    }
};
int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    qsrand(QTime(0,0,0).secsTo(QTime::currentTime()));
    QGraphicsScene scene(-200,-200,400,400);
    for(int i=0;i<10;i++)
    {
        ColorItem *item=new ColorItem;
        item->setPos(::sin((i*6.28)/10.0)*150,
                     ::cos((i*6.28)/10.0)*150);
        scene.addItem(item);
    }
    Robot *robot=new Robot;
    robot->setTransform(QTransform::fromScale(1.2,1.2),true);
    robot->setPos(0,-20);
    scene.addItem(robot);

    GraphicsView view(&scene);
    view.setRenderHint(QPainter::Antialiasing);//反走样
    view.setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
    view.setBackgroundBrush(QColor(230,200,167));
    view.setWindowTitle("Robot");
    view.show();
    return app.exec();
}
