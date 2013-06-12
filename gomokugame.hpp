#ifndef GOMOKUGAME_HPP
#define GOMOKUGAME_HPP

class gomokuGame
{
public:
    explicit gomokuGame();
    ~gomokuGame();

    //*返回当前玩家————即将落子
    //*奇数表示黑色刚下完，偶数表示白色刚下完
    int nowPlayer();//1 black, 0 white

private:
    size_t countTurns;//当前的回合数，从1开始

    //*利用vetor+二进制的思想存放棋盘和棋子颜色的情况
    //*比如boardState.at(0)==9==8+1
    //*表示第一行的1, 4有落子
    //*颜色的表达也类似
    std::vector<int> boardState;//0 no chess, 1 engaged
    std::vector<int> colorState;//1 black, 0 white


};

#endif // GOMOKUGAME_HPP
