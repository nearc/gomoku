/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.0.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Game;
    QAction *actionExit;
    QWidget *centralWidget;
    QLabel *lbBoard;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QSpacerItem *verticalSpacer_5;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *lbChessBlack;
    QLabel *lbPlayerA;
    QLCDNumber *lcdTimeA;
    QHBoxLayout *horizontalLayout_2;
    QLabel *lbChessWhite;
    QLabel *lbPlayerB;
    QLCDNumber *lcdTimeB;
    QHBoxLayout *horizontalLayout_3;
    QLabel *lbPlayerNow;
    QLabel *lbPlayerNowPng;
    QSpacerItem *verticalSpacer;
    QFormLayout *formLayout;
    QLabel *lbTime;
    QRadioButton *rbFiveMin;
    QRadioButton *rbFifteenMin;
    QRadioButton *rbTenMin;
    QRadioButton *rbTwentyMin;
    QSpacerItem *verticalSpacer_2;
    QPushButton *btnNewGame;
    QSpacerItem *verticalSpacer_3;
    QPushButton *btnExit;
    QSpacerItem *verticalSpacer_4;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->setEnabled(true);
        MainWindow->resize(800, 600);
        QIcon icon;
        icon.addFile(QStringLiteral(":/png/logo.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setAutoFillBackground(false);
        MainWindow->setAnimated(true);
        actionNew_Game = new QAction(MainWindow);
        actionNew_Game->setObjectName(QStringLiteral("actionNew_Game"));
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        lbBoard = new QLabel(centralWidget);
        lbBoard->setObjectName(QStringLiteral("lbBoard"));
        lbBoard->setGeometry(QRect(41, 31, 500, 500));
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(591, 31, 140, 432));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_5);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        lbChessBlack = new QLabel(layoutWidget);
        lbChessBlack->setObjectName(QStringLiteral("lbChessBlack"));
        lbChessBlack->setPixmap(QPixmap(QString::fromUtf8(":/png/chessBlack.png")));

        horizontalLayout->addWidget(lbChessBlack);

        lbPlayerA = new QLabel(layoutWidget);
        lbPlayerA->setObjectName(QStringLiteral("lbPlayerA"));

        horizontalLayout->addWidget(lbPlayerA);

        lcdTimeA = new QLCDNumber(layoutWidget);
        lcdTimeA->setObjectName(QStringLiteral("lcdTimeA"));
        lcdTimeA->setEnabled(true);

        horizontalLayout->addWidget(lcdTimeA);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        lbChessWhite = new QLabel(layoutWidget);
        lbChessWhite->setObjectName(QStringLiteral("lbChessWhite"));
        lbChessWhite->setPixmap(QPixmap(QString::fromUtf8(":/png/chessWhite.png")));

        horizontalLayout_2->addWidget(lbChessWhite);

        lbPlayerB = new QLabel(layoutWidget);
        lbPlayerB->setObjectName(QStringLiteral("lbPlayerB"));

        horizontalLayout_2->addWidget(lbPlayerB);

        lcdTimeB = new QLCDNumber(layoutWidget);
        lcdTimeB->setObjectName(QStringLiteral("lcdTimeB"));
        lcdTimeB->setEnabled(true);
        lcdTimeB->setSmallDecimalPoint(false);
        lcdTimeB->setSegmentStyle(QLCDNumber::Filled);
        lcdTimeB->setProperty("value", QVariant(0));

        horizontalLayout_2->addWidget(lcdTimeB);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        lbPlayerNow = new QLabel(layoutWidget);
        lbPlayerNow->setObjectName(QStringLiteral("lbPlayerNow"));

        horizontalLayout_3->addWidget(lbPlayerNow);

        lbPlayerNowPng = new QLabel(layoutWidget);
        lbPlayerNowPng->setObjectName(QStringLiteral("lbPlayerNowPng"));

        horizontalLayout_3->addWidget(lbPlayerNowPng);


        verticalLayout->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(verticalLayout);

        verticalSpacer = new QSpacerItem(118, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        lbTime = new QLabel(layoutWidget);
        lbTime->setObjectName(QStringLiteral("lbTime"));

        formLayout->setWidget(0, QFormLayout::LabelRole, lbTime);

        rbFiveMin = new QRadioButton(layoutWidget);
        rbFiveMin->setObjectName(QStringLiteral("rbFiveMin"));

        formLayout->setWidget(1, QFormLayout::LabelRole, rbFiveMin);

        rbFifteenMin = new QRadioButton(layoutWidget);
        rbFifteenMin->setObjectName(QStringLiteral("rbFifteenMin"));

        formLayout->setWidget(1, QFormLayout::FieldRole, rbFifteenMin);

        rbTenMin = new QRadioButton(layoutWidget);
        rbTenMin->setObjectName(QStringLiteral("rbTenMin"));

        formLayout->setWidget(2, QFormLayout::LabelRole, rbTenMin);

        rbTwentyMin = new QRadioButton(layoutWidget);
        rbTwentyMin->setObjectName(QStringLiteral("rbTwentyMin"));

        formLayout->setWidget(2, QFormLayout::FieldRole, rbTwentyMin);


        verticalLayout_2->addLayout(formLayout);

        verticalSpacer_2 = new QSpacerItem(108, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_2);

        btnNewGame = new QPushButton(layoutWidget);
        btnNewGame->setObjectName(QStringLiteral("btnNewGame"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(btnNewGame->sizePolicy().hasHeightForWidth());
        btnNewGame->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnNewGame);

        verticalSpacer_3 = new QSpacerItem(128, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_3);

        btnExit = new QPushButton(layoutWidget);
        btnExit->setObjectName(QStringLiteral("btnExit"));
        sizePolicy.setHeightForWidth(btnExit->sizePolicy().hasHeightForWidth());
        btnExit->setSizePolicy(sizePolicy);

        verticalLayout_2->addWidget(btnExit);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_2->addItem(verticalSpacer_4);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 800, 23));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        mainToolBar->addSeparator();

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\344\272\224\345\255\220\346\243\213", 0));
        actionNew_Game->setText(QApplication::translate("MainWindow", "\346\226\260\346\270\270\346\210\217", 0));
        actionNew_Game->setShortcut(QApplication::translate("MainWindow", "Alt+N", 0));
        actionExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", 0));
        lbBoard->setText(QString());
        lbChessBlack->setText(QString());
        lbPlayerA->setText(QApplication::translate("MainWindow", "\347\216\251\345\256\266A", 0));
        lbChessWhite->setText(QString());
        lbPlayerB->setText(QApplication::translate("MainWindow", "\347\216\251\345\256\266B", 0));
        lbPlayerNow->setText(QApplication::translate("MainWindow", "\345\275\223\345\211\215\347\216\251\345\256\266", 0));
        lbPlayerNowPng->setText(QApplication::translate("MainWindow", "TextLabel", 0));
        lbTime->setText(QApplication::translate("MainWindow", "\346\270\270\346\210\217\346\227\266\351\227\264\357\274\232", 0));
        rbFiveMin->setText(QApplication::translate("MainWindow", "5 \345\210\206\351\222\237", 0));
        rbFifteenMin->setText(QApplication::translate("MainWindow", "15 \345\210\206\351\222\237", 0));
        rbTenMin->setText(QApplication::translate("MainWindow", "10 \345\210\206\351\222\237", 0));
        rbTwentyMin->setText(QApplication::translate("MainWindow", "20 \345\210\206\351\222\237", 0));
        btnNewGame->setText(QApplication::translate("MainWindow", "\346\226\260\346\270\270\346\210\217", 0));
        btnExit->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272\346\270\270\346\210\217", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
