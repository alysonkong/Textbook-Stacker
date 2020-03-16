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

    singlewindow(QString const & name1); //constructor for singlewindow class
    ~singlewindow(); //destructor for singlewindow class


signals:
   void pressedmain();
   void dropbook(books*);
   void pname_score(QString, int);
   void finalscore(QString, int);
   void change_timer(int);
   void roundcomplete(int);
   void gamewon(QString, int);
   void change_music();

public slots:
    void returntomain();
    void updatescorelabel();
    void newrecipe();
    void deductlife();
    void roundupdate();
    void newround();
    void playpause_music();

private:
    QPixmap* spritesheet; //holds the avatar sprite
    QPixmap back; //the background
    QTimer* timer; //timer that controls the construction of the sprites and how they fall
    QPushButton* exit; //exit button that takes the player back to the main window
    avatar* mc; //avatar for the player to control
    QLabel* pscore; //
    size_t lives; //number of player's lives left
    QHBoxLayout* livesnum; //stores the life hearts
    QLabel* heart1; //first life
    QLabel* heart2; //second life
    QLabel* heart3; //third life
    QPushButton* music_button; //turns music on/off
    GameView* view; //the gameview
    Recipe::Recipe* r; //recipe object
    QWidget* recipe_display; //displays recipe
    QGridLayout *layout; //widget layout
    int round_number = 0; //which round the player has completed

};


#endif // SINGLEWINDOW_H

