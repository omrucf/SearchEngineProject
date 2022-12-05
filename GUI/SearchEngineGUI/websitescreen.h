#ifndef WEBSITESCREEN_H
#define WEBSITESCREEN_H

#include <QWidget>

namespace Ui {
class websiteScreen;
}

class websiteScreen : public QWidget
{
    Q_OBJECT

public:
    explicit websiteScreen(QWidget *parent = nullptr);
    ~websiteScreen();

private:
    Ui::websiteScreen *ui;
};

#endif // WEBSITESCREEN_H
