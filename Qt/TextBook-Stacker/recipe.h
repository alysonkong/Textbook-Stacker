//#ifndef RECIPE_H
//#define RECIPE_H

<<<<<<< HEAD
//#include <iostream>
//#include <QPaintEvent>
//#include <QWidget>
//#include <string> //do i need this??
//#include <QLabel>
//#include <QHBoxLayout>
//#include <vector>
//#include <QLabel>
//#include <QGridLayout>
//#include <vector>
//#include <QPainter>


//* FUNCTION:
// * the recipe class should communicate with player class, textbook class, game window (add recipe to layout of game)
// * it should randomly generate a recipe, which specifies the amount of each kind of textbook the user should catch
// * once a book is added onto the stack, it should update the recipe
// * should the recipes get more challenging with each round of the game??
// * recipe should also display how many of each book you still need to catch
// * this updates everytime the user adds a book to the stack
// * once the player catches all of the books in the recipe, display success/new round message
// * new recipe made everytime theres a new round
// */

=======
#include <iostream>
#include <QPaintEvent>
#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <vector>
#include <QLabel>
#include <QGridLayout>
#include <vector>
#include <QPainter>


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
>>>>>>> af4f4ad660c031ec8b72285a1add2cfc3737aff7

//class Recipe : public QWidget
//{
//    Q_OBJECT

//public:
//    Recipe();
//    //virtual ~Recipe() //can recipe ever be used as a base class??? i dont think so
//    QWidget display_recipe();

<<<<<<< HEAD
=======
public:
    Recipe();
    //virtual ~Recipe() //can recipe ever be used as a base class??? i dont think so
    void display_recipe();
>>>>>>> af4f4ad660c031ec8b72285a1add2cfc3737aff7

//public slots:
//    void paintEvent(QPaintEvent *) override;
//    //void updateRecipe(Textbook_type t); //needs to receive signal that the player has caught the book

//signals:

<<<<<<< HEAD
//    void display_recipe();


//public slots:
//    //void paintEvent(QPaintEvent *) override;
//    //void updateRecipe(Textbook_type t); //needs to receive signal that the player has caught the book

//signals:
//    //void round_complete(); //needs to send signal that round is complete
=======


signals:
    //void round_complete(); //needs to send signal that round is complete
>>>>>>> af4f4ad660c031ec8b72285a1add2cfc3737aff7



<<<<<<< HEAD
//private:
//    int bigcplusplus_count = 0;
//    int bio_count = 0;
//    int chem_count = 0;
//    int soc_count = 0;
//    int eng_count = 0;
//    int philo_count = 0;
=======
    QLabel *title;
    QHBoxLayout *layout;
>>>>>>> af4f4ad660c031ec8b72285a1add2cfc3737aff7

//    QLabel title;
//    QHBoxLayout layout;
//    QLabel *title;
//    QGridLayout *layout;

//    QLabel *bigc_book;
//    QLabel *bio_book;
//    QLabel *chem_book;
//    QLabel *soc_book;
//    QLabel *eng_book;
//    QLabel *philo_book;

<<<<<<< HEAD

=======
    //std::vector<Textbook> stack;
>>>>>>> af4f4ad660c031ec8b72285a1add2cfc3737aff7

//    //std::vector<Textbook> stack;

//};

//#endif // RECIPE_H
