#include "mainwindow.hpp"
#include "judgeRule.hpp"
#include <cmath>
//using namespace std;

const int judgeRule::getState(MainWindow* m)
//void judgeRule::getState(MainWindow* m)
{
	int difference;
    size_t row, col;
	int step;
	int count;
	int nColor, tColor;
	int tState;
    static std::vector<int> LastState;
    std::vector<int> ThisState(m->getBoardState());
    std::vector<int> ThisColor(m->getColorState());

    //ThisState = m.getBoardState();
    //ThisColor = m.getColorState();
    for(row=0;row<ThisState.size();row++){
		if(ThisState[row] != LastState[row])
			break;
    }
	difference = ThisState[row]-LastState[row];
	col = log(difference)/log(2);
	nColor = (ThisColor[row]>>col)%2;
	count = 0;
	for(step = 1;step<=4;step++){ //
		tColor = (ThisColor[row-step]>>(col+step))%2;
        tState = (ThisState[row-step]>>(col+step))%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
		tColor = (ThisColor[row+step]>>(col-step))%2;
		tState = (ThisState[row+step]>>(col-step))%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	if(count >= 4)
		return nColor;
	count = 0;
	for(step = 1;step<=4;step++){
		tColor = (ThisColor[row-step]>>(col-step))%2;
		tState = (ThisState[row-step]>>(col-step))%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
		tColor = (ThisColor[row+step]>>(col+step))%2;
		tState = (ThisState[row+step]>>(col+step))%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	if(count >= 4)
		return nColor;
	count = 0;
	for(step = 1;step<=4;step++){
		tColor = (ThisColor[row-step]>>col)%2;
		tState = (ThisState[row-step]>>col)%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
		tColor = (ThisColor[row+step]>>col)%2;
		tState = (ThisState[row+step]>>col)%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	if(count >= 4)
		return nColor;
	count = 0;
	for(step = 1;step<=4;step++){
		tColor = (ThisColor[row]>>(col-step))%2;
		tState = (ThisState[row]>>(col-step))%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	for(step = 1;step<=4;step++){
		tColor = (ThisColor[row]>>(col+step))%2;
		tState = (ThisState[row]>>(col+step))%2;
		if(tColor == nColor && tState == 1)
			count++;
		else break;
	}
	if(count >= 4)
		return nColor;
	return 2;
}

