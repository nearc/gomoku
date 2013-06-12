#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "judgeRule.hpp"

#include <QDebug>
#include <QMouseEvent>
#include <QPixmap>
#include <QSignalMapper>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    bChess(":/png/chessBlack.png"), wChess(":/png/chessWhite.png"), board(":/png/chess.png"),
    boardState(20,0), colorState(20,0)
{    
    QSignalMapper *m = new QSignalMapper(this);
    QTimer *timer = new QTimer(this);

    this->setFixedHeight(600);
    this->setFixedWidth(800);
    ui->setupUi(this);
    countTurns = 0;
    totTime = 0;//never played once

    //black plays first
    ui->lbPlayerNowPng->setPixmap(bChess);

    timer->setInterval(1000);

    connect(ui->btnNewGame, SIGNAL(clicked()), this, SLOT(boardCleaned())) ;
    connect(ui->btnNewGame, SIGNAL(clicked()), timer, SLOT(start()));
    //connect(ui->btnNewGame, SIGNAL(clicked()), this, SLOT(startNewGame()));
    connect(this, SIGNAL(mouseClicked()), this, SLOT(chessPlaced()));

    //set timeConstraint
    connect(ui->rbFiveMin, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->rbFiveMin, 1);
    connect(ui->rbTenMin, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->rbTenMin, 2);
    connect(ui->rbFifteenMin, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->rbFifteenMin, 3);
    connect(ui->rbTwentyMin, SIGNAL(clicked()), m, SLOT(map()));
    m->setMapping(ui->rbTwentyMin, 4);
    connect(m, SIGNAL(mapped(int)), this , SLOT(setTimeConstraint(int)));


    connect(timer, SIGNAL(timeout()), this, SLOT(countDown()));
    connect(this, SIGNAL(timeoutPlayer(int)), this, SLOT(timeoutMsg(int)));
    connect(this, SIGNAL(oneGameFinished()), this, SLOT(boardCleaned()));
    connect(this, SIGNAL(oneGameFinished()), timer, SLOT(stop()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

const std::vector<int> MainWindow::getBoardState() const
{
    return boardState;
}

const std::vector<int> MainWindow::getColorState() const
{
    return colorState;
}



//输出某玩家时间到的对话框
void MainWindow::timeoutMsg(int p){
    char ch;

    if (p==1) ch='B';
        else ch='A';
    QMessageBox msg;
    msg.setText(tr("玩家")+ch+tr("时间到"));
    msg.exec();
    emit(oneGameFinished());
}

//倒计时模块，产生当前具体哪个玩家时间到的信号
void MainWindow::countDown(){
    int nowPlayer = countTurns &1;//mod2, 1--black, 0--white;
    int timeRA, timeRB;
    qDebug()<<"countDown: "<<countTurns<<endl;
    timeRA = ui->lcdTimeA->intValue();
    timeRB = ui->lcdTimeB->intValue();

    if (timeRA>0 || timeRB>0){
        if (nowPlayer == 0){
            if (timeRA>0){
                ui->lcdTimeA->display(timeRA-1);
            }
            else{
                emit(timeoutPlayer(0));
            }

        }
        else {
            if (timeRB>0){
                ui->lcdTimeB->display(timeRB-1);
            }
            else{
                emit(timeoutPlayer(1));
            }
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *m){
    int tempX=m->pos().x();
    int tempY=m->pos().y();
    int nowPlayer;//1--black, 0--white

    int actX = (tempX-60)/25;//0--18
    int actY = (tempY-65)/25;//0--18

    if (totTime>0 && actX>=0 && actX<=18 && actY>=0 && actY <=18
            &&((boardState.at(actX)&(1 << actY)) ==0) ){

        boardState.at(actX)+= 1 << actY;

        countTurns++;
        nowPlayer = countTurns & 1;//mod 2, 1--black, 0--white;
        if (nowPlayer ==1){
            colorState.at(actX) |= 1 << actY;//black
            update();
            ui->lbPlayerNowPng->setPixmap(wChess);//next->>white
        }
        else {
            colorState.at(actX) &= ((1 << 19)-1)- (1<<actY);//white
            ui->lbPlayerNowPng->setPixmap(bChess);//next->>black
            update();
        }

    }

    emit mouseClicked();
}

//当前有新的棋子落下，将更新的信息传给胜负判断的函数
void MainWindow::chessPlaced(){
    judgeRule jr;
    int Winner;

    Winner = jr.getState(this);
    qDebug()<<"chessPlaced:"<<Winner;
    qDebug()<<"chessPlaced:"<<countTurns;
}

void MainWindow::setTimeConstraint(int t){
    qDebug()<<"setTimeConstraint"<<t<<endl;
    totTime = t*300;//sec
}

void MainWindow::boardCleaned(){
    for (int i=0; i<19; i++)
        boardState.at(i)=0;
    for (int i=0; i<19; i++)
        colorState.at(i)=0;
    countTurns = 0;

    ui->lbPlayerNowPng->setPixmap(bChess);
    ui->lcdTimeA->display(int(totTime));
    ui->lcdTimeB->display(int(totTime));

    update();
    //qDebug()<<"newGameClicker "<<totTime*1000;
}

void MainWindow::paintEvent(QPaintEvent * ev){
    QPainter p(this);
    p.drawPixmap(41,31,board);

    ev->accept();

    for (int i=0; i<19; i++){
        for (int j=0; j<19; j++){
            int drawX = i*25+65;
            int drawY = j*25+70;
            if (((boardState.at(i)&(1 << j)) !=0)){//确定当前位置有落子
                if ((colorState.at(i) & (1<<j)) !=0){//1--black
                    p.drawPixmap(drawX, drawY, bChess);
                }
                else {//0--white
                    p.drawPixmap(drawX, drawY, wChess);
                }
            }
        }
    }
}



void MainWindow::on_btnExit_clicked()
{
    this->close();
}
