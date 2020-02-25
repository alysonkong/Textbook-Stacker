#include "nameinputwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFontDatabase>
#include <QPixmap>

nameinputwindow::nameinputwindow(QWidget *parent) : QWidget(parent)
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

    nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("Name...");
    nameEdit->setFocus();
    nameEdit->setMaxLength(10);
    nameEdit->setFont(f);
    nameEdit->setStyleSheet("QLineEdit{ "
                           "background-color:black;"
                           "border: 2px solid gray;"
                           "border-radius: 10px;"
                           "padding: 0 8px;"
                           "selection-background-color: darkgray;"
                           "font-size: 20px;}"
                           "QLineEdit:focus { "
                           "background-color:white;}");
    nameEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred);
    nameEdit->setFixedWidth(400);
    nameEdit->setFixedHeight(100);


    QLabel * insert = new QLabel("Insert name:");
    insert->setFont(f);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(insert, 5, Qt::AlignCenter);
   // layout->addWidget(frame);
    layout->addWidget(nameEdit, 7, Qt::AlignTop|Qt::AlignHCenter);
    setLayout(layout);

    connect(nameEdit, SIGNAL(editingFinished()),this, SLOT(namechanged()));

    connect(nameEdit, SIGNAL(editingFinished()), this, SLOT(gotosingle_window()));
}

void nameinputwindow::namechanged(){
   emit playername(nameEdit->text());
}

void nameinputwindow::gotosingle_window(){
    emit single_windowindex();
}
