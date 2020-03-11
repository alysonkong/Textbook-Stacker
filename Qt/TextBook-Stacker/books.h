#ifndef BOOKS_H
#define BOOKS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include "recipe.h"


/**
 * @brief The books class animates a book image to drop down
 */
class books : public QGraphicsObject
{
    Q_OBJECT
public:
    books(int);
    //books(int, Recipe::Recipe*);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void advance(int phase) override;
    int gettype();
    inline
    int getbwidth() const{
        return bookwidth;
    }
    inline
    int getbheight() const{
        return bookheight;
    }
    ~books();

    QPixmap* getbookpic() const;
signals:
    void emittype(int);
    void emitbook(books*);
    //void type_pts(int, int) const;

private:
//    QPixmap* biobook;
//    QPixmap* chembook;
//    QPixmap* philobook;
//    QPixmap* cbook;
//    QPixmap* engbook;
//    QPixmap* socbook;
    QPixmap* book;
    qreal speed=1;
    int booktype;
    int points = 5;
    int bookwidth;
    int bookheight;
    Recipe::Recipe* rec;

    //BookStack* stacktainer = bookstack;
};

#endif // BOOKS_H
