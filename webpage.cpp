#include "webpage.h"

webpage::webpage(){}

// webpage::webpage(string URL, vector<string> keywords, int impressions, int clicks)
// {
//     this->URL = URL;
//     this->keywords = keywords;
//     this->impressions = impressions;
//     this->clicks = clicks;
// }

void webpage::setURL(string URL)
{
    cout << "URL = " << URL << endl;
    this->URL = URL;
}

void webpage::setKeywords(vector<string> keywords)
{
    this->keywords = keywords;
}

void webpage::setImpressions(int impressions)
{
    cout << "impressions = " << impressions << endl;
    this->impressions = impressions;
}

void webpage::setClicks(int clicks)
{
    cout << "clicks = " << clicks << endl;
    this->clicks = clicks;
}

void webpage::setPR(int PR)
{
    cout << "PR = " << PR << endl;
    this->PR = PR;
}

void webpage::setpr(double pr)
{
    cout << "pr = " << pr << endl;
    this->pr = pr;
}

void webpage::setCTR(int ctr)
{
    cout << "ctr = " << ctr << endl;
    this->ctr = ctr;
}

void webpage::setScore(int score)
{
    cout << "score = " << score << endl;
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

int webpage::getImpressions()
{
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