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
private:
    avatar* mc; //avatar that the players can control
    QGraphicsScene scene; //the scene where our game is taking place
    QTimer timer; //timer for constructing and moving the sprites
    books* b; //books that fall from the sky
public:
    /**
     * @brief GameView constructor definition for gameview
     * @param mc avatar for the player
     * @param books sprite for the falling books
     */
    GameView(avatar* mc, books*);

    /**
     * @brief drawBackground draws background of this gameview
     * @param painter the painter we want for this function
     * @param rect the rect we want for this function
     */
    void drawBackground(QPainter *painter, const QRectF &rect) override;

protected:
    /**
     * @brief keyPressEvent checks if a key is pressed
     * @param event if a key event if happening and which one
     */
    void keyPressEvent(QKeyEvent *event) override;

    /**
     * @brief keyReleaseEvent checks if a key is released
     * @param event if a key event if happening and which one
     */
    void keyReleaseEvent(QKeyEvent *event) override;

};

#endif // GAMEVIEW_H
