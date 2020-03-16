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

/**
 * @brief The Recipe class randomly generates and displays a recipe of textbooks that the player needs to catch
 */
class Recipe : public QWidget {
    Q_OBJECT

public:
    Recipe();
    void update_recipe_display(int code);
    void newrecipe(QLayout* layout);

public slots:
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
