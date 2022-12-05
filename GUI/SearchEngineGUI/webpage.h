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

    double score;
    double PR;
    double ctr;

public:
    webpage();

    void setURL(string);
    void setKeywords(vector<string>);
    void setImpressions(int);
    void setClicks(int);
    void setPR(double);
    void setCTR(double);
    void setScore(double);
    void pushHyperlink(webpage *);
    void pushInbound(webpage *);
    void print();
    void printAdvanced();
    void calculateScore();
    void calculateCTR();

    string getURL();

    vector<string> getKeywords();

    vector<webpage *> getHyperlinks();
    vector<webpage *> getInbound();

    int getImpressions();
    int getClicks();

    double getScore();
    double getCTR();
    double getPR();
};

#endif
