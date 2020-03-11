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
#include "sidestack.h"


/**
 * @brief The singlewindow class inherits from QWidget to create the window which the singleplayer plays the game on
 */
class singlewindow : public QWidget
{

    Q_OBJECT

public:

    singlewindow(QString const & name1);
    ~singlewindow(); //destructor for singlewindow class
    //int get_round_num();

signals:
   void pressedmain(); // @brief pressedmain signal that a
   void dropbook(books*);
   void pname_score(QString, int);
   void finalscore(int);
   void change_timer(int);
   void roundcomplete(int);

public slots:
    void returntomain(); //directs this window back to the main window
    void updatescorelabel();
    void newrecipe();
    void deductlife();
    void roundupdate();
    void newround();

private:
   // QGraphicsScene scene; //scene where the game is taking place
    QPixmap* spritesheet; //holds the avatar sprite
    QPixmap back;
    QTimer* timer; //timer that controls the construction of the sprites and how they fall
    QPushButton* exit; //exit button that takes the player back to the main window
    avatar* mc; //avatar for the player to control
    QLabel* pscore;
    size_t lives;
    QLabel* livesnum;
    GameView* view;
    SideStack* sstack;
    Recipe::Recipe* r;
    QWidget* recipe_display;
    QGridLayout *layout;
    int round_number = 0;

    //BookStack* bookstack;

};


#endif // SINGLEWINDOW_H
