#ifndef JUDGERULE_HPP
#define JUDGERULE_HPP

#include <vector>
#include <cmath>
//*     包含了所有关于ui的信息
//*     当有新的棋子落下的时候，会调用一次judgeRule::getState(MainWindow*)和judgeRule::Winner()
//*
//*

class judgeRule{

public:
    explicit judgeRule();
    //void getState(MainWindow* m);

    //判断当前是否已经有人获胜
    //1--black, 0--white, 2目前还无人获胜
    //row, col是最后一次的的坐标
    //nColor 表示当前玩家
    int Winner(int row=0, int col=0, int nColor=0);
    //const int getWinner() const;

    //接收有棋子落下的信息
    //更新boardState 和 colorState
    void chessPlaced(int rst, int actX, int actY, int nP);

private:
    //int Winner;
    static std::vector<int> boardState;//0 no chess, 1 engaged
    static std::vector<int> colorState;//1 black, 0 white

};
#endif // JUDGERULE_HPP
