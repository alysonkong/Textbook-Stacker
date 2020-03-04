#include<QCoreApplication>
#include "BookStack.h"

BookStack::BookStack(avatar& p1) : bookcount(0), player(&p1), bkstk(new QVBoxLayout) {}

void BookStack::push(int nb) {
    bstack.push_back(nb);
}
void BookStack::add(books& new_book) {
    QObject::connect(&new_book, &books::emittype, this, &BookStack::push);
    //bstack.push_back(new_book.emittype(int));
    ++bookcount;
    //bkstk->addWidget(new_book);
    QCoreApplication::processEvents();
    repaint();
}

