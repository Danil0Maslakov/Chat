/********************************************************************************
** Form generated from reading UI file 'mainwindowclient.ui'
**
** Created by: Qt User Interface Compiler version 6.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOWCLIENT_H
#define UI_MAINWINDOWCLIENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindowClient
{
public:
    QWidget *centralwidget;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_2;
    QPushButton *Connect;
    QVBoxLayout *verticalLayout;
    QTextBrowser *textBrowser;
    QHBoxLayout *horizontalLayout;
    QPushButton *Send;
    QLineEdit *Message;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindowClient)
    {
        if (MainWindowClient->objectName().isEmpty())
            MainWindowClient->setObjectName("MainWindowClient");
        MainWindowClient->resize(800, 600);
        centralwidget = new QWidget(MainWindowClient);
        centralwidget->setObjectName("centralwidget");
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(210, 60, 260, 270));
        verticalLayout_2 = new QVBoxLayout(layoutWidget);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        Connect = new QPushButton(layoutWidget);
        Connect->setObjectName("Connect");

        verticalLayout_2->addWidget(Connect);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        textBrowser = new QTextBrowser(layoutWidget);
        textBrowser->setObjectName("textBrowser");

        verticalLayout->addWidget(textBrowser);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        Send = new QPushButton(layoutWidget);
        Send->setObjectName("Send");

        horizontalLayout->addWidget(Send);

        Message = new QLineEdit(layoutWidget);
        Message->setObjectName("Message");

        horizontalLayout->addWidget(Message);


        verticalLayout->addLayout(horizontalLayout);


        verticalLayout_2->addLayout(verticalLayout);

        MainWindowClient->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindowClient);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 25));
        MainWindowClient->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindowClient);
        statusbar->setObjectName("statusbar");
        MainWindowClient->setStatusBar(statusbar);

        retranslateUi(MainWindowClient);

        QMetaObject::connectSlotsByName(MainWindowClient);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindowClient)
    {
        MainWindowClient->setWindowTitle(QCoreApplication::translate("MainWindowClient", "MainWindowClient", nullptr));
        Connect->setText(QCoreApplication::translate("MainWindowClient", "Connect", nullptr));
        Send->setText(QCoreApplication::translate("MainWindowClient", "->", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindowClient: public Ui_MainWindowClient {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOWCLIENT_H
