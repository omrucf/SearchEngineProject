/********************************************************************************
** Form generated from reading UI file 'screen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCREEN_H
#define UI_SCREEN_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_screen
{
public:
    QWidget *centralwidget;
    QLabel *Background;
    QLabel *label;
    QPushButton *exit;
    QLineEdit *Input;
    QLabel *Searchlabel;
    QPushButton *search;
    QMenuBar *menubar;
    QMenu *menuOmar_s_Search_Engine;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *screen)
    {
        if (screen->objectName().isEmpty())
            screen->setObjectName(QString::fromUtf8("screen"));
        screen->resize(983, 535);
        centralwidget = new QWidget(screen);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        Background = new QLabel(centralwidget);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, 0, 983, 535));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 20, 461, 71));
        QFont font;
        font.setFamilies({QString::fromUtf8("Chalkboard")});
        font.setPointSize(21);
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        exit = new QPushButton(centralwidget);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(20, 450, 80, 24));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Chalkboard")});
        exit->setFont(font1);
        exit->setCursor(QCursor(Qt::PointingHandCursor));
        exit->setAutoFillBackground(false);
        Input = new QLineEdit(centralwidget);
        Input->setObjectName(QString::fromUtf8("Input"));
        Input->setGeometry(QRect(310, 240, 361, 41));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Chalkboard")});
        font2.setPointSize(35);
        Input->setFont(font2);
        Input->setAutoFillBackground(false);
        Input->setFrame(true);
        Searchlabel = new QLabel(centralwidget);
        Searchlabel->setObjectName(QString::fromUtf8("Searchlabel"));
        Searchlabel->setGeometry(QRect(310, 200, 131, 41));
        Searchlabel->setFont(font2);
        search = new QPushButton(centralwidget);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(580, 283, 91, 41));
        QFont font3;
        font3.setPointSize(20);
        search->setFont(font3);
        search->setCursor(QCursor(Qt::PointingHandCursor));
        screen->setCentralWidget(centralwidget);
        menubar = new QMenuBar(screen);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 983, 21));
        menuOmar_s_Search_Engine = new QMenu(menubar);
        menuOmar_s_Search_Engine->setObjectName(QString::fromUtf8("menuOmar_s_Search_Engine"));
        screen->setMenuBar(menubar);
        statusbar = new QStatusBar(screen);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        screen->setStatusBar(statusbar);

        menubar->addAction(menuOmar_s_Search_Engine->menuAction());

        retranslateUi(screen);

        QMetaObject::connectSlotsByName(screen);
    } // setupUi

    void retranslateUi(QMainWindow *screen)
    {
        screen->setWindowTitle(QCoreApplication::translate("screen", "screen", nullptr));
        Background->setText(QString());
        label->setText(QCoreApplication::translate("screen", "Welcome to Omar's Search Engine :)", nullptr));
        exit->setText(QCoreApplication::translate("screen", "Exit :(", nullptr));
        Input->setText(QString());
        Searchlabel->setText(QCoreApplication::translate("screen", "Search: ", nullptr));
        search->setText(QCoreApplication::translate("screen", "Search :)", nullptr));
        menuOmar_s_Search_Engine->setTitle(QCoreApplication::translate("screen", "Omar's Search Engine", nullptr));
    } // retranslateUi

};

namespace Ui {
    class screen: public Ui_screen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCREEN_H
