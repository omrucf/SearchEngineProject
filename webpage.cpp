#include "webpage.h"

webpage::webpage(){}

void webpage::setURL(string URL)
{
    this->URL = URL;
}

void webpage::setKeywords(vector<string> keywords)
{
    this->keywords = keywords;
}

void webpage::setImpressions(int impressions)
{
    this->impressions = impressions;
}

void webpage::setClicks(int clicks)
{
    this->clicks = clicks;
}

void webpage::setPR(double PR)
{
    this->PR = PR;
}

void webpage::setCTR(double ctr)
{
    this->ctr = ctr;
}

void webpage::setScore(int score)
{
    this->score = score;
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
}

void webpage::printAdvanced()
{
    cout << "URL:\n\t" << URL << endl
         << "Keywords:\n";

    for (int i = 0; i < keywords.size(); i++)
        cout << "\t" << keywords[i] << endl;

    cout << "Impressions:\n\t" << impressions << endl
         << "Clicks:\n\t" << clicks << endl
         << "CTR:\n\t" << ctr << endl
         << "PR:\n\t" << PR << endl
         << "Score:\n\t" << score << endl;
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


int webpage::getCTR()
{
    return this->ctr;
}

int webpage::getImpressions()
{
    return this->impressions;
}

int webpage::getClicks()
{
    return this->clicks;
}
