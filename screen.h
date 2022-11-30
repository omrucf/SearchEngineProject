#ifndef SCREEN_H
#define SCREEN_H

#include "search.h"
#include "graph.h"

extern void clear();
extern string getTillChar(string &, char);

class screen
{
    string emptyString;

    graph g;

    Search s;

public:
    screen();

    void startingScreen();

    int resultsScreen(vector<webpage *>);
    int webScreen(vector<webpage *>, int);
};

#endif /*SCREEN_H*/