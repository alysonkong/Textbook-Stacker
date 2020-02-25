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
 * @brief the leaderboard class stores and displays the rankings of the players by points
 */
class leaderboard : public QWidget{
     Q_OBJECT
public:
    /**
     * @brief leaderboard constructor creates the leaderboard and displays it
     */
    leaderboard();

    /**
     * @brief The leaders class holds the names and scores of the leading players
     */
    class leaders{
    public:
        /**
         * @brief the leaders constructor creates a leader with the player's name and score
         * @param n: the name of the player
         * @param s: the score of the player
         */
        leaders(QString n, size_t s): name(n), score(s){}

        /**
         * @brief namescore returns the name and score of the leader
         * @return the name and score of the leader
         */
        QString namescore(){return name+"    " +QString::number(score);}

    private:
        QString name;
        size_t score;
    };


signals:
    /**
    * @brief pressedmain is a signal that the player wants to return to the mainwindow
    */
   void pressedmain(int); //signal to return to mainwindow

public slots:
   /**
     * @brief returntomain returns to the mainwindow, exiting out of the leaderboard
     */
    void returntomain(); //returns to the mainwindow

    /**
     * @brief getplayerscore
     */
    void getplayerscore(); //gets the player's name and score


private:
    std::vector<leaders> namelists;
    QLabel* names;
    QLabel* lboard;
    QPushButton* returnmain;
    QVBoxLayout* layout;
    int index;

};

}

#endif // LBOARDWINDOW_H
