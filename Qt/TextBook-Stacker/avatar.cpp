
#include "avatar.h"
#include <QGraphicsScene>



void avatar::go(Direction d) // go in this direction
{
    //stop(); // set both velocities to 0
    vx=vy=0;
    turn(d); // turn to direction d
    switch(d) {
    case Left:
        vx = -spd;
        break;
    case Right:
        vx = spd;
        break;
    }
    play();
}
void avatar::turn(Direction d) // turn to a given direction
{
    facing = d;
    switch(d) {
    case Left:
        setSequence(1);
        break;
    case Right:
        setSequence(2);
        break;
    }
}


void avatar::advance(int phase) {
    if(phase) {
        setPos(mapToScene(QPointF(vx,vy)));
    }
    Sprite::advance(phase);
}

QVariant avatar::itemChange(GraphicsItemChange change, const QVariant &value){
//    if(change==ItemPositionHasChanged){
//        QPointF newPos = value.toPointF();
//        newPos.setX(0);
//        newPos.setY(604);
//        return newPos;

//    }
//    return QGraphicsItem::itemChange(change, value);
    if (change == ItemPositionChange && scene()) {
            // value is the new position.
            QPointF newPos = value.toPointF();
            QRectF rect = scene()->sceneRect();
            if (!rect.contains(newPos)) {
                // Keep the item inside the scene rect.
                newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
                newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
                return newPos;
            }
        }
        return QGraphicsItem::itemChange(change, value);



}

