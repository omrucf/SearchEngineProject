#include "results.h"
#include "ui_results.h"

results::results(QString input, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::results)
{
    ui->setupUi(this);
    this->input = input;
    QPixmap background(":/Images/background.jpeg");
    ui->Background->setPixmap(background);

    ui->label->setStyleSheet("QLabel { color : black; }");
    ui->Searchlabel->setStyleSheet("QLabel { color : black; }");
    ui->Searchlabel_2->setStyleSheet("QLabel { color : black; }");
    ui->exit->setStyleSheet("QPushButton { color : black; }");
    ui->search->setStyleSheet("QPushButton { color : black; }");

    ui->Input->setText(input);

    search();

}

results::~results()
{
    delete ui;
}

void results::search()
{

    string emptyString = "   ";
        emptyString[0] = '"';
        emptyString[1] = ' ';
        emptyString[2] = '"';

        s.setSites(g.getSites());

           g.checkPRs();

    vector<webpage *> output;

       char choice;
       char choicee;

       int i;

       string keywords = input.toStdString();

    if (keywords.find(emptyString) != string::npos ||
                    (keywords.find("AND") != string::npos))
                {
                    output = s.ANDSearch(keywords);
                }
                else if (keywords.find("OR") != string::npos)
                {
                    output = s.ORSearch(keywords);
                }
                else if (keywords[0] == '"' && keywords[keywords.size() - 1] == '"')
                {
                    output = s.QuoteSearch(keywords);
                }
                else
                {
                    output = s.ORSearch(keywords);
                }
    std::sort(output.begin(),
                          output.end(),
                          [](webpage *lhs, webpage *rhs)
                          {
                              return lhs->getScore() > rhs->getScore();
                          });

    for (int i = 0; i<output.size();i++)
    {
        stringstream oss;

        oss << output[i];

        output[i]->setImpressions(output[i]->getImpressions() + 1);


        string temp = oss.str();

        QString tempQS = QString::fromStdString(temp);

        qDebug() << tempQS;


        QListWidgetItem* item = new QListWidgetItem(QString::fromStdString(output[i]->getURL()));

        item->setData(QListWidgetItem::UserType, tempQS);

        ui->resultslist->addItem(item);
    }
}

void results::on_exit_clicked()
{
    this->close();
}


void results::on_search_clicked()
{
    this->close();

    results *r = new results(ui->Input->text());

    r->show();
}

void results::keyPressEvent(QKeyEvent *event)
{
  switch (event->key())
  {
    case (Qt::Key_Return):
      on_search_clicked();
       break;
  }
}



void results::on_resultslist_itemDoubleClicked(QListWidgetItem *item)
{
//    QString tempQS = item->UserType;
//    string tempstring = QString::toStdString(tempQS);
//    webpage *tempweb/* = */;

//    websiteScreen* WS = new websiteScreen(input, tempweb);
}

