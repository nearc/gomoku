#include "judgeRule.hpp"

//using namespace std;
judgeRule::judgeRule()
{
}

std::vector<int> judgeRule::boardState(20, 0);
std::vector<int> judgeRule::colorState(20, 0);

int judgeRule::Winner(int row, int col, int nColor)
{
	int step;
	int count;
    int tColor;
	int tState;

	count = 0;
    for(step = 1;step<=4;step++){
        tColor = (colorState[row-step]>>(col+step)) & 1;
        tState = (boardState[row-step]>>(col+step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (colorState[row+step]>>(col-step)) & 1;
        tState = (boardState[row+step]>>(col-step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }

	count = 0;
	for(step = 1;step<=4;step++){
        tColor = (colorState[row-step]>>(col-step)) & 1;
        tState = (boardState[row-step]>>(col-step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (colorState[row+step]>>(col+step)) & 1;
        tState = (boardState[row+step]>>(col+step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }
	count = 0;
	for(step = 1;step<=4;step++){
        tColor = (colorState[row-step]>>col) & 1;
        tState = (boardState[row-step]>>col) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (colorState[row+step]>>col) & 1;
        tState = (boardState[row+step]>>col) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }
	count = 0;
	for(step = 1;step<=4;step++){
        tColor = (colorState[row]>>(col-step)) & 1;
        tState = (boardState[row]>>(col-step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
        tColor = (colorState[row]>>(col+step)) & 1;
        tState = (boardState[row]>>(col+step)) & 1;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
    if(count >= 4){
        return nColor;
    }
    return 2;
}


void judgeRule::chessPlaced(int rst, int actX, int actY, int nP){
    if (rst==0){//countTurns = 0;
        for (int i=0; i<20 ; i++)
            boardState.at(i) = 0;
    }

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

