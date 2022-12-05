#include <fstream>
#include <map>

#include "webpage.h"

class graph
{
    vector<webpage *> sites;

    map<string, vector<webpage *>> keywords;
    map<string, vector<webpage *>> keywordsNoCase;

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
