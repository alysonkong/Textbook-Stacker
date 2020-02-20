#include "recipe.h"
#include <QRandomGenerator>

Recipe::Recipe() : title("Textbook List") {
    //randomly generate a number between 10 and 15 for the total number of books the player needs to catch
    int total_books = QRandomGenerator::global()->bounded(10, 16);

    for (int i = 0; i < total_books; ++i) { //stack consists of 10-15 textbooks
        int book_code = QRandomGenerator::global()->bounded(6);

        if (book_code == 0) {
            ++bigcplusplus_count;
        }

        if (book_code == 1) {
            ++bio_count;
        }

        if (book_code == 2) {
            ++chem_count;
        }

        if (book_code == 3) {
            ++soc_count;
        }

        if (book_code == 4) {
            ++eng_count;
        }

        if (book_code == 5) {
            ++philo_count;
        }

    }

}

QWidget Recipe::display_recipe() {
    //create widget that will be added to layout of game screen
    QLabel *title  = new QLabel("Textbooks to catch");
    QFont f("Arial", 14, QFont::Bold);
    title->setFont(f);
    title->setAlignment(Qt::AlignCenter);

    QVBoxLayout *book_names = new QVBoxLayout;


    //more work to do here




}
