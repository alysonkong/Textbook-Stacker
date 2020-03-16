
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


/**
 * @brief avatar::advance the avatar will be set at a specific point in QGraphicsView
 * @param phase
 */
void avatar::advance(int phase) {
    QRectF mcMoveBoundary;
    if(bookstack.size() ==0){ //if there are no books stacked on avatar, this is the bounding rect
        mcMoveBoundary= QRectF(-25,0, 454, 750);
    }
    else{ //if there are books stacked on avatar, this is the bounding rect
        mcMoveBoundary = QRectF(-5,0, 416, 750);
    }
    if(phase) { //phase =1 moves the avatar
        QPointF nextPos = mapToScene(QPointF(vx,0));
        if(mcMoveBoundary.contains(nextPos)) { //if the avatar is within bounds set the position of avatar
            setPos(nextPos);
        }

    }
    Sprite::advance(phase);
}

/**
 * @brief avatar::getscore
 * @return return score of avatar
 */
size_t avatar::getscore(){
    return score;
}

/**
 * @brief avatar::getname
 * @return name of player
 */
QString avatar::getname(){
    return name;
}

/**
 * @brief avatar::updatepscore increases the player's score by 1 for each correct textbook
 */
void avatar::updatepscore(){
    ++score;
}

/**
 * @brief avatar::boundingRect the boundingrect of avatar and 10 potential books on top
 * @return a qrect that will serve as the container rectangle
 */
QRectF avatar::boundingRect() const{
    return QRectF(0,0,100, 489.8);

}

/**
 * @brief avatar::shape used in collision detection for the avatar based on whether avatar is by itself or has textbooks
 * @return a path that depends on the # of textbooks there are
 */
QPainterPath avatar::shape() const{
    QPainterPath path;
    QPolygonF myPolygon;
    int n = bookstack.size();
    if(bookstack.size()== 0){ //avatar's collision shape by itself
         myPolygon << QPointF(18,306.8) << QPointF(80, 306.8) << QPointF(50,310.8) <<QPointF(18,306.8);
    }
    else{ //avatar's collision shape w/ n books on top
        myPolygon << QPointF(0,(389.8-96-n*32.2)) << QPointF(100, (389.8-96-n*32.2)) << QPointF(50,(389.8-96-n*32.2+10)) <<QPointF(0,(389.8-96-n*32.2));
    }
    path.addPolygon(myPolygon);
    return path;
}

/**
 * @brief avatar::paint overrides the paint function to draw out avatars and books
 * @param painter paints the spritesheet and the book graphics
 * @param option not used
 * @param widget not used
 */
void avatar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    QRectF sr(Sprite::getx_off() + Sprite::getw()*Sprite::getcx(),Sprite::gety_off() + Sprite::geth()*Sprite::getcy(),32,48);
    painter->drawPixmap(QRectF((0+18),293.8,(2*32),(2*48)),*Sprite::getss(), sr); //draws the avatar
    QRectF source(0,0,500,161); //source's dimension is the book graphics dimension

    int y = 1; //the starting pos for book drawing
    for(auto i: bookstack){ //draw out however many books there are
        painter->drawPixmap(QRectF(0,(308.8-32.2*y), 500*0.2, 161*0.2), *i->getbookpic(), source);
        ++y;
    }


}

/**
 * @brief avatar::addbooks gets the index of a book and create a new book that will be pushed into the bookstack
 * @param index
 */
void avatar::addbooks(int index){
    books* temp = new books(index);
    bookstack.push_back(temp);
}

/**
 * @brief avatar::deletestack gets rid of the book stack when avatar finishes a recipe or loses
 */
void avatar::deletestack(){
    bookstack.clear(); //clears the vector
    this->update(); //forcefully updates the graphics

}


