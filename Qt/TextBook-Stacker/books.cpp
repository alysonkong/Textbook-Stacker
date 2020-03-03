#include "books.h"
#include <QPainter>

books::books(int book_type) : booktype(book_type)
{
    if(book_type ==0){
        book = new QPixmap(":/spritesheets/redbook.png");
    }
    else if(book_type ==1){
        book = new QPixmap(":/spritesheets/orangebook.png");

    }
    else if(book_type == 2){
        book = new QPixmap(":/spritesheets/yellowbook.png");
    }
    else if(book_type == 3){
        book = new QPixmap(":/spritesheets/greenbook.png");
    }
    else if(book_type == 4){
        book =  new QPixmap(":/spritesheets/bluebook.png");
    }
    else if(book_type == 5){
        book = new QPixmap(":/spritesheets/purplebook.png");
    }

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
    //painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : scene()->removeItem(this));

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
    QRectF mcMoveBoundary(0,0, 400, 717.8);
    if(phase) {
        QPointF down(0,7);
        down*=speed;
        QPointF nextPos = mapToScene(down);
        if(mcMoveBoundary.contains(nextPos)) {
            setPos(nextPos);
        }

        if(!scene()->collidingItems(this).isEmpty()){
            scene()->removeItem(this);
            delete this;
            getbooktype();
        }
        else if(!mcMoveBoundary.contains(nextPos)){
            scene()->removeItem(this);
            delete this;
        }

//        QPointF down(0,7);
//        down*=speed;
//        setPos(mapToScene(down)); // set my next position
        //speed+=(QRandomGenerator::global()->bounded(0.4)-0.2);
    }

}

void books::getbooktype(){
    emit emittype(booktype);
   // emit emitpts(points);

}

//bool books::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
//    emit type_pts(booktype, points);
//}
