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
            //stack.push_back(0);
        }

        if (book_code == 1) {
            ++bio_count;
            //stack.push_back(1);
        }

        if (book_code == 2) {
            ++chem_count;
            //stack.push_back(2);
        }



        if (book_code == 3) {
            ++soc_count;
            //stack.push_back(3);

        }

        if (book_code == 4) {
            ++eng_count;
            //stack.push_back(4);

        }

        if (book_code == 5) {
            ++philo_count;
            //stack.push_back(5);

        }




    }

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(ffamily, 40);

    //QWidget* recipee = new QWidget;

    QLabel *book_names_title  = new QLabel("Textbooks:");
    book_names_title->setFont(f);
    book_names_title->setStyleSheet("QLabel { font: 20pt;}");

    layout = new QGridLayout;
    layout->addWidget(book_names_title, 0, 0, 1, 1);



    if (bigcplusplus_count != 0) {
        QLabel *bigc_book = new QLabel("Big C++: ");
        bigc_book->setFont(f);
        bigc_book->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(bigc_book, 1, 0, 1, 1);

        bigc_count_display = new QLabel;
        bigc_count_display->setText(QString::number(bigcplusplus_count));
        bigc_count_display->setFont(f);
        bigc_count_display->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(bigc_count_display, 1, 1, 1, 1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/redbook.png");
        pixmap = pixmap.scaled(71,23);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,1,2,1,1, Qt::AlignLeft);


    }


    if (bio_count != 0) {
        QLabel* bio_book = new QLabel("Biology: ");
        bio_book->setFont(f);
        bio_book->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(bio_book, 2, 0, 1, 1);

        bio_count_display = new QLabel;
        bio_count_display->setText(QString::number(bio_count));
        bio_count_display->setFont(f);
        bio_count_display->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(bio_count_display, 2, 1, 1,1);


        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/orangebook.png");
        pixmap = pixmap.scaled(71,23);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,2,2,1,1, Qt::AlignLeft);

    }


    if (chem_count != 0) {
        QLabel* chem_book = new QLabel("Chemistry: ");
        chem_book->setFont(f);
        chem_book->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(chem_book, 3, 0, 1,1);

        chem_count_display = new QLabel;
        chem_count_display->setText(QString::number(chem_count));
        chem_count_display->setFont(f);
        chem_count_display->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(chem_count_display, 3, 1, 1,1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/yellowbook.png");
        pixmap = pixmap.scaled(71,23);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,3,2,1,1, Qt::AlignLeft);
    }


    if (soc_count != 0) {
        QLabel *soc_book = new QLabel("Sociology: ");
        soc_book->setFont(f);
        soc_book->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(soc_book, 4, 0, 1,1);

        soc_count_display = new QLabel;
        soc_count_display->setText(QString::number(soc_count));
        soc_count_display->setFont(f);
        soc_count_display->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(soc_count_display, 4, 1, 1,1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/greenbook.png");
        pixmap = pixmap.scaled(71,23);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,4,2,1,1, Qt::AlignLeft);
    }


    if (eng_count != 0) {
        QLabel *eng_book = new QLabel("English: ");
        eng_book->setFont(f);
        eng_book->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(eng_book, 5, 0, 1,1);

        eng_count_display = new QLabel;
        eng_count_display->setText(QString::number(eng_count));
        eng_count_display->setFont(f);
        eng_count_display->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(eng_count_display, 5, 1, 1,1);

        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/bluebook.png");
        pixmap = pixmap.scaled(71,23);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,5,2,1,1, Qt::AlignLeft);
    }


    if (philo_count != 0) {
        QLabel *philo_book = new QLabel("Philosophy: ");
        philo_book->setFont(f);
        philo_book->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(philo_book, 6, 0, 1,1);

        philo_count_display = new QLabel;
        philo_count_display->setText(QString::number(philo_count));
        philo_count_display->setFont(f);
        philo_count_display->setStyleSheet("QLabel { font: 18pt;}");
       layout->addWidget(philo_count_display, 6, 1,1,1);

       QLabel* book_label = new QLabel;
       QPixmap pixmap(":/spritesheets/purplebook.png");
       pixmap = pixmap.scaled(71,23);
       book_label->setPixmap(pixmap);
       //book_label.setMask(pixmap.mask());

       layout->addWidget(book_label,6,2,1,1, Qt::AlignLeft);
    }


    setLayout(layout);

    //show();



}


