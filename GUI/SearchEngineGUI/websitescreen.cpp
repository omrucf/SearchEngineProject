#include "websitescreen.h"
#include "ui_websitescreen.h"

websiteScreen::websiteScreen(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::websiteScreen)
{
    ui->setupUi(this);
}

websiteScreen::~websiteScreen()
{
    delete ui;
}
