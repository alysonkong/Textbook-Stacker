#ifndef BOOKS_H
#define BOOKS_H

#include <QGraphicsItem>
#include <QGraphicsScene>
#include <QMediaPlayer>
#include "recipe.h"


/**
 * @brief The books class animates a book image to drop down
 */
class books : public QGraphicsObject
{
    Q_OBJECT
public:
    books(int);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void advance(int phase) override;
    /**
     * @brief getbwidth
     * @return return the bookwidth to be used in drawing the books
     */
    inline
    int getbwidth() const{
        return bookwidth;
    }

    /**
     * @brief getbheight
     * @return return the bookheights to be used in drawing the books
     */
    inline
    int getbheight() const{
        return bookheight;
    }
    ~books();

    QPixmap* getbookpic() const;
signals:
    void emittype(int); //emits the type of book to be checked by the recipe and then added to avatar if correct

private:
    QPixmap* book;
    qreal speed=1;
    int booktype;
    int bookwidth = 500; //fixed x-dimension based on the book png.
    int bookheight = 161; //fixed y-dim based on the book png.

};

#endif // BOOKS_H
