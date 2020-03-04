#ifndef STACK_H
#define STACK_H

#include<QVBoxLayout>
#include<vector>
#include"books.h"
#include<QWidget>
#include"avatar.h"

class BookStack : public QWidget {
    Q_OBJECT
public:
    BookStack(avatar& p1);
    void add(books& new_book);
public slots:
    void push(int nb);
protected:
    //vector<books*> bstack; //since books now disappear when caught, no need for vector to hold books themselves, only booktype
    std::vector<int> bstack;
    //int height;
    size_t bookcount;
    friend class books;
    friend class FallingObject;
    avatar* player;
    QVBoxLayout* bkstk;
};

#endif // STACK_H
