#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QMouseEvent>
#include <QPixmap>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    bChess(":/png/chessBlack.png"), wChess(":/png/chessWhite.png"), board(":/png/chess.png"),
    boardState(20,0), colorState(20,0)
{    


    this->setFixedHeight(600);
    this->setFixedWidth(800);
    ui->setupUi(this);

    countTurns = 0;//steps, odd->black, even->white

    //black plays first
    ui->lbPlayerNowPng->setPixmap(bChess);

    connect(ui->btnNewGame, SIGNAL(clicked()), this, SLOT(boardCleaned())) ;
    connect(this, SIGNAL(mouseClicked()), this, SLOT(chessPlaced()));
    qDebug()<<boardState.at(19);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::mousePressEvent(QMouseEvent *m){
    int tempX=m->pos().x();
    int tempY=m->pos().y();
    int nowPlayer;//1--black, 0--white

    actX = (tempX-60)/25;//0--18
    actY = (tempY-65)/25;//0--18

    qDebug()<<"bS[actX]:"<<boardState.at(actX)<<endl;
    qDebug()<<"1<<actY:"<< (1<<actY) <<endl;
    qDebug()<<"suum: "<<(boardState.at(actX)&(1 << actY)) <<endl;
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



    //QDebug debug("cordinate");
    qDebug()<<"cordinate"<<endl;
    qDebug()<<tempX<<' '<<actX<<' '<<endl;
    qDebug()<<tempY<<' '<<actY<<' '<<endl;

    emit mouseClicked();
}

void MainWindow::chessPlaced(){
    qDebug()<<"chessPlaced:"<<countTurns;
}

void MainWindow::boardCleaned(){
    for (int i=0; i<19; i++)
        boardState.at(i)=0;
    update();
}

void MainWindow::paintEvent(QPaintEvent * ev){
    QPainter p(this);
    p.drawPixmap(41,31,board);

//    for (int i=0; i<19; i++){
//        for (int j=0; j<19; j++){
//            int drawX = i*25+65;
//            int drawY = j*25+70;
//            if ((colorState.at(drawX) & (1<<drawY)) == 1){//1--black
//                p.drawPixmap(drawX, drawY, bChess);
//            }
//            else {//0--white
//                p.drawPixmap(drawX, drawY, wChess);
//            }


//        }
//    }
    //qDebug()<<"paintEvent"<<drawX<<' '<<drawY<<endl;
}


