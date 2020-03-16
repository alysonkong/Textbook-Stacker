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

    //creates the layouts we need to format our helpwindow
    main_layout = new QVBoxLayout;
    first_layout = new QHBoxLayout;
    second_layout = new QHBoxLayout;
    third_layout = new QHBoxLayout;
    fourth_layout = new QHBoxLayout;

    //creates title label with our font
    title = new QLabel("Instructions...");
    title->setFont(f);

    //creates label for the instructions with our font
    instructions = new QLabel("Catch the textbooks that fall from the sky by\nmoving your avatar left or right with the left and\nright "
                              "arrow keys or the 'a' and 'd' letter keys! "
                              "You\nwill have to complete the recipe shown in the upper\nleft-hand corner before moving onto the next round.\nIf you "
                              "catch a textbook that is not required by the\ncurrent recipe or a falling 'F' letter, you will lose\na heart. "
                              "Lose all three hearts and you lose the\ngame! Good Luck!");
    instructions->setFont(f);
    instructions->setStyleSheet("QLabel { font: 24pt;}"); //sets font size to 24pt

    //creates pixmap for the avatar instructions image
    QPixmap pic1(":/icons/avatarinstruct.png");
    pic1 = pic1.scaled(275,275,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates button to display the avatar instructions icon
    avatar_instruct = new QPushButton();
    QIcon icon(pic1); //creates new icon for the button
    avatar_instruct->setIcon(icon); //change pushbutton visual into the imported icon
    avatar_instruct->setIconSize(pic1.rect().size()); //sets icon's size to the size of the pixmap
    avatar_instruct->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //creates pixmap for the checkmark book image
    QPixmap book1(":/icons/checkmark_book.png");
    book1 = book1.scaled(150, 250,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates new button to display the checkmark book icon
    book = new QPushButton();
    QIcon icon5(book1); //creates new icon for the button
    book->setIcon(icon5); //change pushbutton visual into the imported icon
    book->setIconSize(book1.rect().size()); //sets icon's size to the size of the pixmap
    book->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //creates pixmap for the xmark f image
    QPixmap f_letter(":/icons/xmark_f.png");
    f_letter = f_letter.scaled(200,200,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates new button to display the xmark f icon
    fletter = new QPushButton();
    QIcon icon6(f_letter); //creates new icon for the button
    fletter->setIcon(icon6); //change pushbutton visual into the imported icon
    fletter->setIconSize(f_letter.rect().size()); //sets icon's size to the size of the pixmap
    fletter->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //creates pixmap for the recipe image
    QPixmap rec(":/icons/recipe2.png");
    rec = rec.scaled(250,250,Qt::IgnoreAspectRatio); //resized the icon graphics

    //creates new button to display the recipe icon
    recipe = new QPushButton();
    QIcon icon7(rec); //creates new icon for the button
    recipe->setIcon(icon7); //change pushbutton visual into the imported icon
    recipe->setIconSize(rec.rect().size()); //sets icon's size to the size of the pixmap
    recipe->setStyleSheet("QPushButton { border:none;}"); //removes border from the button

    //adds the above puttons to their respective layouts to give the desired interface
    first_layout->addWidget(title, 0, Qt::AlignCenter);
    third_layout->addWidget(avatar_instruct,0,Qt::AlignCenter);
    third_layout->addWidget(book,0,Qt::AlignCenter);
    third_layout->addWidget(fletter,0,Qt::AlignCenter);
    second_layout->addWidget(recipe,0,Qt::AlignCenter);
    second_layout->addWidget(instructions, 0, Qt::AlignCenter);

    //creates new button to allow the user to return to main menu
    returntomain = new QPushButton("Return to main");
    returntomain->setFont(f); //sets font of the button to our font
    returntomain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                              "border-width: 2px; border-color: solid yellow;}"); //customizes button's stylesheet

    //adds this button to the corresponding layout
    fourth_layout->addWidget(returntomain,0, Qt::AlignRight);

    //adds the layouts to the main layout
    main_layout->addLayout(first_layout,Qt::AlignCenter);
    main_layout->addLayout(second_layout, Qt::AlignCenter);
    main_layout->addLayout(third_layout, Qt::AlignCenter);
    main_layout->addLayout(fourth_layout, Qt::AlignCenter);

    //sets helpwindow's layout to the main_layout
    setLayout(main_layout);

    /**
     * @brief connect the returntomani button with the signal clicked to the helpwindow's slot return_to_main to allow the user to return
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

