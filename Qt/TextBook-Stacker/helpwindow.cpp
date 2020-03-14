#include "helpwindow.h"
#include<QFontDatabase>
#include<QPixmap>


namespace HelpWindow{

//add pics, maybe screenshots
/**
 * @brief helpwindow::helpwindow() constructor
 */
helpwindow::helpwindow() {

   /** "The object of this game is to move the avatar left and right \n"
                                  "to catch the falling textbooks. The user can move horizontally \n"
                                  "using either the left and right arrow keys or 'A' to go left \n"
                                  "and 'D' to go right. There will be a list displaying which types \n"
                                  "of books and how many of each need to be caught. Avoid catching \n"
                                  "the wrong textbook and getting any 'Fs'!! Good luck"**/


    int id = QFontDatabase::addApplicationFont(":/fonts/Bubble font.ttf");
    QString ffamily = QFontDatabase::applicationFontFamilies(id).at(0);
    QFont f(ffamily, 40);

    QPixmap bkgd(":/bkgnd/textbookbkgndclear.png");
    bkgd = bkgd.scaled(this->size(), Qt::IgnoreAspectRatio); //sets background image to be the size of the window
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgd);
    this->setAutoFillBackground(true);
    this->setPalette(palette);

    main_layout = new QVBoxLayout;
    first_layout = new QHBoxLayout;
    second_layout = new QHBoxLayout;
    third_layout = new QHBoxLayout;
    fourth_layout = new QHBoxLayout;
    fifth_layout = new QHBoxLayout;

    title = new QLabel("Instructions...");
    title->setFont(f);
    first_layout->addWidget(title, 0, Qt::AlignCenter);


    instructions = new QLabel("Press the left\narrow key to\nmove left!");
    instructions->setFont(f);
    instructions->setStyleSheet("QLabel { font: 18pt;}");

    instructions1 = new QLabel("Catch the\nfalling\ntextbooks by\nmoving your\ncharacter\nunder the\ntextbook!\nEach book\n"
                               "adds one\npoint to\nyour score.");
    instructions1->setFont(f);
    instructions1->setStyleSheet("QLabel { font: 18pt;}");

    instructions2 = new QLabel("Avoid the\nfalling 'F'\nletters! If\nyou catch one\nby mistake you\nwill lose\none heart.");
    instructions2->setFont(f);
    instructions2->setStyleSheet("QLabel { font: 18pt;}");

    instructions3 = new QLabel("The recipe is\nshown at the\ntop left\ncorner. It\ntells you\nwhich\ntextbooks to\ncatch and\nhow many of\neach. "
                               "If you\ncatch a\ntextbook\nthat isn't\nin the\nrecipe or\nthat you\ndon't need,\nyou will\nlose one\nheart.");
    instructions3->setFont(f);
    instructions3->setStyleSheet("QLabel { font: 18pt;}");

    instructions4 = new QLabel("If you lose\nall three\nhearts, you\nwill lose the\ngame.");
    instructions4->setFont(f);
    instructions4->setStyleSheet("QLabel { font: 18pt;}");

    instructions5 = new QLabel("Press the\nright arrow\nkey to move\nright!");
    instructions5->setFont(f);
    instructions5->setStyleSheet("QLabel { font: 18pt;}");

    fourth_layout->addWidget(instructions, 0,Qt::AlignCenter);
    fourth_layout->addWidget(instructions1, 0, Qt::AlignCenter);
    fourth_layout->addWidget(instructions2, 0, Qt::AlignCenter);
    fourth_layout->addWidget(instructions3, 0, Qt::AlignCenter);
    fourth_layout->addWidget(instructions4, 0, Qt::AlignCenter);
    fourth_layout->addWidget(instructions5, 0, Qt::AlignCenter);

    QPixmap pic1(":/icons/leftarrow.svg");
    pic1 = pic1.scaled(100,100,Qt::IgnoreAspectRatio); //resized the icon graphics
    pic_Left = new QPushButton();
    QIcon icon(pic1);
    pic_Left->setIcon(icon); //change pushbutton visual into the imported icon
    pic_Left->setIconSize(pic1.rect().size());
    pic_Left->setStyleSheet("QPushButton { border:none;}");

    QPixmap pic1_1(":/icons/left.png");
    pic1_1 = pic1_1.scaled(50,50,Qt::IgnoreAspectRatio); //resized the icon graphics
    pic_left = new QPushButton();
    QIcon icon3(pic1_1);
    pic_left->setIcon(icon3); //change pushbutton visual into the imported icon
    pic_left->setIconSize(pic1_1.rect().size());
    pic_left->setStyleSheet("QPushButton { border:none;}");

