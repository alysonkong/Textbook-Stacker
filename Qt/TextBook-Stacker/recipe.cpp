#include "recipe.h"
#include "books.h"
#include <QRandomGenerator>
#include <QFontDatabase>
#include <QSizePolicy>


namespace Recipe {

/**
*@brief Recipe::Recipe randomly generates a list of how many textbooks the user needs to catch
*/
Recipe::Recipe() {

    //randomly generate a number between 6-9 for the total number of books the player needs to catch
    total_books = QRandomGenerator::global()->bounded(2,3); //(6,10)

    for (int i = 0; i < total_books; ++i) {
        int book_code = QRandomGenerator::global()->bounded(6); //randomly assign code to differentiate 6 different types of books

        if (book_code == 0) { //if number generated corresponds to the book code for big c++: 0
            ++bigcplusplus_count; //update textbook count
        }

        if (book_code == 1) { //biology book code: 1
            ++bio_count;
        }

        if (book_code == 2) { //chemistry book code: 2
            ++chem_count;
        }

        if (book_code == 3) { //sociology book code: 3
            ++soc_count;
        }

        if (book_code == 4) { //english book code: 4
            ++eng_count;
        }

        if (book_code == 5) { //philosophy book code: 5
            ++philo_count;
        }
    }

    //add bubble font
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
    f = QFont(ffamily, 40);

    QLabel *book_names_title  = new QLabel("Textbooks:"); //add title to recipe display
    book_names_title->setFont(f);
    book_names_title->setStyleSheet("QLabel { font: 35pt;}");

    layout = new QGridLayout;
    layout->addWidget(book_names_title, 0, 0, 1, 1); //add title to layout

    display_recipe(); //display the recipe

    setLayout(layout); //make layout the recipe layout

    //add sound effect for books stacking on top of each other
    stacking_sound = new QMediaPlayer();
    stacking_sound->setMedia(QUrl("qrc:/music/stacking sound effect.mp3"));
    stacking_sound->setVolume(20);

    //add sound effect for avatar catching an F letter
    error_sound = new QMediaPlayer();
    error_sound->setMedia(QUrl("qrc:/music/bomb sound effect.mp3"));
    error_sound->setVolume(50);

}



/**
*@brief Recipe::update_recipe_display updates the recipe display, showing how many of each type of textbook the user needs to catch
* @param code the book code of the book that was correctly caught
*/
void Recipe::update_recipe_display(int code) {

    if (code == 0) { //if user caught big c++
        bigc_count_display->setText(QString::number(bigcplusplus_count)); //change amount left in recipe display
    }

    if (code == 1) { //if user caught biology
        bio_count_display->setText(QString::number(bio_count)); //change display
    }

    if (code == 2) { //if user caught chemistry
        chem_count_display->setText(QString::number(chem_count)); //change display
    }

    if (code == 3) { //if user caught sociology
        soc_count_display->setText(QString::number(soc_count)); //change display
    }

    if (code == 4) { //if user caught english
        eng_count_display->setText(QString::number(eng_count)); //change display
    }

    if (code == 5) { //if user caught philosophy
        philo_count_display->setText(QString::number(philo_count)); //change display
    }
}



/**
 * @brief Recipe::newrecipe generates and displays a new recipe, replacing the old one
 * @param layout is the layout of the recipe display prior to the recipe getting updated
 */
void Recipe::newrecipe(QLayout* slayout){

        QLayoutItem* item;
        while ( ( item = slayout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }

        //rest of function is code to generate a new recipe:

        total_books = QRandomGenerator::global()->bounded(2,3); //6,10

        for (int i = 0; i < total_books; ++i) {
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

        QLabel *book_names_title  = new QLabel("Textbooks:");
        book_names_title->setFont(f);
        book_names_title->setStyleSheet("QLabel { font: 20pt;}");

        layout->addWidget(book_names_title, 0, 0, 1, 1);

        display_recipe();

        setLayout(layout);
}



/**
 * @brief Recipe::book_caught receives a signal from gameview sending the type of book caught by the avatar
 * @param code is the type of book caught
 */
void Recipe::book_caught(int code) {

    //checks which book code it is and sends out corresponding signals

    if (code == 0) { //if book caught is big c++
        if (bigcplusplus_count != 0) { //if there are still big c++ books in the recipe

            //play stacking sound effect
            if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                stacking_sound->setPosition(0);
            }
            else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                stacking_sound->play();
            }

            --bigcplusplus_count; //update big c++ count
            --total_books; //update total books count
            updatescore(0); //updates score indicating big c++ was caught
            update_recipe_display(0); //updates the recipe display so it shows user has caught big c++
        }

        else { //there are no big c++ books needed to be caught
            emit wrong_book();
        }
    }

    if (code == 1) { //repeat process for if user caught biology book
        if (bio_count != 0) {
            if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                stacking_sound->setPosition(0);
            }
            else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                stacking_sound->play();
            }

            --bio_count;
            --total_books;
            updatescore(1);
            update_recipe_display(1);
        }

