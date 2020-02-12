#ifndef LBOARDWINDOW_H
#define LBOARDWINDOW_H
#include<QWidget>
#include<vector>
#include<string>
#include<QLabel>

namespace Leaderboardwindow {

class leaderboard : public QWidget{
     Q_OBJECT
public:
    leaderboard();

public slots:
    void showLBoard() const;


private:
    std::vector<std::string> namelists;
    QLabel names;
    QLabel lboard;

};

}

#endif // LBOARDWINDOW_H
