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

class leaderboard : public QStackedWidget{
     Q_OBJECT
public:
    leaderboard();

signals:
    void pressedmain(int index);

public slots:
    void returntomain();


private:
    std::vector<std::string> namelists;
    QLabel* names;
    QLabel* lboard;
    QPushButton* returnmain;
    QVBoxLayout* layout;
    int index;

};

}

#endif // LBOARDWINDOW_H
