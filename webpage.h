#ifndef WEBPAGE_H
#define WEBPAGE_H

#include <iostream>
#include <vector>

using namespace std;

class webpage
{
    string URL;
    
    vector<string> keywords;

    vector<webpage *> hyperlinks;

    vector<webpage *> inbound;

    int PR;
    int ctr;
    int impressions, clicks;

    double pr;

    public:

    webpage();
    webpage(string, vector<string>, int, int);

    void setPR(int);
    void setpr(double);
    void setCTR(int);
    void setHyperlinks(vector<webpage *>);
    void setInbound(vector<webpage *>);
    void print();

    string getURL();
    
    vector<string> getKeywords();

    vector<webpage *> getHyperlinks();
    vector<webpage *> getInbound();

    int getPR();
    int getCTR();
    int getImpressions();
    int getClicks();

    double getPr();
};


#endif