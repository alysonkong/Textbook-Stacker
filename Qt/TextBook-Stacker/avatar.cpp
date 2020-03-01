
#include "avatar.h"
#include <QGraphicsScene>


/**
 * @brief avatar::go in the direction listed in the paramter
 * @param d the direction
 */
void avatar::go(Direction d)
{
    vx=0;
    turn(d); // turn to direction d
    switch(d) {
    //include if statement to stop animation
    case Left:
        vx = -spd;
        break;
    case Right:
        vx = spd;
        break;
    }
    play();
}

/**
 * @brief avatar::turns the avatar to the parameter direction
 * @param d specified direction
 */
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

/**
 * @brief avatar::advance the avatar will be set at a specific point in QGraphicsView
 * @param phase
 */
void avatar::advance(int phase) {
    QRectF mcMoveBoundary(0,0, 436, 750);
    if(phase) { //phase =1 moves the avatar
        QPointF nextPos = mapToScene(QPointF(vx,0));
        if(mcMoveBoundary.contains(nextPos)) {
            setPos(nextPos);
        }
       // setPos(mapToScene(QPointF(vx, 0))); //sets the avatar at this specified point
    }
    if(!scene()->collidingItems(this).isEmpty()){
        score++;
    }
    Sprite::advance(phase);
}

size_t avatar::getscore(){
    return score;
}


void avatar::updatescore(int addval){
    score += addval;
}

//QVariant avatar::itemChange(GraphicsItemChange change, const QVariant &value){
//    if (change == ItemPositionChange && scene()) {
//            // value is the new position.
//            QPointF newPos= value.toPointF();
//            QRectF rect = scene()->sceneRect();
//            if (!rect.contains(newPos)) {
//                // Keep the item inside the scene rect.
//                newPos.setX(qMin(rect.right(), qMax(newPos.x(), rect.left())));
//                newPos.setY(qMin(rect.bottom(), qMax(newPos.y(), rect.top())));
//                return newPos;
//            }
//        }
//        return QGraphicsItem::itemChange(change, value);
//}

