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
    explicit websiteScreen(QString, QString, QWidget *parent = nullptr);
    ~websiteScreen();

private slots:
    void on_exit_clicked();

    void on_pushButton_clicked();

private:
    Ui::websiteScreen *ui;
    QString input;
    QString site;
};

#endif // WEBSITESCREEN_H
