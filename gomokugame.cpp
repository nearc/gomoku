#include "gomokugame.hpp"

gomokuGame::gomokuGame()
{
}


//*返回当前玩家————指已经完成落子的
//*奇数表示黑色刚下完，偶数表示白色刚下完
int gomokuGame::nowPlayer()
{
    return (this->countTurns & 1);//countTurns mod 2
}