//QWidget* Recipe::display_recipe() {



//}

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
                //stack.push_back(0);
            }

            if (book_code == 1) {
                ++bio_count;
                //stack.push_back(1);
            }

            if (book_code == 2) {
                ++chem_count;
                //stack.push_back(2);
            }



            if (book_code == 3) {
                ++soc_count;
                //stack.push_back(3);

            }

            if (book_code == 4) {
                ++eng_count;
                //stack.push_back(4);

            }

            if (book_code == 5) {
                ++philo_count;
                //stack.push_back(5);

            }




        }

        int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
        QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
        QFont f(ffamily, 40);

        //QWidget* recipee = new QWidget;

        QLabel *book_names_title  = new QLabel("Textbooks:");
        book_names_title->setFont(f);
        book_names_title->setStyleSheet("QLabel { font: 20pt;}");

        //layout = new QGridLayout;
        layout->addWidget(book_names_title, 0, 0, 1, 1);



        if (bigcplusplus_count != 0) {
            QLabel *bigc_book = new QLabel("Big C++: ");
            bigc_book->setFont(f);
            bigc_book->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(bigc_book, 1, 0, 1, 1);

            bigc_count_display = new QLabel;
            bigc_count_display->setText(QString::number(bigcplusplus_count));
            bigc_count_display->setFont(f);
            bigc_count_display->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(bigc_count_display, 1, 1, 1, 1);

            QLabel* book_label = new QLabel;
            QPixmap pixmap(":/spritesheets/redbook.png");
            pixmap = pixmap.scaled(71,23);
            book_label->setPixmap(pixmap);
            //book_label.setMask(pixmap.mask());

            layout->addWidget(book_label,1,2,1,1, Qt::AlignLeft);


        }


        if (bio_count != 0) {
            QLabel* bio_book = new QLabel("Biology: ");
            bio_book->setFont(f);
            bio_book->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(bio_book, 2, 0, 1, 1);

            bio_count_display = new QLabel;
            bio_count_display->setText(QString::number(bio_count));
            bio_count_display->setFont(f);
            bio_count_display->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(bio_count_display, 2, 1, 1,1);


            QLabel* book_label = new QLabel;
            QPixmap pixmap(":/spritesheets/orangebook.png");
            pixmap = pixmap.scaled(71,23);
            book_label->setPixmap(pixmap);
            //book_label.setMask(pixmap.mask());

            layout->addWidget(book_label,2,2,1,1, Qt::AlignLeft);

        }


        if (chem_count != 0) {
            QLabel* chem_book = new QLabel("Chemistry: ");
            chem_book->setFont(f);
            chem_book->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(chem_book, 3, 0, 1,1);

            chem_count_display = new QLabel;
            chem_count_display->setText(QString::number(chem_count));
            chem_count_display->setFont(f);
            chem_count_display->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(chem_count_display, 3, 1, 1,1);

            QLabel* book_label = new QLabel;
            QPixmap pixmap(":/spritesheets/yellowbook.png");
            pixmap = pixmap.scaled(71,23);
            book_label->setPixmap(pixmap);
            //book_label.setMask(pixmap.mask());

            layout->addWidget(book_label,3,2,1,1, Qt::AlignLeft);
        }


        if (soc_count != 0) {
            QLabel *soc_book = new QLabel("Sociology: ");
            soc_book->setFont(f);
            soc_book->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(soc_book, 4, 0, 1,1);

            soc_count_display = new QLabel;
            soc_count_display->setText(QString::number(soc_count));
            soc_count_display->setFont(f);
            soc_count_display->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(soc_count_display, 4, 1, 1,1);

            QLabel* book_label = new QLabel;
            QPixmap pixmap(":/spritesheets/greenbook.png");
            pixmap = pixmap.scaled(71,23);
            book_label->setPixmap(pixmap);
            //book_label.setMask(pixmap.mask());

            layout->addWidget(book_label,4,2,1,1, Qt::AlignLeft);
        }


        if (eng_count != 0) {
            QLabel *eng_book = new QLabel("English: ");
            eng_book->setFont(f);
            eng_book->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(eng_book, 5, 0, 1,1);

            eng_count_display = new QLabel;
            eng_count_display->setText(QString::number(eng_count));
            eng_count_display->setFont(f);
            eng_count_display->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(eng_count_display, 5, 1, 1,1);

            QLabel* book_label = new QLabel;
            QPixmap pixmap(":/spritesheets/bluebook.png");
            pixmap = pixmap.scaled(71,23);
            book_label->setPixmap(pixmap);
            //book_label.setMask(pixmap.mask());

            layout->addWidget(book_label,5,2,1,1, Qt::AlignLeft);
        }


        if (philo_count != 0) {
            QLabel *philo_book = new QLabel("Philosophy: ");
            philo_book->setFont(f);
            philo_book->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(philo_book, 6, 0, 1,1);

            philo_count_display = new QLabel;
            philo_count_display->setText(QString::number(philo_count));
            philo_count_display->setFont(f);
            philo_count_display->setStyleSheet("QLabel { font: 18pt;}");
            layout->addWidget(philo_count_display, 6, 1,1,1);

           QLabel* book_label = new QLabel;
           QPixmap pixmap(":/spritesheets/purplebook.png");
           pixmap = pixmap.scaled(71,23);
           book_label->setPixmap(pixmap);
           //book_label.setMask(pixmap.mask());

           layout->addWidget(book_label,6,2,1,1, Qt::AlignLeft);
        }


        setLayout(layout);


}


