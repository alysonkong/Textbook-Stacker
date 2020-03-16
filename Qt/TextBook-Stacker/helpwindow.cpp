#include "helpwindow.h"
#include<QFontDatabase>
#include<QPixmap>

//namepace for HelpWindow
namespace HelpWindow
{

/**
 * @brief helpwindow::helpwindow() constructor
 */
helpwindow::helpwindow()
{
    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf"); //sets id to the font we want (Bubble Font)
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0); //creates a string that stores the family id
    QFont f(ffamily, 40); //creates a font with the family id and point size

    QPixmap bkgd(":/bkgnd/textbookbkgndclear.png"); //creates a pixmap for the background with our image
    bkgd = bkgd.scaled(this->size(), Qt::IgnoreAspectRatio); //sets background image to be the size of the window
    QPalette palette; //creates a palette
    palette.setBrush(QPalette::Background, bkgd); //sets brush of palette to be the background
    this->setAutoFillBackground(true); //auto fills background
    this->setPalette(palette); //sets helpwindow's palette to our palette that we created

    //creates the gridlayout we need to format our helpwindow
    layout = new QGridLayout;

    //creates title label with our font
    title = new QLabel("Instructions...");
    title->setFont(f);
    title->setStyleSheet("QLabel { color: white;}");

    //creates label for the instructions with our font
    instructions = new QLabel("❉ Catch the textbooks that are fall from the \nsky by moving your avatar left or right with \nthe left and right "
                              "arrow keys or the 'a' and \n'd' letter keys!\n"
                              "❉ You will have to complete the recipe shown \nin the upper left-hand corner before moving \nonto the next round. If you "
                              "catch a textbook \nthat is not listed by the current recipe or a \nfalling 'F' letter, you will lose a heart ❤️\n"
                              "❉ Lose all three hearts and you lose the game! \nGood Luck!");
    instructions->setFont(f);
    instructions->setStyleSheet("QLabel { font: 24pt;}"); //sets font size to 24pt

    //creates pixmap for the avatar instructions image
    QPixmap pic1(":/icons/avatarinstruct.png");
    pic1 = pic1.scaled(213*1.2,138*1.2,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates button to display the avatar instructions icon
    avatar_instruct = new QPushButton();
    QIcon icon(pic1); //creates new icon for the button
    avatar_instruct->setIcon(icon); //change pushbutton visual into the imported icon
    avatar_instruct->setIconSize(pic1.rect().size()); //sets icon's size to the size of the pixmap
    avatar_instruct->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //creates pixmap for the checkmark book image
    QPixmap book1(":/icons/checkmark_book.png");
    book1 = book1.scaled(539*0.5, 365*0.5,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates new button to display the checkmark book icon
    book = new QPushButton();
    QIcon icon5(book1); //creates new icon for the button
    book->setIcon(icon5); //change pushbutton visual into the imported icon
    book->setIconSize(book1.rect().size()); //sets icon's size to the size of the pixmap
    book->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //creates pixmap for the xmark f image
    QPixmap f_letter(":/icons/xmark_f.png");
    f_letter = f_letter.scaled(509*0.4,365*0.4,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates new button to display the xmark f icon
    fletter = new QPushButton();
    QIcon icon6(f_letter); //creates new icon for the button
    fletter->setIcon(icon6); //change pushbutton visual into the imported icon
    fletter->setIconSize(f_letter.rect().size()); //sets icon's size to the size of the pixmap
    fletter->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //creates pixmap for the recipe image
    QPixmap rec(":/icons/recipe2.png");
    rec = rec.scaled(728*0.5,574*0.5,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates new button to display the recipe icon
    recipe = new QPushButton();
    QIcon icon7(rec); //creates new icon for the button
    recipe->setIcon(icon7); //change pushbutton visual into the imported icon
    recipe->setIconSize(rec.rect().size()); //sets icon's size to the size of the pixmap
    recipe->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //adds the above buttons to the gridlayout to give the desired interface
    layout->addWidget(title, 0, 0, 1, -1, Qt::AlignCenter);
    layout->addWidget(recipe,1,0, 2, 1,Qt::AlignCenter);
    layout->addWidget(instructions,1,1, 2, 2, Qt::AlignCenter);
    layout->addWidget(avatar_instruct,3, 0, 2, 1, Qt::AlignCenter);
    layout->addWidget(book,3, 1, 2, 1, Qt::AlignCenter);
    layout->addWidget(fletter,3, 2, 2, 1,Qt::AlignCenter);

    //creates new button to allow the user to return to main menu
    returntomain = new QPushButton("Return to main");
    returntomain->setFont(f); //sets font of the button to our font
    returntomain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                              "border-width: 2px; padding: 6px; border-color: solid yellow;}"); //customizes button's stylesheet


    layout->addWidget(returntomain,6, 0, 1, -1, Qt::AlignRight);

    setLayout(layout);

    /**
     * @brief connect the returntomani button with the signal clicked to the helpwindow's signal return_to_main to allow the user to return
     * to the main menu
     */
    connect(returntomain, SIGNAL(clicked()), this, SLOT(return_to_main()));

}


/**
 * @brief helpwindow::return_to_main() is slot that connects back to mainwindow
 */
void helpwindow::return_to_main() {
    emit pressed_main(1);
}


}

