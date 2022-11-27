#ifndef SEARCH_H
#define SEARCH_H

#include <iostream>
#include <vector>
#include <fstream>
#include <set>

#include "webpage.h"

using namespace std;

extern string getTillChar(string &, char);

class Search
{
    vector<webpage *> sites;

public:
    Search();

    vector<string> ANDSearch(string);
    vector<string> ORSearch(string);

    void setSites(vector<webpage *>);

};

#endif /*SEARCH_H*/