int Recipe::get_bigc_count() {
    return bigcplusplus_count;
}

int Recipe::get_bio_count() {
    return bio_count;
}

int Recipe::get_chem_count() {
    return chem_count;
}

int Recipe::get_soc_count() {
    return soc_count;
}

int Recipe::get_eng_count() {
    return eng_count;
}

int Recipe::get_philo_count() {
    return philo_count;
}



void Recipe::book_caught(int code) {
    if (code == 0) {
        if (bigcplusplus_count != 0) {
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


}



//still working on the display

//        void books::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
//            QRectF source(0,0,500,161); //image is 500x161
//            painter->drawPixmap(boundingRect(),*biobook, source); //boundingrect is the target in which to draw the book into
//            //painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : scene()->removeItem(this));

//        }

//void Recipe::paint(QPainter *painter, QPixmap* pixmap, const QStyleOptionGraphicsItem *, QWidget *) {
//    QRectF source(0,0,500,161); //image is 500x161
//    painter->drawPixmap(QRectF(0,0,500*0.2,161*0.2),*pixmap, source); //boundingrect is the target in which to draw the book into
//}

//        QRectF books::boundingRect() const{
//            return QRectF(0,0,500*0.2,161*0.2);
//        }

//        QPainter *painter;
//        QRectF source(0,0,500,161);
//        painter->drawPixmap(QRectF(0,0,500*0.2, 161*0.2));


//        void particles::make(){
//              for(auto i = 0; i <row; ++i){ //go through the rows
//                  for(auto n= 0; n<column; ++n){ //go through the columns
//                      oneparticle *one = new oneparticle; //creates a new particle
//                      layout->addWidget(one, i+1, n, Qt::AlignCenter);
//                  }
//              }

//        void oneparticle::paintEvent(QPaintEvent *e){
//            QPainter painter(this);
//            painter.setBrush(QBrush(QColorConstants::Svg::pink));
//            painter.setPen(Qt::white);
//            QRectF rectangle(1, 1, 15, 15);
//            painter.drawEllipse(rectangle);

//        }


//        books* book(0);
//        layout->addItem(book,1,2,1,1);


//        QLabel* book_label = new QLabel();
//        book_label->setScaledContents(true);

//        QPixmap pixmap(":/spritesheets/redbook.png");
//        book_label->setPixmap(pixmap);

//        pixmap = pixmap.scaled(71,23, Qt::KeepAspectRatio);
//        book_label->setPixmap(pixmap);
//        //book_label.setMask(pixmap.mask());

//layout->addWidget(book_label,1,2,1,1, Qt::AlignLeft);
