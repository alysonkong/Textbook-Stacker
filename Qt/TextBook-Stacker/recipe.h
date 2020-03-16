#ifndef RECIPE_H
#define RECIPE_H

#include <iostream>
#include <QWidget>
#include <QLabel>
#include <QPixmap>
#include <QGridLayout>
#include <QGraphicsItem>
#include <QMediaPlayer>

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
    *@brief the function updates the recipe display, showing how many of each type of textbook the user needs to catch
    * @param code the book code of the book that was correctly caught
    */
    void update_recipe_display(int code);

    /**
     * @brief newrecipe generates and displays a new recipe, replacing the old one
     * @param layout is the layout of the recipe display prior to the recipe getting updated
     */
    void newrecipe(QLayout* layout);

public slots:
    /**
     * @brief book_caught receives a signal from gameview sending the type of book caught by the avatar
     * @param code is the type of book caught
     */
    void book_caught(int code);

signals:
    /**
     * @brief round_complete sends signal out that the user has caught all of the necessary books in the round
     */
    void round_complete(int);

    /**
     * @brief wrong_book sends out signal that the avatar has caught the wrong book
     */
    void wrong_book();

    /**
     * @brief updatescore sends out signal that the score should be updated since a correct book was caught
     * @param int the number indicating which textbook was caught
     */
    void updatescore(int);

private:
    /**
     * @brief display_recipe displays the recipe, showing the user how many of each type of book they need to catch
     */
    void display_recipe();

    int bigcplusplus_count = 0;
    int bio_count = 0;
    int chem_count = 0;
    int soc_count = 0;
    int eng_count = 0;
    int philo_count = 0;
    int total_books = 0;
    QLabel* bigc_count_display;
    QLabel *bio_count_display;
    QLabel *chem_count_display;
    QLabel *soc_count_display;
    QLabel *eng_count_display;
    QLabel *philo_count_display;
    QGridLayout *layout;
    QFont f;
    QMediaPlayer* stacking_sound;
    QMediaPlayer* error_sound;
};

}

#endif
