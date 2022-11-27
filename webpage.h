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

    int impressions;
    int clicks;
    int score;

    double PR;
    double ctr;

    public:

    webpage();
    // webpage(string, vector<string>, int, int);

    void setURL(string);
    void setKeywords(vector<string>);
    void setImpressions(int);
    void setClicks(int);
    void setPR(int);
    void setpr(double);
    void setCTR(int);
    void setScore(int);
    void setHyperlinks(vector<webpage *>);
    void setInbound(vector<webpage *>);
    void print();

    string getURL();
    
    vector<string> getKeywords();

    vector<webpage *> getHyperlinks();
    vector<webpage *> getInbound();

    int getCTR();
    int getImpressions();
    int getClicks();

    double getPR();
};


#endif