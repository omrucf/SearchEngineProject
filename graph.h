#include <fstream>

#include "webpage.h"

class graph
{
    vector<webpage *> sites;

    public:

    graph();

    void readSites();

    void Print();

    vector<webpage *> getSites();

};