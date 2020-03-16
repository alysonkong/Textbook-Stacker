#include "books.h"
#include <QPainter>


/**
 * @brief books::books creates a book graphicsobject based on the index of the book
 * @param book_type
 */
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
    else if(book_type >5 | book_type <=9){
        book = new QPixmap(":/spritesheets/letter_F.png");
    }

}

/**
 * @brief books::paint overrides the paint function to draw the book
 * @param painter draws the book
 * @param option provides option to stylize qgraphicsitem
 * @param widget is what the
 */
void books::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
    if(booktype<=5){
    QRectF source(0,0,500,161); //image is 500x161
    painter->drawPixmap(QRectF(0,0,bookwidth*0.2,bookheight*0.2), *book, source); //boundingrect is the target in which to draw the book into
    }
    else{
        QRectF source(0,0,512,512);
        painter->drawPixmap(QRectF(0,0,512*0.15,512*0.15), *book, source);
    }

}

/**
 * @brief books::boundingRect bounds the size of the rect in which the book is drawn in, scaling the size by 0.2
 * @return a QRectF with custom parameters
 */
QRectF books::boundingRect() const{
    if(booktype<=5){
        return QRectF(0,0,bookwidth*0.2,bookheight*0.2);
    }
    else{
        return QRectF(0,0,512*0.15,512*0.15);
    }
}

/**
 * @brief books::advance the book down the screen
 * @param phase
 */
void books::advance(int phase) {
    QRectF mcMoveBoundary(0,0, 500, 700);
    if(phase) {
        QPointF down(0,7);
        down*=speed;
        QPointF nextPos = mapToScene(down);

        if(mcMoveBoundary.contains(nextPos)) { //if book is contained within the window bounds, set position
             setPos(nextPos);
        }

       if(!scene()->collidingItems(this).isEmpty()){ //if there is a collision detected with the book, emit the book index and remove from scene
             emit emittype(booktype);
             scene()->removeItem(this);
              delete this;
        }
        else if(!mcMoveBoundary.contains(nextPos)){ //if the book isn't contained within the window bounds, remove the book from scene
              scene()->removeItem(this);
               delete this;
        }

    }

}


/**
 * @brief books::getbookpic returns the book qpixmap which will be used in avatar.cpp to draw the bookstack
 * @return
 */
QPixmap* books::getbookpic() const{
    return book;
}

/**
 * @brief books::~books custom destructor used to delete the qpixmap of a book
 */
books::~books(){
    this->prepareGeometryChange();
    delete book;
    book = nullptr;
}
