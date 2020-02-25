#ifndef SPRITE_H
#define SPRITE_H

#include<QGraphicsItem>


/**
 * @brief The Sprite class creates a graphics item out of a spritesheet
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

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    void advance(int phase) override;

    // constructors/getters/setters
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

    /**
     * @brief setScale sets the scale of the graphics item/sprite
     * @param s
     */
    inline void setScale(double s) { _scale = s; }

    /**
     * @brief scale gets the scale of the sprite object
     * @return
     */
    inline double scale() { return _scale; }

    /**
     * @brief sequence
     * @return
     */
    inline int sequence() { return cy; }

    /**
     * @brief setSequence sets the current frame of the spritesheet
     * @param seq_num
     */
    inline void setSequence(int seq_num) {
        cy = (seq_num % ny);
        if(cy < 0) cy+=ny;
    }

    /**
     * @brief animating determines whether animating is true or false
     * @return true or false of animating boolean
     */
    inline bool animating() { return _animating; }

    /**
     * @brief setAnimating sets animating as either true or false
     * @param a is a boolean object that is either true or false
     */
    inline
    void setAnimating(bool a) { _animating = a; }

    /**
     * @brief pause animating false
     */
    inline void pause() { setAnimating(false); }

    /**
     * @brief play animating true
     */
    inline void play() { setAnimating(true); }

    /**
     * @brief resetAnimation rests the animation to the frame
     */
    inline void resetAnimation() { cx=0; }
};

#endif // SPRITE_H
