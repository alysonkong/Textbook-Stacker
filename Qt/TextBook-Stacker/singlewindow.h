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

/**
 * @brief The singlewindow class inherits from QWidget to create the window which the singleplayer plays the game on
 */
class singlewindow : public QWidget
{

    Q_OBJECT

public:

    /**
     * @brief singlewindow constructor that constructs a singleplayer window with one name of the singleplayer
     * @param name1 the name of the player
     */
    singlewindow(QString const & name1);

    ~singlewindow(); //destructor for singlewindow class

signals:
    /**
    * @brief pressedmain signal that a button in the singlewindow class wants to go back to main
    */
   void pressedmain();

public slots:
   /**
     * @brief returntomain slot that directs this window back to the main window
     */
    void returntomain();

private:
    /**
     * @brief scene the scene where the game is taking place
     */
    QGraphicsScene scene;
    /**
     * @brief spritesheet holds the sprites (avatar, books, etc.)
     */
    QPixmap* spritesheet;
    /**
     * @brief timer timer that controls the construction of the sprites and how they fall
     */
    QTimer timer;
    /**
     * @brief exit button that takes the player back to the main window
     */
    QPushButton* exit;
    /**
     * @brief mc avatar for the player to control
     */
    avatar* mc;
    /**
     * @brief m the falling books that the player has to catch with their avatar
     */
    books* m;

};


#endif // SINGLEWINDOW_H
