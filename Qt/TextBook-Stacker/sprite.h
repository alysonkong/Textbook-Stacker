//#ifndef SPRITE_H
//#define SPRITE_H

//#include<QGraphicsItem>

//class Sprite : public QGraphicsItem
//{
//private:
//    QPixmap* ss; // spritesheet
//    int w, h; // width/height of a single frame
//    int nx, ny; // number of frames in the x/y direction
//    int cx=0, cy=0; // current frame position
//    int x_off, y_off; // location of upper left corner of first frame in the spritesheet
//    double _scale; // scale of the sprite
//    int ticks_per_frame = 1;
//    int ticks = 1;

//    bool _animating=false;
//public:

//    // overrides
//    QRectF boundingRect() const override;
//    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
//    void advance(int phase) override;

//    // constructors/getters/setters
//    inline
//    Sprite(QPixmap* ss, int w, int h, int nx, int ny, int x_off, int y_off, double scale = 1, int tpf=1)
//        : ss(ss)
//        , w(w), h(h)
//        , nx(nx), ny(ny)
//        , x_off(x_off), y_off(y_off)
//        , _scale(scale)
//        , ticks_per_frame(tpf)
//    {
//    }

//    inline
//    void setScale(double s) {
//        _scale = s;
//    }
//    inline
//    double scale() {
//        return _scale;
//    }

//    inline
//    int sequence() { return cy; }
//    inline
//    void setSequence(int seq_num) {
//        cy = (seq_num % ny);
//        if(cy < 0) cy+=ny;
//    }

//    inline
//    bool animating() { return _animating; }
//    inline
//    void setAnimating(bool a) { _animating = a; }
//    inline void pause() { setAnimating(false); }
//    inline void play() { setAnimating(true); }
//    inline void resetAnimation() { cx=0; }
//};

//#endif // SPRITE_H
