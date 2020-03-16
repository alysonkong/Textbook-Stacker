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
    class leaders{ //technically can hold
    public:
        leaders(const QString& n, int s): name(n), score(s){}
        QString namescore(){return name+"    " +QString::number(score);}
        int getscore(){ return score;}
       // QString getname(){return name;}
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
    QVBoxLayout* layout;
    int index;
    QFont f;

};

}

#endif // LBOARDWINDOW_H
