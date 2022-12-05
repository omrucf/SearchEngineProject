#include "websitescreen.h"
#include "ui_websitescreen.h"

websiteScreen::websiteScreen(QString input, webpage * site, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::websiteScreen)
{
    ui->setupUi(this);
    this->input = input;
    this->site = site;
}

websiteScreen::~websiteScreen()
{
    delete ui;
}
