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
    books* b; //books that are dropping
    QTimer timer; //timer for constructing and moving the sprites
    QTimer timer2; //timer for books dropping
    QPixmap* back; //background image

public:
    ~GameView();
    GameView(avatar* mc);
    void drawBackground(QPainter *painter, const QRectF &rect) override;
    void stopbookdrop();

public slots:
    void bookdrop();
    void getbook(int);
    void increase_speed(int);

signals:
    void booktypetowindow(int);

protected:
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // GAMEVIEW_H
