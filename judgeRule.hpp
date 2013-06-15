#ifndef JUDGERULE_HPP
#define JUDGERULE_HPP

#include "mainwindow.hpp"
#include <vector>
#include <cmath>
//*     包含了所有关于ui的信息
//*     当有新的棋子落下的时候，会调用一次judgeRule::getState(MainWindow*)和judgeRule::Winner()
//*
//*

class judgeRule{

public:
    explicit judgeRule();
    void getState(MainWindow* m);
    const int getWinner() const;
    void chessPlaced(int actX, int actY);

private:
    int Winner;//1--black, 0--white, 2目前还无人获胜
   // static std::vector <int> lastState;
};
#endif // JUDGERULE_HPP
