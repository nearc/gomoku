#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include <vector>
#include <QPainter>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:

    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    //void setFixedHeight(int);
    //void setFixedWidth(int);
    Ui::MainWindow *ui;
    size_t countTurns;//当前的回合数
    size_t totTime;//每人的时间上限

    QPixmap bChess;
    QPixmap wChess;
    QPixmap board;

    //*利用vetor+二进制的思想存放棋盘和棋子颜色的情况
    //*比如boardState.at(0)==9==8+1
    //*表示第一行的1, 4有落子
    //*颜色的表达也类似
    std::vector<int> boardState;//0 no chess, 1 engaged
    std::vector<int> colorState;//1 black, 0 white

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void boardCleaned();//用于清空棋盘
    void chessPlaced();//用于向胜负判断函数传递有新子落下的消息
    void setTimeConstraint(int);
    void countDown();
    void on_btnExit_clicked();
    void timeoutMsg(int);
signals:
    void mouseClicked();
    void newGameClicked(int);
    void timeoutPlayer(int);
};

#endif // MAINWINDOW_HPP
