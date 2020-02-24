#include "books.h"
#include <QPainter>

books::books()
{
    book = new QPixmap(":/spritesheets/yellowbook.png"); //use resource file to create a book visual

}

/**
 * @brief books::paint overrides the paint function to draw the book
 * @param painter draws the book
 * @param option provides option to stylize qgraphicsitem
 * @param widget is what the
 */
void books::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    QRectF source(0,0,500,161); //image is 500x161
    painter->drawPixmap(boundingRect(),*book, source); //boundingrect is the target in which to draw the book into

}

/**
 * @brief books::boundingRect bounds the size of the rect in which the book is drawn in, scaling the size by 0.2
 * @return a QRectF with custom parameters
 */
QRectF books::boundingRect() const{
    return QRectF(0,0,500*0.2,161*0.2);
}

/**
 * @brief books::advance the book down the screen
 * @param phase
 */
void books::advance(int phase) {
    if(phase) {
        QPointF down(0,7);
        down*=speed;
        setPos(mapToScene(down)); // set my next position
        //speed+=(QRandomGenerator::global()->bounded(0.4)-0.2);
    }
}
