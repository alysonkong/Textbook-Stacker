#ifndef SPRITE_H
#define SPRITE_H

#include<QGraphicsItem>



//modify using base rectangle
/**
 * @brief The Sprite class creates a graphicsitem from a srite sheet
 */
class Sprite : public QGraphicsItem
{

private:
    QPixmap* ss; // spritesheet
    int w, h; // width/height of a single frame
    int nx, ny; // number of frames in the x/y direction
    int cx=0, cy=0; // current frame position
    int x_off, y_off; // location of upper left corner of first frame in the spritesheet
    double _scale; // scale of the sprite
    int ticks_per_frame = 1;
    int ticks = 1;

    bool _animating=false;
public:

    // overrides
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int phase) override;

    /**
     * @brief Sprite constructor
     */
    inline
    Sprite(QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1)
        : ss(ss)
        , w(w), h(h)
        , nx(nx), ny(ny)
        , x_off(x_off), y_off(y_off)
        , _scale(scale)
        , ticks_per_frame(tpf)
    {
    }

    //sets the scale of the sprite
    inline
    void setScale(double s) {
        _scale = s;
    }

    /**
     * @brief scale gets the scale of sprite
     * @return return scale
     */

    inline
    double scale() {
        return _scale;
    }

    /**
     * @brief sequence gets the current frame position
     * @return current frame position
     */
    inline
    int sequence() { return cy; }

    /**
     * @brief setSequence sets the sequence of the sprite
     * @param seq_num is the sequence
     */
    inline
    void setSequence(int seq_num) {
        cy = (seq_num % ny);
        if(cy < 0) cy+=ny;
    }

    /**
     * @brief animating returns the bool type of animating
     * @return  true or false bool value
     */
    inline
    bool animating() { return _animating; }

    /**
     * @brief setAnimating sets the animating to either true or false
     * @param a is either t or f
     */
    inline
    void setAnimating(bool a) { _animating = a; }

    /**
     * @brief pause sets animating to false
     */
    inline void pause() { setAnimating(false); }

    /**
     * @brief play sets animating to true
     */
    inline void play() { setAnimating(true); }

    /**
     * @brief resetAnimation reset the animation to frame 0
     */
    inline void resetAnimation() { cx=0; }
};

#endif // SPRITE_H
