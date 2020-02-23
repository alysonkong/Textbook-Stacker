#include "FallingObject.h"

/*
FallingObject::FallingObject() : x_val(RAND), y_val(0), fall_rate(1), sprite(x_val, y_val, 5, 10), on_stack(false), on_ground(false) {

}

void FallingObject::fall() {
    while ((on_stack == false) && (on_ground == false)) {
        y_val += fall_rate;
        sprite.translate(0, fall_rate);
        QCoreApplication::processEvents();
        repaint();
        if (y_val >= book_stack.get_height()) on_stack = true;
        if (y_val >= 400) on_ground = true;
    }
}
*/
