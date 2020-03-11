#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QGraphicsItem>
//#include <list>
#include <string>
//#include <QStackedWidget>

//#include <QGraphicsScene>
//#include <QPainter>

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
    //QWidget* display_recipe(); //should it be void????


    void update_recipe_display(int code);
    //void clear_recipe();
    int get_bigc_count();
    int get_bio_count();
    int get_chem_count();
    int get_soc_count();
    int get_eng_count();
    int get_philo_count();




//these slots and signals should be ready whenever the corresponding slots and signals are ready

public slots:
    void book_caught(int code);
    void newrecipe(QLayout* layout);



signals:
    void round_complete(int);
    void wrong_book();
    void updatescore(int); //the int here is gonna be the book code, not points added




private:
    int bigcplusplus_count = 0;
    int bio_count = 0;
    int chem_count = 0;
    int soc_count = 0;
    int eng_count = 0;
    int philo_count = 0;

    QLabel* bigc_count_display;
    QLabel *bio_count_display;
    QLabel *chem_count_display;
    QLabel *soc_count_display;
    QLabel *eng_count_display;
    QLabel *philo_count_display;

    QGridLayout *layout;

    int total_books = 0;

    //std::list<int> stack; //list keeps track of which books need to be caught


};

}

#endif
