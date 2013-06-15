#include "judgeRule.hpp"
#include "mainwindow.hpp"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    judgeRule jR;
    w.show();
    while (!w.close()){
        jR.chessPlaced(w.getLastX(), w.getLastY(), w.nowPlayer());

    }
    return a.exec();
}
