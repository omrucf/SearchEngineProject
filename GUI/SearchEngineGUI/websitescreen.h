#ifndef WEBSITESCREEN_H
#define WEBSITESCREEN_H

#include <QWidget>

#include "results.h"

namespace Ui {
class websiteScreen;
}

class websiteScreen : public QWidget
{
    Q_OBJECT

public:
    explicit websiteScreen(QString, webpage*, QWidget *parent = nullptr);
    ~websiteScreen();

private:
    Ui::websiteScreen *ui;
    QString input;
    webpage * site;
};

#endif // WEBSITESCREEN_H
