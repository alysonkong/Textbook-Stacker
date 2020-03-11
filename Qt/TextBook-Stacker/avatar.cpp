
#include "avatar.h"
#include <QGraphicsScene>
#include <QPixmap>
#include <QPainter>


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

//QRectF avatar::boundingRect() const{

//}

int avatar::getlife(){
    return life;
}

void avatar::deletelife(){
    --life;
}

/**
 * @brief avatar::advance the avatar will be set at a specific point in QGraphicsView
 * @param phase
 */
void avatar::advance(int phase) {
    QRectF mcMoveBoundary;
    if(bookstack.size() ==0){
        mcMoveBoundary= QRectF(-25,0, 454, 750);
    }
    else{
        mcMoveBoundary = QRectF(0,0, 400, 750);
    }
    if(phase) { //phase =1 moves the avatar
        QPointF nextPos = mapToScene(QPointF(vx,0));
        if(mcMoveBoundary.contains(nextPos)) {
            setPos(nextPos);
        }
       // setPos(mapToScene(QPointF(vx, 0))); //sets the avatar at this specified point
    }
    Sprite::advance(phase);
}

size_t avatar::getscore(){
    return score;
}

QString avatar::getname(){
    return name;
}

void avatar::updatepscore(){
    ++score;
}

QRectF avatar::boundingRect() const{
    //int xdimension = 100;
//    if(bookstack.size() == 0){
//        xdimension = Sprite::scale()*Sprite::getw();
//    }
    //else{
    //}
    //int ydimension = Sprite::scale()*Sprite::geth()+(bookstack.size()*(161*0.2));

    return QRectF(0,0,100, 489.8);
   // return QRectF(0,200,100, 189.8);
}

QPainterPath avatar::shape() const{
    QPainterPath path;
    QPolygonF myPolygon;
    int n = bookstack.size();
    if(bookstack.size()== 0){
        myPolygon << QPointF(18,293.8) << QPointF(82, 293.8) << QPointF(50,303.8) <<QPointF(18,293.8);
    }
    else{
        myPolygon << QPointF(0,(389.8-96-n*32.2)) << QPointF(100, (389.8-96-n*32.2)) << QPointF(50,(389.8-96-n*32.2+10)) <<QPointF(0,(389.8-96-n*32.2));
    }
    path.addPolygon(myPolygon);
    return path;
}

void avatar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF sr(Sprite::getx_off() + Sprite::getw()*Sprite::getcx(),Sprite::gety_off() + Sprite::geth()*Sprite::getcy(),32,48);
    //QRectF sr(ax_off+aw*acx, ay_off+ah*acy, 32, 48);
    QPolygonF mPolygon;
    mPolygon << QPointF(18,293.8) << QPointF(82, 293.8) << QPointF(50,303.8) <<QPointF(18,293.8);

   painter->setBrush(Qt::cyan);
    painter->drawRect(QRectF(0,0,100, 489.8));

    painter->drawPixmap(QRectF((0+18),293.8,(2*32),(2*48)),*Sprite::getss(), sr);


    QPen myPen(Qt::red, 2, Qt::SolidLine);
    painter->setPen(myPen);
    painter->drawPolygon(mPolygon);




    QRectF source(0,0,500,161);
    int y = 1;
    for(auto i: bookstack){
        painter->drawPixmap(QRectF(0,(293.8-32.2*y), 500*0.2, 161*0.2), *i->getbookpic(), QRectF(0,0,500,161));
        ++y;
    }


}

void avatar::addbooks(int index){
    books* temp = new books(index);
    bookstack.push_back(temp);
}


void avatar::deletestack(){
    bookstack.clear();
    this->update();
//    for(auto i: bookstack){
//        delete i;
//        i = nullptr;
//    }
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

//create wrapper class for avatar & bookstack
