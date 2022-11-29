#include <fstream>

#include "webpage.h"

class graph
{
    vector<webpage *> sites;

    public:

    graph();
    ~graph();

    void readImpressions();
    void readKeywords();
    void readWebgraph();
    void readSites();
    void outImpressions();
    void calculatePR();
    void Print();
    void PrintAdvanced();

    void checkPRs();

    vector<webpage *> getSites();

};