#include <fstream>

#include "webpage.h"

class graph
{
    vector<webpage *> sites;

    public:

    graph();

    void readImpressions();
    void readKeywords();
    void readWebgraph();
    void readSites();
    void Print();
    void PrintAdvanced();

    vector<webpage *> getSites();

};