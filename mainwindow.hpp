#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QPainter>
#include <vector>

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
    size_t countTurns;

    QPixmap bChess;
    QPixmap wChess;
    QPixmap board;
    QPainter paint;

    int actX;
    int actY;

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

signals:
    void mouseClicked();

};

#endif // MAINWINDOW_HPP
