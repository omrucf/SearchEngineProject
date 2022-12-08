#include "websitescreen.h"
#include "ui_websitescreen.h"

websiteScreen::websiteScreen(QString input, QString site, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::websiteScreen)
{
    ui->setupUi(this);
    this->input = input;
    this->site = site;
    QPixmap background(":/Images/background.jpeg");
    ui->Background->setPixmap(background);
    ui->URL->setText("You are now viewing " + site);
}

websiteScreen::~websiteScreen()
{
    delete ui;
}

void websiteScreen::on_exit_clicked()
{
    this->close();
}


void websiteScreen::on_pushButton_clicked()
{
    this->close();

    results * r = new results(input);
    r->show();
}

