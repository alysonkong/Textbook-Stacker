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
    class leaders{
    public:
        leaders(QString n, size_t s): name(n), score(s){}
        QString namescore(){return name+"    " +QString::number(score);}
    private:
        QString name;
        size_t score;
    };

signals:
   void pressedmain(int);

public slots:
    void returntomain();
    void getplayerscore();


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
