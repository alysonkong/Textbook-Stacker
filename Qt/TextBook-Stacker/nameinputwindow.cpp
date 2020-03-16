#include "nameinputwindow.h"
#include <QVBoxLayout>
#include <QLabel>
#include <QFontDatabase>
#include <QPixmap>


/**
 * @brief nameinputwindow::nameinputwindow constructor
 */
nameinputwindow::nameinputwindow(QWidget *parent) : QWidget(parent) {

    QPixmap back(":/bkgnd/textbookbkgndclear.png"); //create pixmap for background image
    back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
    QPalette palette;
    palette.setBrush(QPalette::Background, back); //sets the palette used as the background image
    this->setAutoFillBackground(true);
    this->setPalette(palette); //sets the background as background image

    //add special font
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString family = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(family, 40);

    //create line edit for user to input name
    nameEdit = new QLineEdit;
    nameEdit->setPlaceholderText("Name..."); //sets the placeholder to say Name... before user inputs anything
    nameEdit->setFocus(); //sets the focus of the line edit
    nameEdit->setMaxLength(10); //name cannot be longer than 10 characters
    nameEdit->setFont(f); //sets font
    //modify line edit display
    nameEdit->setStyleSheet("QLineEdit{ "
                           "background-color:black;"
                           "border: 2px solid gray;"
                           "border-radius: 10px;"
                           "padding: 0 8px;"
                           "selection-background-color: darkgray;"
                           "font-size: 20px;}"
                           "QLineEdit:focus { "
                           "background-color:white;}");
    nameEdit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred); //set how large the line edit box will be
    nameEdit->setFixedWidth(400);
    nameEdit->setFixedHeight(100);


    QLabel * insert = new QLabel("Insert name:"); //tells user to insert name
    insert->setFont(f);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(insert, 5, Qt::AlignCenter); //add label to window layout
    layout->addWidget(nameEdit, 7, Qt::AlignTop|Qt::AlignHCenter); //add line edit box to window layout
    setLayout(layout);

    //lets itself know when the user has finished inputting their name to update namechanged()
    connect(nameEdit, SIGNAL(editingFinished()),this, SLOT(namechanged()));
}

/**
 * @brief nameinputwindow::namechanged() slot sends signal to mainwindow of the user input
 */
void nameinputwindow::namechanged(){
   emit playername(nameEdit->text());
}


/**
 * @brief nameinputwindow::gotosingle_window slot sends signal to mainwindow to connect to singleplayer window
 */
void nameinputwindow::gotosingle_window(){
    emit single_windowindex();
}
