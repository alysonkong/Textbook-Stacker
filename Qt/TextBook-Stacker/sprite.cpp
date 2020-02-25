#include "sprite.h"
#include <QPainter>



/**
 * @brief Sprite::boundingRect creates the target rectangle in which the sprite object will be drawn into
 * @return QRectF of the rectangle size
 */
QRectF Sprite::boundingRect() const {
    return QRectF(0,0,_scale*w,_scale*h);
}


/**
 * @brief Sprite::paint paints the sprite object
 * @param painter
 */
void Sprite::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) {
    QRectF sr(x_off + w*cx,y_off + h*cy,w,h);
    painter->drawPixmap(boundingRect(),*ss,sr); //bounding rect is
}


/**
 * @brief Sprite::advance advances the animation to the next
 * @param phase
 */
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


