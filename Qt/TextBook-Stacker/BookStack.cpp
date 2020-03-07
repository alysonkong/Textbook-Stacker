
#include<QCoreApplication>
#include "BookStack.h"
#include<algorithm>

BookStack::BookStack(avatar& p1) : bookcount(0), player(&p1), bkstk(new QVBoxLayout) {}

BookStack::~BookStack() {
    auto delete_books = [](books* ob) {delete ob; ob = nullptr; };
    for_each(bstack.begin(), bstack.end(), delete_books);
}

void BookStack::push(int b) {
    books* nb = new books(b);
    bstack.push_back(nb);
}

void BookStack::updatex(int x) {
    x_pos = x;
}

void BookStack::add(books& new_book) {
    QObject::connect(&new_book, &books::emittype, this, &BookStack::push);
   // QObject::connect(this->player, &avatar::emitcx, this, &BookStack::updatex);
    //bstack.push_back(new_book.emittype(int));
    //bookcount = player->getscore();
    //bkstk->addWidget(new_book);
    QCoreApplication::processEvents();
    //repaint();
}
