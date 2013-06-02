#include "mainwindow.hpp"
#include "ui_mainwindow.h"
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

    //black plays first
    ui->lbPlayerNowPng->setPixmap(bChess);


    connect(ui->btnNewGame, SIGNAL(clicked()), this, SLOT(boardCleaned())) ;
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

    timer->start(1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(countDown()));
    connect(this, SIGNAL(timeoutPlayer(int)), this, SLOT(timeoutMsg(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::timeoutMsg(int p){
    char ch;

    if (p==1) ch='A';
        else ch='B';
    QMessageBox msg;
    msg.setText(tr("玩家")+ch+tr("时间到"));
    msg.exec();


}

void MainWindow::countDown(){
    int nowPlayer = countTurns &1;//mod2, 1--black, 0--white;
    int timeR;
    qDebug()<<"countDown: "<<countTurns<<endl;

    if (countTurns>0 && nowPlayer == 0){
        timeR = ui->lcdTimeA->intValue();
        if (timeR>0){
            ui->lcdTimeA->display(timeR-1);
        }
        else{
            emit(timeoutPlayer(0));
        }

    }
    else {
        timeR = ui->lcdTimeB->intValue();
        if (timeR>0){
            ui->lcdTimeB->display(timeR-1);
        }
        else{
            emit(timeoutPlayer(1));
        }
    }
}

void MainWindow::mousePressEvent(QMouseEvent *m){
    int tempX=m->pos().x();
    int tempY=m->pos().y();
    int nowPlayer;//1--black, 0--white

    int actX = (tempX-60)/25;//0--18
    int actY = (tempY-65)/25;//0--18

    if (actX>=0 && actX<=18 && actY>=0 && actY <=18
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

void MainWindow::chessPlaced(){
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
