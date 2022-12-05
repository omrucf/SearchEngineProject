#ifndef SCREEN_H
#define SCREEN_H

#include <QMainWindow>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui { class screen; }
QT_END_NAMESPACE

class screen : public QMainWindow
{
    Q_OBJECT

public:
    screen(QWidget *parent = nullptr);
    ~screen();

private slots:
    void on_exit_clicked();

    void on_search_clicked();

private:
    Ui::screen *ui;

protected:
   void keyPressEvent(QKeyEvent *event);
};
#endif // SCREEN_H
