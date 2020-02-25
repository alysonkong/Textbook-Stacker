#include "sprite.h"
#include <QPainter>


QRectF Sprite::boundingRect() const {
    return QRectF(0,0,_scale*w,_scale*h);
}

void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QRectF sr(x_off + w*cx,y_off + h*cy,w,h);
    painter->drawPixmap(boundingRect(),*ss,sr);
}

void Sprite::advance(int phase) {
    if(phase && _animating) { // only update when phase is 1
        ++ticks;
        ticks %= ticks_per_frame;
        if(!ticks) {
            ++cx;
            cx %= nx;
            update(boundingRect());
        }
    }
}


