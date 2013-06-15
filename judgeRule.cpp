#include "mainwindow.hpp"
#include "judgeRule.hpp"

//using namespace std;
judgeRule::judgeRule():lastState(20, 0), Winner(2){

}

int judgeRule::Winner()
{
//	int difference;
    size_t row, col;
	int step;
	int count;
	int nColor, tColor;
	int tState;
    //static std::vector<int> LastState;
//    ThisState = m.getBoardState();
//    ThisColor = m.getColorState();
//    for(row=0;row<ThisState.size();row++){
//        if(ThisState[row] != lastState[row])
//			break;
//    }
//    difference = ThisState[row]-lastState[row];
//    lastState = ThisState;

//    log的结果是个浮点数，这里会存在误差，
//    比如log(4096)/log(2)的结果本应该是12,计算得到11。>_<
//    col = log(difference+1)/log(2);
    row = m->getLastX();
    col = m->getLastY();
    nColor = m->nowPlayer();
   // nColor = (ThisColor[row]>>col) & 1;
	count = 0;
    for(step = 1;step<=4;step++){
        tColor = (ThisColor[row-step]>>(col+step)) & 1;
        tState = (ThisState[row-step]>>(col+step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (ThisColor[row+step]>>(col-step)) & 1;
        tState = (ThisState[row+step]>>(col-step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }

	count = 0;
	for(step = 1;step<=4;step++){
        tColor = (ThisColor[row-step]>>(col-step)) & 1;
        tState = (ThisState[row-step]>>(col-step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (ThisColor[row+step]>>(col+step)) & 1;
        tState = (ThisState[row+step]>>(col+step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }
	count = 0;
	for(step = 1;step<=4;step++){
        tColor = (ThisColor[row-step]>>col) & 1;
        tState = (ThisState[row-step]>>col) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (ThisColor[row+step]>>col) & 1;
        tState = (ThisState[row+step]>>col) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }
	count = 0;
	for(step = 1;step<=4;step++){
        tColor = (ThisColor[row]>>(col-step)) & 1;
        tState = (ThisState[row]>>(col-step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (ThisColor[row]>>(col+step)) & 1;
        tState = (ThisState[row]>>(col+step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }
    return 2;
}


void judgeRule::chessPlaced(int actX, int actY, int nP){
    if (actX>=0 && actX<=18 && actY>=0 && actY <=18
            &&((boardState.at(actX)&(1 << actY)) ==0) ){

        boardState.at(actX)+= 1 << actY;

        if (nP == 1){
            colorState.at(actX) |= 1 << actY;//black
        }
        else {
            colorState.at(actX) &= ((1 << 19)-1)- (1<<actY);//white
        }
    }
}

