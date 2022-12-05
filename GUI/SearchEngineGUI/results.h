#ifndef RESULTS_H
#define RESULTS_H

#include <QWidget>
#include <QKeyEvent>
#include <QListWidgetItem>

#include "graph.h"
#include "search.h"
#include "screen.h"

namespace Ui {
class results;
}

class results : public QWidget
{
    Q_OBJECT

public:
    explicit results(QString, QWidget *parent = nullptr);
    ~results();

    void search();

private slots:
    void on_exit_clicked();

    void on_search_clicked();

    void on_resultslist_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::results *ui;
    QString input;
    Search s;
    graph g;


protected:
   void keyPressEvent(QKeyEvent *event);
};

#endif // RESULTS_H
