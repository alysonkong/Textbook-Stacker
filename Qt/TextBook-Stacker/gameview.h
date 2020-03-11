#ifndef GAMEVIEW_H
#define GAMEVIEW_H

#include <QGraphicsView>
#include <QTimer>
#include "avatar.h"
#include <QVariant>
#include "books.h"

/**
 * @brief The GameView class inherits from QGraphicsView and is the view for the gamewindow and singlewindow
 */
class GameView : public QGraphicsView
{
    Q_OBJECT
private:
    avatar* mc; //avatar that the players can control
    QGraphicsScene scene; //the scene where our game is taking place
    books* b;
    QTimer timer; //timer for constructing and moving the sprites
    QTimer timer2;
    QPixmap* back;

public:
    ~GameView();
    GameView(avatar* mc, books*);
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    //void advance()
public slots:
    void bookdrop();
   // void getbooktype(int);
    void getbook(int);
    void increase_speed(int);
signals:
    void booktypetowindow(int);
   // void sendbook(books*);


protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // GAMEVIEW_H
