#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <vector>
#include <QPainter>
#include <judgeRule.hpp>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    const std::vector <int> getBoardState() const;
    const std::vector <int> getColorState() const;

    //*返回当前玩家————即将落子
    //*奇数表示黑色刚下完，偶数表示白色刚下完
    int nowPlayer() const;//1 black, 0 white
    int getLastX() const;
    int getLastY() const;
    int getCountTurns() const;
    void someoneWin(const int w);

private:
    //void setFixedHeight(int);
    //void setFixedWidth(int);
    Ui::MainWindow *ui;
    size_t countTurns;//当前的回合数
    size_t totTime;//每人的时间上限

    QPixmap bChess;
    QPixmap wChess;
    QPixmap board;

    //*最近一次落子的坐标
    int actX;
    int actY;

    //*利用vetor+二进制的思想存放棋盘和棋子颜色的情况
    //*比如boardState.at(0)==9==8+1
    //*表示第一行的1, 4有落子
    //*颜色的表达也类似
    std::vector<int> winBoardState;//0 no chess, 1 engaged
    std::vector<int> winColorState;//1 black, 0 white

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void boardCleaned();//用于清空棋盘,开始新局
    //void startNewGame();
   // void chessPlaced();//用于向胜负判断函数传递有新子落下的消息
    void setTimeConstraint(int);
    void countDown();
    void on_btnExit_clicked();
    void timeoutMsg(int);
signals:
    void mouseClicked();
//    void newGameClicked(int);
    void timeoutPlayer(int);
    void oneGameFinished();
};

#endif // MAINWINDOW_HPP
