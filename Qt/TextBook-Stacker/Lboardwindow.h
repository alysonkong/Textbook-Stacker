#ifndef LBOARDWINDOW_H
#define LBOARDWINDOW_H
#include<QWidget>
#include<vector>
#include<string>
#include<QLabel>
#include<QPushButton>
#include<QVBoxLayout>
#include<QStackedWidget>

namespace Leaderboardwindow {

/**
 * @brief The leaderboard class shows the leaderboard and connects to main window
 */
class leaderboard : public QWidget{
     Q_OBJECT
public:
    leaderboard();
    /**
     * @brief The leaders class is a neested class within the leaderboard that holds the score and name of every player
     */
    class leaders{
    public:
        /**
         * @brief leaders constructor for leaders that take in a name and score
         * @param n name of player
         * @param s score of player
         */
        leaders(const QString& n, int s): name(n), score(s){}
        /**
         * @brief namescore converts name and score into a string
         * @return return the name and score
         */
        QString namescore(){return name+"    " +QString::number(score);}
        /**
         * @brief getscore
         * @return the score of the player for comparison with the rest of the list
         */
        int getscore(){ return score;}

    private:
        QString name;
        int score;
    };
    void updatedisplay(const QString&, int);

signals:
   void pressedmain(int);

public slots:
    void returntomain();
    //void getplayerscore(const QString&, int);



private:
    QList<leaders> namelists;
    QLabel* names;
    QLabel* lboard;
    QPushButton* returnmain;
    QGridLayout* layout;
    int index;
    QFont f;

};

}

#endif // LBOARDWINDOW_H
