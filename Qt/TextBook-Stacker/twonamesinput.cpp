#include "twonamesinput.h"
#include <QLabel>
#include <QFontDatabase>
#include <QVBoxLayout>

/**
 * @brief twonamesinput::twonamesinput implementation for the twonamesinput constructor
 * @param parent parent QWidget from which this class inherits
 */
twonamesinput::twonamesinput(QWidget *parent) : QWidget(parent)
{

        QPixmap back(":/bkgnd/textbookbkgndclear.png"); //chooses the background image we want for this window
        back = back.scaled(this->size(), Qt::IgnoreAspectRatio); //set background image to size of window, ignore aspect ratio of orig. pic
        QPalette palette; //defiens a palette
        palette.setBrush(QPalette::Background, back); //sets the brush to the background image
        this->setAutoFillBackground(true); //fills the entire background
        this->setPalette(palette); //sets window's palette to our palette


         int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //chooses font id
         QString family = QFontDatabase::applicationFontFamilies(id).at(0); //chooses font family
         QFont f(family, 40); //chooses specific font from font id and font family

        name1Edit = new QLineEdit; //initializes lineedit for player 1
        name1Edit->setPlaceholderText("Name..."); //sets placeholder text
        name1Edit->setFocus(); //focuses the keyboard input to this widget
        name1Edit->setMaxLength(10); //sets maxlength to 10
        name1Edit->setFont(f); //sets font to the font we chose above
        name1Edit->setStyleSheet("QLineEdit{ "
                               "background-color:black;"
                               "border: 2px solid gray;"
                               "border-radius: 10px;"
                               "padding: 0 8px;"
                               "selection-background-color: darkgray;"
                               "font-size: 20px;}"
                               "QLineEdit:focus { "
                               "background-color:white;}"); //sets the style sheet to our preference
        name1Edit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred); //sets size policy
        name1Edit->setFixedWidth(400); //sets width
        name1Edit->setFixedHeight(100); //sets height

        name2Edit = new QLineEdit; //initializes lineedit for player 2
        name2Edit->setPlaceholderText("Name..."); //sets placeholder text
        name2Edit->setFocus(); //focuses the keyboard input to this widget
        name2Edit->setMaxLength(10); //sets maxlength to 10
        name2Edit->setFont(f); //sets font to the font we chose above
        name2Edit->setStyleSheet("QLineEdit{ "
                               "background-color:black;"
                               "border: 2px solid gray;"
                               "border-radius: 10px;"
                               "padding: 0 8px;"
                               "selection-background-color: darkgray;"
                               "font-size: 20px;}"
                               "QLineEdit:focus { "
                               "background-color:white;}"); //sets the style sheet to our preference
        name2Edit->setSizePolicy(QSizePolicy::Ignored, QSizePolicy::Preferred); //sets size policy
        name2Edit->setFixedWidth(400); //sets width
        name2Edit->setFixedHeight(100); //sets height


        QLabel * insert = new QLabel("Insert player 1 name:"); //creates label for player 1's name
        insert->setFont(f); //sets font to our font

        QLabel * insert2 = new QLabel("Insert player 2 name:"); //creates label for player 2's name
        insert2->setFont(f); //sets font to our font

        QVBoxLayout *layout = new QVBoxLayout; //creates vertical layout

        /**
          adds widgets to our layout
          **/
        layout->addWidget(insert, 1, Qt::AlignCenter);
        layout->addWidget(name1Edit, 3, Qt::AlignCenter);
        layout->addWidget(insert2, 1, Qt::AlignCenter);
        layout->addWidget(name2Edit, 3, Qt::AlignCenter);

        setLayout(layout); //sets window's layout to our layou

        connect(name2Edit, SIGNAL(editingFinished()),this, SLOT(namechanged())); //makes it so once editing is finished the slot namechanged is called
        connect(name2Edit, SIGNAL(editingFinished()), this, SLOT(gotogamewindow())); //makes it so once editing is finished the slot gotowindow is called
    }

/**
     * @brief twonamesinput::namechanged emits signal of the two player's names
     */
    void twonamesinput::namechanged(){
       emit playernames(name1Edit->text(), name2Edit->text());
    }

    /**
     * @brief twonamesinput::gotogamewindow emits signal that we want to go to the game window
     */
    void twonamesinput::gotogamewindow(){
        emit gamewindowindex();
    }
