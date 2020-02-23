
#include "avatar.h"



void avatar::go(Direction d) // go in this direction
{
    //stop(); // set both velocities to 0
    vx=vy=0;
    turn(d); // turn to direction d
    switch(d) {
    case Left:
        vx = -spd;
        break;
    case Right:
        vx = spd;
        break;
    }
    play();
}
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


void avatar::advance(int phase) {
    if(phase) {
        setPos(mapToScene(QPointF(vx,vy)));
    }
    Sprite::advance(phase);
}


