#ifndef BOOKS_H
#define BOOKS_H

#include <QGraphicsItem>
#include <QGraphicsScene>


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
    void gettype_pts();


public slots:
    void getbooktype();
   // bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode = Qt::IntersectsItemShape) const override;

signals:
    void emittype(int);
    void emitpts(int);
    //void type_pts(int, int) const;

private:
    QPixmap* biobook;
    QPixmap* chembook;
    QPixmap* philobook;
    QPixmap* cbook;
    QPixmap* engbook;
    QPixmap* socbook;
    QPixmap* book;
    qreal speed=1;
    int booktype = 1;
    int points = 5;
    //BookStack* stacktainer = bookstack;
};

#endif // BOOKS_H
