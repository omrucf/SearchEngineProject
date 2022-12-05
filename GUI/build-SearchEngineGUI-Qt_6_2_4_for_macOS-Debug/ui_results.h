/********************************************************************************
** Form generated from reading UI file 'results.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESULTS_H
#define UI_RESULTS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_results
{
public:
    QLabel *label;
    QLineEdit *Input;
    QLabel *Background;
    QPushButton *exit;
    QLabel *Searchlabel;
    QPushButton *search;
    QLabel *Searchlabel_2;
    QListWidget *resultslist;

    void setupUi(QWidget *results)
    {
        if (results->objectName().isEmpty())
            results->setObjectName(QString::fromUtf8("results"));
        results->resize(983, 535);
        label = new QLabel(results);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 17, 461, 71));
        QFont font;
        font.setPointSize(21);
        font.setBold(true);
        font.setItalic(true);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        Input = new QLineEdit(results);
        Input->setObjectName(QString::fromUtf8("Input"));
        Input->setGeometry(QRect(10, 150, 361, 41));
        QFont font1;
        font1.setPointSize(35);
        Input->setFont(font1);
        Input->setAutoFillBackground(false);
        Input->setFrame(true);
        Background = new QLabel(results);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, -3, 983, 535));
        exit = new QPushButton(results);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(20, 447, 80, 24));
        QFont font2;
        exit->setFont(font2);
        exit->setCursor(QCursor(Qt::PointingHandCursor));
        exit->setAutoFillBackground(false);
        Searchlabel = new QLabel(results);
        Searchlabel->setObjectName(QString::fromUtf8("Searchlabel"));
        Searchlabel->setGeometry(QRect(10, 110, 131, 41));
        Searchlabel->setFont(font1);
        search = new QPushButton(results);
        search->setObjectName(QString::fromUtf8("search"));
        search->setGeometry(QRect(280, 193, 91, 41));
        QFont font3;
        font3.setPointSize(20);
        search->setFont(font3);
        search->setCursor(QCursor(Qt::PointingHandCursor));
        Searchlabel_2 = new QLabel(results);
        Searchlabel_2->setObjectName(QString::fromUtf8("Searchlabel_2"));
        Searchlabel_2->setGeometry(QRect(500, 110, 131, 41));
        Searchlabel_2->setFont(font1);
        resultslist = new QListWidget(results);
        resultslist->setObjectName(QString::fromUtf8("resultslist"));
        resultslist->setGeometry(QRect(500, 170, 411, 341));
        Background->raise();
        label->raise();
        Input->raise();
        exit->raise();
        Searchlabel->raise();
        search->raise();
        Searchlabel_2->raise();
        resultslist->raise();

        retranslateUi(results);

        QMetaObject::connectSlotsByName(results);
    } // setupUi

    void retranslateUi(QWidget *results)
    {
        results->setWindowTitle(QCoreApplication::translate("results", "Form", nullptr));
        label->setText(QCoreApplication::translate("results", "Omar's Search Engine :)", nullptr));
        Input->setText(QString());
        Background->setText(QString());
        exit->setText(QCoreApplication::translate("results", "Exit :(", nullptr));
        Searchlabel->setText(QCoreApplication::translate("results", "Search: ", nullptr));
        search->setText(QCoreApplication::translate("results", "Search :)", nullptr));
        Searchlabel_2->setText(QCoreApplication::translate("results", "Results:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class results: public Ui_results {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESULTS_H
