#ifndef AVATAR_H
#define AVATAR_H
#include<iostream>
#include<QPaintEvent>
#include<QWidget>
#include<string>
#include <vector>
#include "sprite.h"
#include <QGraphicsObject>
#include "books.h"


/**
 * @brief The Direction enum sets up the left or right movements for avatar
 */
enum Direction {
    Left, Right
};


/**
 * @brief The avatar class inherits from sprite class to create an avatar with the sprite sheet pics, as well as name and score
 */
class avatar : public QObject, public Sprite
{
    Q_OBJECT

private:
    double vx=0; //velocity in the x direction
    double spd=0; //speed of the avatar
    QString name;
    size_t score;
    std::vector<books*> bookstack;
    int aw, ah;
    int ax_off, ay_off;
    double a_scale;
    int acx=0, acy = 0;
    Direction facing; //direction that the avatar is facing




public slots:
    void updatescore();
    void addbooks(int);
    void deletestack();

public:
   // QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    /**
     * @brief avatar constructor
     * @param user_name name of the user
     * @param ss spritesheet
     * @param w width
     * @param h height
     * @param nx number of frames in the x direction
     * @param ny number of frames in the y direction
     * @param x_off and y_off is the coordinate location of upper left corner of first frame in the spritesheet
     * @param scale scale of the pixmap
     * @param tpf ticks per frame
     */
    inline
    avatar(QString user_name, QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1)
        : Sprite(ss,w,h,nx,ny,x_off,y_off,scale,tpf), name(user_name), score(0), bookstack(), aw(w), ah(h), ax_off(x_off), ay_off(y_off), a_scale(scale),
          acx(nx), acy(ny)
    {
        turn(Left); //sets the direction of avatar in beg as facing left
    }
    /**
     * @brief speed gets the speed of the avatar
     * @return speed
     */
    inline
    double speed() { return spd; }

    /**
     * @brief setSpeed sets the speed of the avatar
     * @param v is the speed that the function takes in to set the speed
     */
    inline
    void setSpeed(double v) { spd = v; }

    void go(Direction d); // go in this direction
    void turn(Direction d); // turn to a given direction

    /**
     * @brief stops the animation
     */
    inline void stop() {
        vx = 0;
        pause(); // pause animation
       // resetAnimation(); // set frame to 0
    }

    /**
     * @brief stop in the specified direction
     * @param d is the direction
     */
    inline void stop(Direction d) { if(facing == d) stop(); }

    QRectF boundingRect() const override;
    void advance(int phase) override; //advances the avatar in animation
    QPainterPath shape() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    size_t getscore();
    QString getname();
    void setscore();

};

//override boundingrect, shape, and paint
//QGraphicsItem::shape() const ->
//in paint, draw stack of books, expand
//also modify shape, polygon
//qgraphicsitem , qgraphicsscene
//Qpixmap private member variables
//return pos of avatar

#endif // AVATAR_H
