#ifndef WRAPPER_H
#define WRAPPER_H
#include"avatar.h"
#include"BookStack.h"
//#include"recipe.h"

class Wrapper : public QObject {
    Q_OBJECT
public:
    Wrapper(avatar& a, BookStack& bs);
signals:
    void emitcx();
public slots:
   // void compare(BookStack& bs, Recipe::Recipe& r);
private:
    avatar* player;
    BookStack* bookstack;
};

#endif // WRAPPER_H
