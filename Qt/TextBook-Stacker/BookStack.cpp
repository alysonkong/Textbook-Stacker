#include<QCoreApplication>
#include "BookStack.h"

BookStack::BookStack(avatar& p1) : bookcount(0), player(&p1), bkstk(new QVBoxLayout) {}

void BookStack::add(books& new_book) {
    bstack.push_back(new_book.getbooktype());
    ++bookcount;
    bkstk->addWidget(new_book);
    QCoreApplication::processEvents();
    repaint();
}

