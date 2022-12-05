/********************************************************************************
** Form generated from reading UI file 'websitescreen.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBSITESCREEN_H
#define UI_WEBSITESCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_websiteScreen
{
public:
    QLabel *Background;
    QPushButton *exit;
    QLabel *label;
    QLabel *URL;

    void setupUi(QWidget *websiteScreen)
    {
        if (websiteScreen->objectName().isEmpty())
            websiteScreen->setObjectName(QString::fromUtf8("websiteScreen"));
        websiteScreen->resize(983, 535);
        Background = new QLabel(websiteScreen);
        Background->setObjectName(QString::fromUtf8("Background"));
        Background->setGeometry(QRect(0, -3, 983, 535));
        exit = new QPushButton(websiteScreen);
        exit->setObjectName(QString::fromUtf8("exit"));
        exit->setGeometry(QRect(20, 450, 80, 24));
        QFont font;
        exit->setFont(font);
        exit->setCursor(QCursor(Qt::PointingHandCursor));
        exit->setAutoFillBackground(false);
        label = new QLabel(websiteScreen);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(260, 17, 461, 71));
        QFont font1;
        font1.setPointSize(21);
        font1.setBold(true);
        font1.setItalic(true);
        label->setFont(font1);
        label->setAlignment(Qt::AlignCenter);
        URL = new QLabel(websiteScreen);
        URL->setObjectName(QString::fromUtf8("URL"));
        URL->setGeometry(QRect(200, 200, 571, 71));
        QFont font2;
        font2.setPointSize(25);
        URL->setFont(font2);

        retranslateUi(websiteScreen);

        QMetaObject::connectSlotsByName(websiteScreen);
    } // setupUi

    void retranslateUi(QWidget *websiteScreen)
    {
        websiteScreen->setWindowTitle(QCoreApplication::translate("websiteScreen", "Form", nullptr));
        Background->setText(QString());
        exit->setText(QCoreApplication::translate("websiteScreen", "Exit :(", nullptr));
        label->setText(QCoreApplication::translate("websiteScreen", "Omar's Search Engine :)", nullptr));
        URL->setText(QCoreApplication::translate("websiteScreen", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class websiteScreen: public Ui_websiteScreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBSITESCREEN_H
