#include "recipe.h"
#include <QRandomGenerator>

Recipe::Recipe() {
    //randomly generate a number between 10 and 15 for the total number of books the player needs to catch
    int total_books = QRandomGenerator::global()->bounded(10, 16);

    for (int i = 0; i < total_books; ++i) { //stack consists of 10-15 textbooks
        int book_code = QRandomGenerator::global()->bounded(6);

        if (book_code == 0) {
            ++bigcplusplus_count;
            //stack.push_back(textbook);
        }

        if (book_code == 1) {
            ++bio_count;
            //stack.push_back(textbook);
        }

        if (book_code == 2) {
            ++chem_count;
            //stack.push_back(textbook);
        }

        if (book_code == 3) {
            ++soc_count;
            //stack.push_back(textbook);
        }

        if (book_code == 4) {
            ++eng_count;
            //stack.push_back(textbook);
        }

        if (book_code == 5) {
            ++philo_count;
            //stack.push_back(textbook);
        }

    }

    //call display_recipe();??

}

void Recipe::display_recipe() { //should I return widget or be void??

    title  = new QLabel("Textbooks to catch");

    bigc_book = new QLabel("Big C++");
    bio_book = new QLabel("Biology");
    chem_book = new QLabel("Chemistry");
    soc_book = new QLabel("Sociology");
    eng_book = new QLabel("English");
    philo_book = new QLabel("Philosophy");


    QGridLayout *book_names = new QGridLayout;
    book_names->addWidget(title, 0, 0, 1, 2, Qt::AlignCenter);
    book_names->addWidget(bigc_book, 1, 0, 1, 1, Qt::AlignLeft);
    book_names->addWidget(bio_book, 2, 0, 1, 1, Qt::AlignLeft);
    book_names->addWidget(chem_book, 3, 0, 1, 1, Qt::AlignLeft);
    book_names->addWidget(soc_book, 4, 0, 1, 1, Qt::AlignLeft);
    book_names->addWidget(eng_book, 5, 0, 1, 1, Qt::AlignLeft);
    book_names->addWidget(philo_book, 6, 0, 1, 1, Qt::AlignLeft);

    //need to add small images of each book next to the name of it



    setLayout(book_names);
    show();

}

