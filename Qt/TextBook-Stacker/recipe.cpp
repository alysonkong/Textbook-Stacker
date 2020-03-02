#include "recipe.h"
#include <QRandomGenerator>
#include <QFontDatabase>



namespace Recipe {

Recipe::Recipe() {



    //randomly generate a number between 10 and 15 for the total number of books the player needs to catch
    total_books = QRandomGenerator::global()->bounded(10, 16);

    for (int i = 0; i < total_books; ++i) { //stack consists of 10-15 textbooks
        int book_code = QRandomGenerator::global()->bounded(6);

        if (book_code == 0) {
            ++bigcplusplus_count;
            stack.push_back(0);
        }

        if (book_code == 1) {
            ++bio_count;
            stack.push_back(1);
        }

        if (book_code == 2) {
            ++chem_count;
            stack.push_back(2);
        }



        if (book_code == 3) {
            ++soc_count;
            stack.push_back(3);

        }

        if (book_code == 4) {
            ++eng_count;
            stack.push_back(4);

        }

        if (book_code == 5) {
            ++philo_count;
            stack.push_back(5);

        }



    }


}












QWidget* Recipe::display_recipe() {

    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(ffamily, 40);

    QWidget* recipee = new QWidget;

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

        QLabel *bigc_count_display = new QLabel;
        bigc_count_display->setText(QString::number(bigcplusplus_count));
        bigc_count_display->setFont(f);
        bigc_count_display->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(bigc_count_display, 1, 1, 1, 1);

//        void books::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *){
//            QRectF source(0,0,500,161); //image is 500x161
//            painter->drawPixmap(boundingRect(),*biobook, source); //boundingrect is the target in which to draw the book into
//            //painter->setBrush(scene()->collidingItems(this).isEmpty() ? Qt::darkYellow : scene()->removeItem(this));

//        }

//        QRectF books::boundingRect() const{
//            return QRectF(0,0,500*0.2,161*0.2);
//        }

//        QPainter *painter;
//        QRectF source(0,0,500,161);
//        painter->drawPixmap(QRectF(0,0,500*0.2, 161*0.2));



        QLabel* book_label = new QLabel;
        QPixmap pixmap(":/spritesheets/redbook.png");
        pixmap = pixmap.scaled(71,23, Qt::KeepAspectRatio);
        book_label->setPixmap(pixmap);
        //book_label.setMask(pixmap.mask());

        layout->addWidget(book_label,1,2,1,1, Qt::AlignLeft);



    }


    if (bio_count != 0) {
        QLabel* bio_book = new QLabel("Biology: ");
        bio_book->setFont(f);
        bio_book->setStyleSheet("QLabel { font: 18pt;}");
        layout->addWidget(bio_book, 2, 0, 1, 1);

        QLabel *bio_count_display = new QLabel;
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

        QLabel *chem_count_display = new QLabel;
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

        QLabel *soc_count_display = new QLabel;
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

        QLabel *eng_count_display = new QLabel;
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

        QLabel *philo_count_display = new QLabel;
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


    recipee->setLayout(layout);

    return recipee;

}

//void Recipe::paint(QPainter *painter, QPixmap* pixmap, const QStyleOptionGraphicsItem *, QWidget *) {
//    QRectF source(0,0,500,161); //image is 500x161
//    painter->drawPixmap(QRectF(0,0,500*0.2,161*0.2),*pixmap, source); //boundingrect is the target in which to draw the book into
//}




//void Recipe::book_caught(int code) {
//    if (code == 0) {
//        --bigcplusplus_count;
//    }

//    if (code == 1) {
//        --bio_count;
//    }

//    if (code == 2) {
//        --chem_count;
//    }

//    if (code == 3) {
//        --soc_count;
//    }

//    if (code == 4) {
//        --eng_count;
//    }

//    if (code == 5) {
//        --philo_count;
//    }

//    //call display_recipe



//}

}