        else {
            emit wrong_book();
        }
    }

    if (code == 2) { //repeat process for if user caught a chemistry book
        if (chem_count != 0) {
            if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                stacking_sound->setPosition(0);
            }
            else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                stacking_sound->play();
            }

            --chem_count;
            --total_books;
            updatescore(2);
            update_recipe_display(2);
        }

        else {
            emit wrong_book();
        }
    }

    if (code == 3) { //repeat process for if user caught a sociology book
        if (soc_count != 0) {
            if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                stacking_sound->setPosition(0);
            }
            else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                stacking_sound->play();
            }
            --soc_count;
            --total_books;
            updatescore(3);
            update_recipe_display(3);
        }

        else {
            emit wrong_book();
        }
    }

    if (code == 4) { //repeat process for if user caught an english book
        if (eng_count != 0) {
            if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                stacking_sound->setPosition(0);
            }
            else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                stacking_sound->play();
            }
            --eng_count;
            --total_books;
            updatescore(4);
            update_recipe_display(4);
        }

        else {
            emit wrong_book();
        }
    }

    if (code == 5) { //repeat process for if user caught a philosophy book
        if (philo_count != 0) {
            if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                stacking_sound->setPosition(0);
            }
            else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                stacking_sound->play();
            }
            --philo_count;
            --total_books;
            updatescore(5);
            update_recipe_display(5);
        }

        else {
            emit wrong_book();
        }
    }

    if(code >5){ //if book code > 5, indicates user caught an F
        //play error sound
        if (error_sound->state() == QMediaPlayer::PlayingState) {
            error_sound->setPosition(0);
        }
        else if (error_sound->state() == QMediaPlayer::StoppedState) {
            error_sound->play();
        }

        emit wrong_book(); //send out signal that user caught the wrong thing
    }

    if (total_books == 0) { //if no more books left to catch
        this->newrecipe(layout); //replace old recipe and generate and display new recipe
        emit round_complete(1); //send out signal that the round is complete
    }
}




/**
 * @brief Recipe::display_recipe displays the recipe, showing the user how many of each type of book they need to catch
 */
void Recipe::display_recipe() {

    if (bigcplusplus_count != 0) { //if there is at least one big c++ book in recipe
        bigc_count_display = new QLabel; //make label for book count
        bigc_count_display->setText(QString::number(bigcplusplus_count));

        bigc_count_display->setFont(f); //set font
        bigc_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(bigc_count_display, 1, 1, 1, 1);

        QLabel* book_label = new QLabel; //create label for book pixmap being displayed
        QPixmap pixmap(":/spritesheets/redbigc++.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);

        layout->addWidget(book_label,1,0,1,1, Qt::AlignLeft); //add book to recipe display
    }


    if (bio_count != 0) { //if there is at least one biology book in recipe
        bio_count_display = new QLabel; //make label for book count
        bio_count_display->setText(QString::number(bio_count));

        bio_count_display->setFont(f); //set font
        bio_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(bio_count_display, 2, 1, 1,1);


        QLabel* book_label = new QLabel; //create label for book pixmap being displayed
        QPixmap pixmap(":/spritesheets/orangebio.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);

        layout->addWidget(book_label,2,0,1,1, Qt::AlignLeft); //add book to recipe display
    }


    if (chem_count != 0) { //if there is at least one chemistry book in recipe
        chem_count_display = new QLabel; //make label for book count
        chem_count_display->setText(QString::number(chem_count));

        chem_count_display->setFont(f); //set font
        chem_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(chem_count_display, 3, 1, 1,1);

        QLabel* book_label = new QLabel; //create label for book pixmap being displayed
        QPixmap pixmap(":/spritesheets/yellowchem.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);

        layout->addWidget(book_label,3,0,1,1, Qt::AlignLeft); //add book to recipe display
    }


    if (soc_count != 0) { //if there is at least one sociology book in recipe
        soc_count_display = new QLabel; //make label for book count
        soc_count_display->setText(QString::number(soc_count));

        soc_count_display->setFont(f); //set font
        soc_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(soc_count_display, 4, 1, 1,1);

        QLabel* book_label = new QLabel; //create label for book pixmap being displayed
        QPixmap pixmap(":/spritesheets/greensoc.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);

        layout->addWidget(book_label,4,0,1,1, Qt::AlignLeft); //add book to recipe display
    }


    if (eng_count != 0) { //if there is at least one english book in recipe
        eng_count_display = new QLabel; //make label for book count
        eng_count_display->setText(QString::number(eng_count));

        eng_count_display->setFont(f); //set font
        eng_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(eng_count_display, 5, 1, 1,1);

        QLabel* book_label = new QLabel; //create label for book pixmap being displayed
        QPixmap pixmap(":/spritesheets/blueeng.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);

        layout->addWidget(book_label,5,0,1,1, Qt::AlignLeft); //add book to recipe display
    }


    if (philo_count != 0) { //if there is at least one philosophy book in recipe
        philo_count_display = new QLabel; //make label for book count
        philo_count_display->setText(QString::number(philo_count));

        philo_count_display->setFont(f); //set font
        philo_count_display->setStyleSheet("QLabel { font: 25pt;}");
       layout->addWidget(philo_count_display, 6, 1,1,1);

       QLabel* book_label = new QLabel; //create label for book pixmap being displayed
       QPixmap pixmap(":/spritesheets/purplephil.png");
       pixmap = pixmap.scaled(500*0.3,161*0.3);
       book_label->setPixmap(pixmap);

       layout->addWidget(book_label,6,0,1,1, Qt::AlignLeft); //add book to recipe display
    }


}
}

