#include "recipe.h"
#include "books.h"
#include <QRandomGenerator>
#include <QFontDatabase>
#include <QSizePolicy>



namespace Recipe {

Recipe::Recipe() {

    //randomly generate a number between 6-9 for the total number of books the player needs to catch
    total_books = QRandomGenerator::global()->bounded(2,3); //6,10

    for (int i = 0; i < total_books; ++i) { //stack consists of 6-9 textbooks
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

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
    f = QFont(ffamily, 40);

    QLabel *book_names_title  = new QLabel("Textbooks:");
    book_names_title->setFont(f);
    book_names_title->setStyleSheet("QLabel { font: 35pt;}");

    layout = new QGridLayout;
    layout->addWidget(book_names_title, 0, 0, 1, 1);

    display_recipe();

    setLayout(layout);

    stacking_sound = new QMediaPlayer();
    stacking_sound->setMedia(QUrl("qrc:/music/stacking sound effect.mp3"));
    stacking_sound->setVolume(20);

    error_sound = new QMediaPlayer();
    error_sound->setMedia(QUrl("qrc:/music/bomb sound effect.mp3"));
    error_sound->setVolume(50);

}



void Recipe::newrecipe(QLayout* slayout){
        QLayoutItem* item;
        while ( ( item = slayout->takeAt( 0 ) ) != NULL )
        {
            delete item->widget();
            delete item;
        }
        //delete layout;
        //QGridLayout* nlayout = new QGridLayout;
        total_books = QRandomGenerator::global()->bounded(2,3); //6,10

        for (int i = 0; i < total_books; ++i) { //stack consists of 6-9 textbooks
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

        //layout = new QGridLayout;
        layout->addWidget(book_names_title, 0, 0, 1, 1);

        display_recipe();

        setLayout(layout);
}



void Recipe::book_caught(int code) {
    if (code == 0) {
        if (bigcplusplus_count != 0) {
            if (stacking_sound->state() == QMediaPlayer::PlayingState) {
                stacking_sound->setPosition(0);
            }
            else if (stacking_sound->state() == QMediaPlayer::StoppedState) {
                stacking_sound->play();
            }
            --bigcplusplus_count;
            --total_books;
            updatescore(0);
            update_recipe_display(0);
        }

        else {
            emit wrong_book();
        }
    }

    if (code == 1) {
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

    if (code == 2) {
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

    if (code == 3) {
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

    if (code == 4) {
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

    if (code == 5) {
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
    if(code >5){
        if (error_sound->state() == QMediaPlayer::PlayingState) {
            error_sound->setPosition(0);
        }
        else if (error_sound->state() == QMediaPlayer::StoppedState) {
            error_sound->play();
        }
        emit wrong_book();
    }

    if (total_books == 0) {
        this->newrecipe(layout);
        emit round_complete(1);
    }

    //call display_recipe, needs to change display in single window too

}


void Recipe::update_recipe_display(int code) {
    if (code == 0) {

        bigc_count_display->setText(QString::number(bigcplusplus_count));
    }

    if (code == 1) {
        bio_count_display->setText(QString::number(bio_count));
    }

    if (code == 2) {
        chem_count_display->setText(QString::number(chem_count));
    }

    if (code == 3) {
        soc_count_display->setText(QString::number(soc_count));
    }

    if (code == 4) {
        eng_count_display->setText(QString::number(eng_count));
    }

    if (code == 5) {
        philo_count_display->setText(QString::number(philo_count));
    }
}


void Recipe::display_recipe() {
    if (bigcplusplus_count != 0) {
//        QLabel *bigc_book = new QLabel("Big C++: ");
//        bigc_book->setFont(f);
//        bigc_book->setStyleSheet("QLabel { font: 18pt;}");
//        layout->addWidget(bigc_book, 1, 0, 1, 1);

        bigc_count_display = new QLabel;
        bigc_count_display->setText(QString::number(bigcplusplus_count));
        bigc_count_display->setFont(f);
        bigc_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(bigc_count_display, 1, 1, 1, 1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/redbigc++.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,1,0,1,1, Qt::AlignLeft);


    }


    if (bio_count != 0) {
//        QLabel* bio_book = new QLabel("Biology: ");
//        bio_book->setFont(f);
//        bio_book->setStyleSheet("QLabel { font: 18pt;}");
//        layout->addWidget(bio_book, 2, 0, 1, 1);

        bio_count_display = new QLabel;
        bio_count_display->setText(QString::number(bio_count));
        bio_count_display->setFont(f);
        bio_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(bio_count_display, 2, 1, 1,1);


        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/orangebio.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,2,0,1,1, Qt::AlignLeft);

    }


    if (chem_count != 0) {
//        QLabel* chem_book = new QLabel("Chemistry: ");
//        chem_book->setFont(f);
//        chem_book->setStyleSheet("QLabel { font: 18pt;}");
//        layout->addWidget(chem_book, 3, 0, 1,1);

        chem_count_display = new QLabel;
        chem_count_display->setText(QString::number(chem_count));
        chem_count_display->setFont(f);
        chem_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(chem_count_display, 3, 1, 1,1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/yellowchem.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,3,0,1,1, Qt::AlignLeft);
    }


    if (soc_count != 0) {
//        QLabel *soc_book = new QLabel("Sociology: ");
//        soc_book->setFont(f);
//        soc_book->setStyleSheet("QLabel { font: 18pt;}");
//        layout->addWidget(soc_book, 4, 0, 1,1);

        soc_count_display = new QLabel;
        soc_count_display->setText(QString::number(soc_count));
        soc_count_display->setFont(f);
        soc_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(soc_count_display, 4, 1, 1,1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/greensoc.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,4,0,1,1, Qt::AlignLeft);
    }


    if (eng_count != 0) {
//        QLabel *eng_book = new QLabel("English: ");
//        eng_book->setFont(f);
//        eng_book->setStyleSheet("QLabel { font: 18pt;}");
//        layout->addWidget(eng_book, 5, 0, 1,1);

        eng_count_display = new QLabel;
        eng_count_display->setText(QString::number(eng_count));
        eng_count_display->setFont(f);
        eng_count_display->setStyleSheet("QLabel { font: 25pt;}");
        layout->addWidget(eng_count_display, 5, 1, 1,1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/blueeng.png");
        pixmap = pixmap.scaled(500*0.3,161*0.3);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,5,0,1,1, Qt::AlignLeft);
    }


    if (philo_count != 0) {
//        QLabel *philo_book = new QLabel("Philosophy: ");
//        philo_book->setFont(f);
//        philo_book->setStyleSheet("QLabel { font: 18pt;}");
//        layout->addWidget(philo_book, 6, 0, 1,1);

        philo_count_display = new QLabel;
        philo_count_display->setText(QString::number(philo_count));
        philo_count_display->setFont(f);
        philo_count_display->setStyleSheet("QLabel { font: 25pt;}");
       layout->addWidget(philo_count_display, 6, 1,1,1);

       QLabel* book_label = new QLabel;
       QPixmap pixmap(":/spritesheets/purplephil.png");
       pixmap = pixmap.scaled(500*0.3,161*0.3);
       book_label->setPixmap(pixmap);
       //book_label.setMask(pixmap.mask());

       layout->addWidget(book_label,6,0,1,1, Qt::AlignLeft);
    }


}
}

