#ifndef STACK_H
#define STACK_H

#include<QVBoxLayout>
#include<vector>
#include"books.h"
#include<QWidget>
#include"recipe.h"
#include"avatar.h"

class BookStack : public QGraphicsObject {
    Q_OBJECT
public:
    BookStack(avatar& p1, Recipe::Recipe& r);
    void add(books& new_book);
signals:
    void getstack();
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
    Recipe::Recipe* recipe;
    QVBoxLayout* bkstk;
    friend class Wrapper;
};

#endif // STACK_H
