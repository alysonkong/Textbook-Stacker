#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <QPaintEvent>
#include <QWidget>
//#include <string> //do i need this??
#include <QLabel>
#include <QHBoxLayout>

/* FUNCTION:
 * the recipe class should communicate with player class, textbook class, game window (add recipe to layout of game)
 * it should randomly generate a recipe, which specifies the amount of each kind of textbook the user should catch
 * once a book is added onto the stack, it should update the recipe
 * should the recipes get more challenging with each round of the game??
 * recipe should also display how many of each book you still need to catch
 * this updates everytime the user adds a book to the stack
 * once the player catches all of the books in the recipe, display success/new round message
 * new recipe made everytime theres a new round
 */


class Recipe : public QWidget
{
    Q_OBJECT

public:
    Recipe();
    //virtual ~Recipe() //can recipe ever be used as a base class??? i dont think so
    QWidget display_recipe();


public slots:
    void paintEvent(QPaintEvent *) override;
    //void updateRecipe(Textbook_type t); //needs to receive signal that the player has caught the book

signals:


private:
    int bigcplusplus_count = 0;
    int bio_count = 0;
    int chem_count = 0;
    int soc_count = 0;
    int eng_count = 0;
    int philo_count = 0;

    QLabel title;
    QHBoxLayout layout;

};

#endif // RECIPE_H
