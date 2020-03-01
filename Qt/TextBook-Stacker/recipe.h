#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QGraphicsItem>
#include <list>
#include <string>


namespace Recipe {

/* FUNCTION:
 * the recipe class randomly generates a "recipe" of textbooks that the player needs to catch, a new recipe every round of the game
 * it displays the the amount of textbooks the player still needs to catch, updating every time the player catches a correct book
 * once the player catches all of the books in the recipe, display success/new round message
 */
class Recipe : public QWidget {
    Q_OBJECT

public:
 /**
 *@brief the recipe constructor randomly generates a list of how many textbooks the user needs to catch
 */
    Recipe();

 /**
  *@brief the function displays the recipe and updates it, showing how many of each type of textbook the user needs to catch
 */
    QWidget* display_recipe();
    //void display_recipe();


//public slots:
    //void paintEvent(QPaintEvent *) override;
//    void book_caught(int code);



//signals:
    //void round_complete(); //needs to send signal that round is complete, tells
    //void update_stack(int code);
    //void wrong_book();



private:
    int bigcplusplus_count = 0;
    int bio_count = 0;
    int chem_count = 0;
    int soc_count = 0;
    int eng_count = 0;
    int philo_count = 0;

    QLabel *title;
    QGridLayout *layout;

    int total_books = 0;


    QWidget* recipee;




    //std::list<int> stack; //list keeps track of which books need to be caught


};

}

#endif
