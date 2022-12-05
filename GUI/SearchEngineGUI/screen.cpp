#include "screen.h"
#include "ui_screen.h"
#include "results.h"

screen::screen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::screen)
{
    ui->setupUi(this);

    QPixmap background(":/Images/background.jpeg");
    ui->Background->setPixmap(background);

    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->Searchlabel->setStyleSheet("QLabel { color : black; }");
    ui->exit->setStyleSheet("QPushButton { color : black; }");
    ui->search->setStyleSheet("QPushButton { color : black; }");

}

screen::~screen()
{
    delete ui;
}

void screen::on_exit_clicked()
{
    this->close();
}


void screen::on_search_clicked()
{
    this->close();

    results *r = new results(ui->Input->text());

    r->show();
}

void screen::keyPressEvent(QKeyEvent *event)
{
  switch (event->key())
  {
    case (Qt::Key_Return):
      on_search_clicked();
       break;
  }
}

