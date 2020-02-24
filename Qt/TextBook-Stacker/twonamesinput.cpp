#include "twonamesinput.h"
#include <QLabel>
#include <QFontDatabase>
#include <QVBoxLayout>

twonamesinput::twonamesinput(QWidget *parent) : QWidget(parent)
{

        QPixmap back(":/bkgnd/textbookbkgndclear.png");
        back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
        QPalette palette;
        palette.setBrush(QPalette::Background, back);
        this->setAutoFillBackground(true);
        this->setPalette(palette);


         int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
         QString family = QFontDatabase::applicationFontFamilies(id).at(0);
         QFont f(family, 40);

        name1Edit = new QLineEdit;
        name1Edit->setPlaceholderText("Name...");
        name1Edit->setFocus();
        name1Edit->setMaxLength(10);
        name1Edit->setFont(f);
        name1Edit->setStyleSheet("QLineEdit{ "
                               "background-color:black;"
                               "border: 2px solid gray;"
                               "border-radius: 10px;"
                               "padding: 0 8px;"
                               "selection-background-color: darkgray;"
                               "font-size: 20px;}"
                               "QLineEdit:focus { "
                               "background-color:white;}");
        name1Edit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        name1Edit->setFixedWidth(400);
        name1Edit->setFixedHeight(100);

        name2Edit = new QLineEdit;
        name2Edit->setPlaceholderText("Name...");
        name2Edit->setFocus();
        name2Edit->setMaxLength(10);
        name2Edit->setFont(f);
        name2Edit->setStyleSheet("QLineEdit{ "
                               "background-color:black;"
                               "border: 2px solid gray;"
                               "border-radius: 10px;"
                               "padding: 0 8px;"
                               "selection-background-color: darkgray;"
                               "font-size: 20px;}"
                               "QLineEdit:focus { "
                               "background-color:white;}");
        name2Edit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
        name2Edit->setFixedWidth(400);
        name2Edit->setFixedHeight(100);


        QLabel * insert = new QLabel("Insert player 1 name:");
        insert->setFont(f);

        QLabel * insert2 = new QLabel("Insert player 2 name:");
        insert2->setFont(f);

        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(insert, 1, Qt::AlignCenter);
        layout->addWidget(name1Edit, 3, Qt::AlignCenter);
        layout->addWidget(insert2, 1, Qt::AlignCenter);
        layout->addWidget(name2Edit, 3, Qt::AlignCenter);
        setLayout(layout);

        connect(name2Edit, SIGNAL(editingFinished()),this, SLOT(namechanged()));
        connect(name2Edit, SIGNAL(editingFinished()), this, SLOT(gotogamewindow()));
    }

    void twonamesinput::namechanged(){
       emit playernames(name1Edit->text(), name2Edit->text());
    }

    void twonamesinput::gotogamewindow(){
        emit gamewindowindex();
    }
