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

    nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("Name...");
    nameEdit->setFocus();
    nameEdit->setMaxLength(10);


    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(family, 40);
    QLabel * insert = new QLabel("Insert name:");
    insert->setFont(f);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(insert);
    layout->addWidget(nameEdit);
    setLayout(layout);

    connect(nameEdit, SIGNAL(editingFinished()),
                this, SLOT(namechanged()));

    connect(nameEdit, SIGNAL(editingFinished()),
            this, SLOT(gotogamewindow()));
}

void nameinputwindow::namechanged(){
   emit playername(nameEdit->text());

}

void nameinputwindow::gotogamewindow(){
    emit gamewindowindex();
}
