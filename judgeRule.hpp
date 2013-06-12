#ifndef JUDGERULE_HPP
#define JUDGERULE_HPP

#include "mainwindow.hpp"
//*     包含了所有关于ui的信息
//*     当有新的棋子落下的时候，会调用一次judgeRule::getState(MainWindow*)和judgeRule::Winner()
//*
//*

class judgeRule{

public:
    const int getState(MainWindow* m);
    //*     在MainWindow类下我提供了两个public函数
    //*     const std::vector <int> getBoardState() const;
    //*     用于返回当前棋盘某坐标下是否有棋子的信息, 1--有, 0--空
    //*
    //*     const std::vector <int> getColorState() const;
    //*     用于返回某个坐标下的颜色信息, 1--black, 0--white
    //*     你可以在getState中调用他们并且复制到judgeRule类的成员变量里

    //const int Winner();
    //*     然后我再调用Winner输出当前是否有获胜的人
    //*     1--black, 0--white, 这之外的数字表示目前还没有人获胜

    //*     测试的时候为了便于调试，你可以先手动输入棋盘的信息作为测试数据

};
#endif // JUDGERULE_HPP
