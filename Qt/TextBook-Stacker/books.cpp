#include "books.h"
#include <QPainter>

books::books(int book_type) : booktype(book_type), bookwidth(500), bookheight(161)
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

    stacking_sound = new QMediaPlayer();
    stacking_sound->setMedia(QUrl("qrc:/music/stacking sound effect.mp3"));

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
//take in qrectf of
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
    QRectF mcMoveBoundary(0,0, 500, 650);
    if(phase) {
        QPointF down(0,7);
        down*=speed;
        QPointF nextPos = mapToScene(down);
       // QRectF itemSceneBoundingRect = this->mapRectToScene(this->boundingRect());
        //this->prepareGeometryChange();
        //if(!scene()->intersects(itemSceneBoundingRect)){
       // if(!mcMoveBoundary.contains(nextPos)){
            //this->deleteLater();

            //delete this;
         //   scene()->removeItem(this);
            //delete(this);
            //delete book;
            //book = nullptr;
       // }
//        if(!scene()->collidingItems(this).isEmpty()){
//            emit emittype(booktype);

//            this->deleteLater();
//            scene()->removeItem(this);
//            delete book;
//            book = nullptr;
            //delete this;
           //

       //}


               // else { //if(!mcMoveBoundary.contains(nextPos))
                 // setPos(nextPos);
                    //delete book;
                   // book = nullptr;

             //   }

//        if(!mcMoveBoundary.contains(nextPos)){ //|| !scene()->collidingItems(this).isEmpty()
//           // this->prepareGeometryChange();
//            this->deleteLater();
//           // scene()->removeItem(this); //having only this uncommented leads to crash
//            //delete book;
//           // book = nullptr;

//            //delete this;
//            //scene()->update();
//        }

//        if(mcMoveBoundary.contains(nextPos)){ //&& scene()->collidingItems(this).isEmpty()
//            if(!scene()->collidingItems(this).isEmpty()){
//                emit emittype(this->gettype());

//                this->deleteLater();
//                //scene()->removeItem(this);
//               // delete this;
//            }
//            else{
//                setPos(nextPos);
//            }
//        }


//        if(mcMoveBoundary.contains(nextPos) && scene()->collidingItems(this).isEmpty()) {
//            setPos(nextPos);
//        }
//        else if(!scene()->collidingItems(this).isEmpty()){
//            emit emittype(this->gettype());
//            this->deleteLater();
//            //scene()->removeItem(this);
//           // delete book;
//           // book = nullptr;
//           // delete this;
//           //scene()->update();
//        }
//        else{

//            scene()->removeItem(this);

//            delete this;

//        }

        if(mcMoveBoundary.contains(nextPos)) {
                    setPos(nextPos);
                }

                if(!scene()->collidingItems(this).isEmpty()){

                    if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                        stacking_sound->setPosition(0);
                    }
                    else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                        stacking_sound->play();
                    }

                    emit emittype(this->gettype());
                    //QObject::connect
                    scene()->removeItem(this);
//                    delete book;
//                    book = nullptr;
                     delete this;
                   //

                }
                else if(!mcMoveBoundary.contains(nextPos)){
                    scene()->removeItem(this); //should i delete the qgraphicsobject or just the pixmap???
//                    delete book;
//                    book = nullptr;
                     delete this;
                }

    }

}

/**
 * @brief books::gettype accessor function
 * @return book type index
 */
int books::gettype(){
    return booktype;
}


QPixmap* books::getbookpic() const{
    return book;
}

books::~books(){
    this->prepareGeometryChange();
    delete book;
    book = nullptr;
}

//bool books::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const{
//    emit type_pts(booktype, points);
//}
