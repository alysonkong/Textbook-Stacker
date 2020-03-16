#include "sprite.h"
#include <QPainter>


/**
 * @brief Sprite::paint paints the sprite object into the designated area
 * @param painter
 */
void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QRectF sr(x_off + w*cx,y_off + h*cy,w,h);
    painter->drawPixmap(QRectF(0,0,_scale*w,_scale*h),*ss,sr);
}

/**
 * @brief Sprite::advance moves the sprite object and animates it w/ different frames
 * @param phase
 */
void Sprite::advance(int phase) {
    if(phase && _animating) { // only update when phase is 1
        ++ticks;
        ticks %= ticks_per_frame;
        if(!ticks) {
            ++cx;
            cx %= nx;

        }
    }
}




