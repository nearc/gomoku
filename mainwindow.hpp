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

    std::vector<int> boardState;//0 no chess, 1 engaged
    std::vector<int> colorState;//1 black, 0 white

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *);

private slots:
    void boardCleaned();
    void chessPlaced();

signals:
    void mouseClicked();

};

#endif // MAINWINDOW_HPP
