#include "webpage.h"

Q_DECLARE_METATYPE(webpage *);

webpage::webpage()
{}

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

void webpage::setScore(double score)
{
    this->score = score;
}

void webpage::pushHyperlink(webpage *hyperlink)
{
    this->hyperlinks.push_back(hyperlink);
}

void webpage::pushInbound(webpage *inbound)
{
    this->inbound.push_back(inbound);
}

void webpage::print()
{
    cout << "\t\t  ======================================================================================" << endl
         << "\t\t||                                                                                      ||" << endl
         << "\t\t||        Keywords:                                                                     ||" << endl;

    for (int i = 0; i < keywords.size(); i++)
        cout << "\t\t||        \t" << keywords[i] << endl;

    cout << "\t\t||                                                                                      ||" << endl
         << "\t\t  ======================================================================================" << endl;
}

void webpage::printAdvanced()
{
    cout << "\t\t  ======================================================================================" << endl
         << "\t\t||                                                                                      ||" << endl
         << "\t\t||        Keywords:                                                                     ||" << endl;

    for (int i = 0; i < keywords.size(); i++)
        cout << "\t\t||        \t" << keywords[i] << endl;

    cout << "\t\t||        Impressions:\n\t" << impressions << endl
         << "\t\t||        Clicks:\n\t" << clicks << endl
         << "\t\t||        CTR:\n\t" << ctr << endl
         << "\t\t||        PR:\n\t" << PR << endl
         << "\t\t||        Score:\n\t" << score << endl;

    cout << "\t\t||        Hyperlinks:\n";
    for (int i = 0; i < hyperlinks.size(); i++)
        cout << "\t\t||        \t" << hyperlinks[i]->getURL() << endl;

    cout << "Inbound:\n";
    for (int i = 0; i < inbound.size(); i++)
        cout << "\t\t||        \t" << inbound[i]->getURL() << endl;

    cout << "\t\t||                                                                                      ||" << endl
         << "\t\t  ======================================================================================" << endl;
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

int webpage::getImpressions()
{
    return this->impressions;
}

int webpage::getClicks()
{
    return this->clicks;
}

double webpage::getScore()
{
    return this->score;
}

double webpage::getCTR()
{
    return this->ctr;
}

double webpage::getPR()
{
    return this->PR;
}

void webpage::calculateScore()
{
    calculateCTR();

    double tempScore =
        (0.4 * PR) +
        ((1 - (0.1 * impressions / (1 + (0.1 * impressions)))) * PR + ((0.1 * impressions / (1 + (0.1 * impressions)))) * ctr) * 0.6;

    setScore(tempScore);
}

void webpage::calculateCTR()
{
    setCTR((double(clicks) / double(impressions)));
}
