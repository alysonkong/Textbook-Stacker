#ifndef AVATAR_H
#define AVATAR_H
#include<iostream>
#include<QPaintEvent>
#include<QWidget>
#include<string>
#include "sprite.h"


//class avatar : public QWidget{
//    Q_OBJECT

//public:
//    avatar() : score(0), name("") {}
//    avatar(std::string user_name) :score(0), name(user_name) {}
//    virtual ~avatar() {};

//public slots:
//    void paintEvent(QPaintEvent *) override;

//signals:


//private:
//    size_t score;
//    std::string name;
    //QPixMap stationary;
//    QPixMap moveright;
//    QPixMap moveleft;


//};



enum Direction {
    Left, Right
};

class avatar : public Sprite
{
private:
    double vx=0, vy=0;
    double spd=0;
    Direction facing;
    QString name;
    size_t score;

public:
    QVariant itemChange(GraphicsItemChange change, const QVariant &value) override;
    inline
    avatar(QString user_name, QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1)
        : Sprite(ss,w,h,nx,ny,x_off,y_off,scale,tpf), name(user_name), score(0)
    {
        turn(Left);
    }
    inline
    double speed() { return spd; }
    inline
    void setSpeed(double v) { spd = v; }

    void go(Direction d); // go in this direction
    void turn(Direction d); // turn to a given direction
    inline void stop() {
        vx = vy = 0;
        pause(); // pause animation
        //resetAnimation(); // set frame to 0
    }
    inline void stop(Direction d) { if(facing == d) stop(); }

    void advance(int phase) override;
};


//qgraphicsitem , qgraphicsscene
//Qpixmap private member variables


#endif // AVATAR_H