    QPixmap pic2(":/icons/rightarrow.svg");
    pic2 = pic2.scaled(100,100,Qt::IgnoreAspectRatio); //resized the icon graphics
    pic_Right = new QPushButton();
    QIcon icon2(pic2);
    pic_Right->setIcon(icon2); //change pushbutton visual into the imported icon
    pic_Right->setIconSize(pic2.rect().size());
    pic_Right->setStyleSheet("QPushButton { border:none;}");

    QPixmap pic1_2(":/icons/right.png");
    pic1_2 = pic1_2.scaled(50,50,Qt::IgnoreAspectRatio); //resized the icon graphics
    pic_right = new QPushButton();
    QIcon icon4(pic1_2);
    pic_right->setIcon(icon4); //change pushbutton visual into the imported icon
    pic_right->setIconSize(pic1_2.rect().size());
    pic_right->setStyleSheet("QPushButton { border:none;}");

    QPixmap book1(":/spritesheets/redbook.png");
    book1 = book1.scaled(500*0.2, 161*0.2,Qt::IgnoreAspectRatio); //resized the icon graphics
    book = new QPushButton();
    QIcon icon5(book1);
    book->setIcon(icon5); //change pushbutton visual into the imported icon
    book->setIconSize(book1.rect().size());
    book->setStyleSheet("QPushButton { border:none;}");

    QPixmap f_letter(":/spritesheets/letter_F.png");
    f_letter = f_letter.scaled(100,100,Qt::IgnoreAspectRatio); //resized the icon graphics
    fletter = new QPushButton();
    QIcon icon6(f_letter);
    fletter->setIcon(icon6); //change pushbutton visual into the imported icon
    fletter->setIconSize(f_letter.rect().size());
    fletter->setStyleSheet("QPushButton { border:none;}");

    QPixmap rec(":/icons/recipe2.png");
    rec = rec.scaled(728*0.2,574*0.2,Qt::IgnoreAspectRatio); //resized the icon graphics
    recipe = new QPushButton();
    QIcon icon7(rec);
    recipe->setIcon(icon7); //change pushbutton visual into the imported icon
    recipe->setIconSize(rec.rect().size());
    recipe->setStyleSheet("QPushButton { border:none;}");

    QPixmap hearts(":/icons/heart.png");
    hearts = hearts.scaled(100,100,Qt::IgnoreAspectRatio); //resized the icon graphics
    heart = new QPushButton();
    QIcon icon8(hearts);
    heart->setIcon(icon8); //change pushbutton visual into the imported icon
    heart->setIconSize(hearts.rect().size());
    heart->setStyleSheet("QPushButton { border:none;}");


    third_layout->addWidget(pic_Left,0,Qt::AlignCenter);
    third_layout->addWidget(book,0,Qt::AlignCenter);
    third_layout->addWidget(fletter,0,Qt::AlignCenter);
    third_layout->addWidget(recipe,0,Qt::AlignCenter);
    third_layout->addWidget(heart,0,Qt::AlignCenter);
    third_layout->addWidget(pic_Right,0,Qt::AlignCenter);


    //second_layout->addWidget(pic_left,0,Qt::AlignCenter);
    //second_layout->addWidget(pic_right,0,Qt::AlignCenter);

    //first_layout->addWidget(pic1_1, 0, Qt::AlignCenter);



    returntomain = new QPushButton("Return to main");
    returntomain->setFont(f);
    returntomain->setStyleSheet("QPushButton{font-size: 24px; color : white; background-color: black; border-style: outset;"
                              "border-width: 2px; border-color: solid yellow;}");
    fifth_layout->addWidget(returntomain,0, Qt::AlignCenter);
    //layout->setAlignment(this, Qt::AlignCenter);

    main_layout->addLayout(first_layout,Qt::AlignCenter);
    //main_layout->addLayout(second_layout, Qt::AlignCenter);
    main_layout->addLayout(third_layout, Qt::AlignCenter);
    main_layout->addLayout(fourth_layout, Qt::AlignCenter);
    main_layout->addLayout(fifth_layout, Qt::AlignCenter);

    setLayout(main_layout);
    connect(returntomain, SIGNAL(clicked()), this, SLOT(return_to_main()));

}


/**
 * @brief helpwindow::return_to_main() is slot that connects back to mainwindow
 */
void helpwindow::return_to_main() {
    emit pressed_main(1);
}


}

