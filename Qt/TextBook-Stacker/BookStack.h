
#ifndef STACK_H
#define STACK_H

#include<QVBoxLayout>
#include<vector>
#include<QPaintEvent>
#include"books.h"
#include<QWidget>
#include"recipe.h"
#include"avatar.h"

class BookStack : public QGraphicsObject {
    Q_OBJECT
public:
    BookStack(avatar& p1);
    void add(books& new_book);
    ~BookStack();
signals:
    void getstack();
public slots:
    void push(int b);
    void updatex(int x);
protected:
    std::vector<books*> bstack;
    //std::vector<int> bstack;
    int height;
    int x_pos;
    size_t bookcount;
    friend class books;
    friend class FallingObject;
    avatar* player;
    //Recipe::Recipe* recipe;
    QVBoxLayout* bkstk;
    friend class Wrapper;
};

#endif // STACK_H

