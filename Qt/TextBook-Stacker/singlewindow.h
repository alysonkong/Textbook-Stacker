#ifndef SINGLEWINDOW_H
#define SINGLEWINDOW_H


#include <QWidget>
#include <QGraphicsScene>
#include <QTimer>
#include<QPushButton>
#include "nameinputwindow.h"
#include <QLabel>
#include "avatar.h"
#include "books.h"
#include "gameview.h"

#include "recipe.h"

/**
 * @brief The singlewindow class inherits from QWidget to create the window which the singleplayer plays the game on
 */
class singlewindow : public QWidget
{

    Q_OBJECT

public:

    singlewindow(QString const & name1);
    ~singlewindow(); //destructor for singlewindow class

signals:
   void pressedmain(); // @brief pressedmain signal that a
   void dropbook(books*);

public slots:
    void returntomain(); //directs this window back to the main window
    void updatescorelabel(int);
    void dropobject();

private:
   // QGraphicsScene scene; //scene where the game is taking place
    QPixmap* spritesheet; //holds the avatar sprite
    QTimer* timer; //timer that controls the construction of the sprites and how they fall
    QPushButton* exit; //exit button that takes the player back to the main window
    avatar* mc; //avatar for the player to control
    books* m; //falling books that the player has to catch with their avatar
    QLabel* pscore;
    GameView* view;

};


#endif // SINGLEWINDOW_H
