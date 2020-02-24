#ifndef BOOKS_H
#define BOOKS_H

#include <QGraphicsItem>


/**
 * @brief The books class animates a book image to drop down
 */
class books : public QGraphicsItem
{
public:
    books();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
    void advance(int phase) override;

private:
    QPixmap* book;
    qreal speed=1;
};

#endif // BOOKS_H
