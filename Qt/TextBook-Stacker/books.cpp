#include "books.h"
#include <QPainter>

books::books()
{
    book = new QPixmap(":/spritesheets/yellowbook.png");

}

void books::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF source(0,0,500,161);
    painter->drawPixmap(boundingRect(),*book, source);

}

QRectF books::boundingRect() const{
    return QRectF(0,0,500*0.5,161*0.5);
}

void books::advance(int phase) {
    if(phase) {
        QPointF down(0,7);
        down*=speed;
        setPos(mapToScene(down)); // set my next position
        //speed+=(QRandomGenerator::global()->bounded(0.4)-0.2);
    }
}

//++ticks;
//ticks %= ticks_per_frame;
//if(!ticks) {
//    ++cx;
//    cx %= nx;
//    update(boundingRect());
//}
