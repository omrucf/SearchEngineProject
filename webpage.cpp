#include "webpage.h"

webpage::webpage()
{
}

webpage::webpage(string URL, vector<string> keywords, int impressions, int clicks)
{
    this->URL = URL;
    this->keywords = keywords;
    this->impressions = impressions;
    this->clicks = clicks;
}

void webpage::setPR(int PR)
{
    this->PR = PR;
}

void webpage::setpr(double pr)
{
    this->pr = pr;
}

void webpage::setCTR(int ctr)
{
    this->ctr = ctr;
}

void webpage::setHyperlinks(vector<webpage *> hyperlinks)
{
    this->hyperlinks = hyperlinks;
}

void webpage::setInbound(vector<webpage *> inbound)
{
    this->inbound = inbound;
}

void webpage::print()
{
    cout << "URL:\n\t" << URL << endl
         << "Keywords:\n";

    for (int i = 0; i < keywords.size(); i++)
        cout << "\t" << keywords[i] << endl;

    cout << "Impressions:\n\t" << impressions << endl
         << "Clicks:\n\t" << clicks << endl;
}

string webpage::getURL()
{
    return this->URL;
}

vector<string> webpage::getKeywords()
{
    return this->keywords;
}

vector<webpage *> webpage::getHyperlinks()
{
    return this->hyperlinks;
}

vector<webpage *> webpage::getInbound()
{
    return this->inbound;
}

int webpage::getPR()
{
    return PR;
}

int webpage::getCTR()
{
return this->ctr;
}

int webpage::getImpressions(){
    return this->impressions;
}

int webpage::getClicks()
{
    return this->clicks;
}

double webpage::getPr()
{
    return this->pr;
}