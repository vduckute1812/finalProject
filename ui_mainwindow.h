/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLabel *firstCam;
    QLabel *secondCam;
    QPushButton *getObject;
    QPlainTextEdit *plainTextEdit;
    QLabel *thirdImg;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(728, 511);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        firstCam = new QLabel(centralWidget);
        firstCam->setObjectName(QStringLiteral("firstCam"));
        firstCam->setGeometry(QRect(20, 20, 341, 221));
        firstCam->setAutoFillBackground(true);
        secondCam = new QLabel(centralWidget);
        secondCam->setObjectName(QStringLiteral("secondCam"));
        secondCam->setGeometry(QRect(370, 20, 341, 221));
        secondCam->setAutoFillBackground(true);
        getObject = new QPushButton(centralWidget);
        getObject->setObjectName(QStringLiteral("getObject"));
        getObject->setGeometry(QRect(130, 420, 121, 31));
        plainTextEdit = new QPlainTextEdit(centralWidget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        plainTextEdit->setGeometry(QRect(390, 370, 291, 51));
        thirdImg = new QLabel(centralWidget);
        thirdImg->setObjectName(QStringLiteral("thirdImg"));
        thirdImg->setGeometry(QRect(10, 260, 191, 131));
        thirdImg->setAutoFillBackground(true);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(270, 420, 111, 31));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 728, 19));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        firstCam->setText(QString());
        secondCam->setText(QString());
        getObject->setText(QApplication::translate("MainWindow", "Train Background", 0));
        thirdImg->setText(QString());
        pushButton->setText(QApplication::translate("MainWindow", "Get Subtraction", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
