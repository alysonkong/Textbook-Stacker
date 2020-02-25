#ifndef TWONAMESINPUT_H
#define TWONAMESINPUT_H

#include <QWidget>
#include <QLineEdit>

/**
 * @brief The twonamesinput class creates the class for the window that allows two players to enter their names. inherits from QWidget
 */
class twonamesinput : public QWidget
{
    Q_OBJECT
public:

    /**
     * @brief twonamesinput constructor for the twonamesinput window
     * @param parent the QWidget parent from which this class inherits from (set to nullptr)
     */
    explicit twonamesinput(QWidget *parent = nullptr);

public slots:
    /**
     * @brief namechanged slot that is called when a name is changed
     */
    void namechanged();
    /**
     * @brief gotogamewindow slot that goes to the game window
     */
    void gotogamewindow();

signals:
    /**
     * @brief playernames signal that signals when the player's names are inputted
     */
    void playernames(QString, QString);
    /**
     * @brief gamewindowindex signal that gives the gamewindowindex (multiplayer window)
     */
    void gamewindowindex();

private:
     QLineEdit *name1Edit; //lineedit for player 1's names
     QLineEdit *name2Edit; //lineedit for player 2's names

};

#endif // TWONAMESINPUT_H
