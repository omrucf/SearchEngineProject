#include "graph.h"

extern string getTillChar(string &, char);

graph::graph()
{
    readSites();

    calculatePR();
}

graph::~graph()
{
    outImpressions();
}

void graph::readImpressions() // O(n)
{
    ifstream inWIC;

    inWIC.open("impressions.csv");

    string temp; // to store temp strings

    while (!inWIC.eof())
    {
        webpage *tempPage = new webpage;

        getline(inWIC >> ws, temp);

        tempPage->setURL(getTillChar(temp, ','));
        tempPage->setImpressions(stoi(getTillChar(temp, ',')));
        tempPage->setClicks(stoi(getTillChar(temp, ',')));
        tempPage->setCTR(stod(getTillChar(temp, ',')));
        tempPage->setPR(stod(getTillChar(temp, ',')));
        tempPage->setScore(stod(getTillChar(temp, ',')));

        sites.push_back(tempPage);
    }

    inWIC.close();
}

void graph::readKeywords() // O(n)
{
    ifstream inWK; // inputs from keywords.csv and impressions.csv

    string temp; // to store temp strings

    inWK.open("keywords.csv");

    string tempURL;

    int i = 0;

    while (!inWK.eof()) // n times
    {
        vector<string> tempKeywords(0);

        string tempkeyword;

        getline(inWK >> ws, temp);

        tempURL = getTillChar(temp, ',');

        while (!temp.empty())
        {

            tempkeyword = getTillChar(temp, ',');

            tempKeywords.push_back(tempkeyword);


            transform(tempkeyword.begin(), tempkeyword.end(), tempkeyword.begin(), ::toupper);

        }

        sites[i++]->setKeywords(tempKeywords);
    }

    inWK.close();
}

void graph::readWebgraph() // O(n)
{
    ifstream inWH; // inputs from keywords.csv and impressions.csv

    string temp; // to store temp strings

    inWH.open("webgraph.csv");

    string tempURL;

    int i = 0;

    while (!inWH.eof()) // n times
    {
        string tempHyper;

        getline(inWH >> ws, temp);

        tempURL = getTillChar(temp, ',');
        int mainI = stoi(getTillChar(temp, ','));

        while (!temp.empty())
        {
            tempHyper = getTillChar(temp, ',');
            int hyperI = stoi(getTillChar(temp, ','));

            sites[mainI]->pushHyperlink(sites[hyperI]);
            sites[hyperI]->pushInbound(sites[mainI]);
        }
    }

    inWH.close();
}

void graph::readSites() // O(n)
{
    readImpressions(); // O(n)
    readKeywords();    // O(n)
    readWebgraph();    // O(n)
}

void graph::outImpressions()
{
    ofstream out;

    out.open("impressions.csv");

    for (int i = 0; i < sites.size(); i++)
    {
        out << sites[i]->getURL() << ","
            << sites[i]->getImpressions() << ","
            << sites[i]->getClicks() << ","
            << sites[i]->getCTR() << ","
            << sites[i]->getPR() << ","
            << sites[i]->getScore();
        if (i != sites.size() - 1)
            out << endl;
    }
}

void graph::calculatePR() // O(mn)
{
    const double numOfSites = sites.size();

    vector<double> PRVec;

    double MOE = 0.000001; // margin of error

    int j = 0;

    vector<bool> moe(numOfSites, false); // margin of error
    bool allmoe = false;

    for (int i = 0; i < numOfSites; i++) // iteration 0; n times
    {
        sites[i]->setPR(double(1.0 / numOfSites));

        PRVec.push_back(sites[i]->getPR());
    }

    while (!allmoe && j < 100)
    {
        for (int i = 0; i < numOfSites; i++) // n times
        {

            double tempPR = 0.0;

            for (int k = 0; k < sites[i]->getInbound().size(); k++) // m times
                tempPR += (sites[i]->getInbound()[k]->getPR() / sites[i]->getInbound()[k]->getHyperlinks().size());

            tempPR = ((1 - 0.85) / numOfSites) + (0.85 * tempPR);

            PRVec[i] = tempPR;
        }
        allmoe = true;
        for (int i = 0; i < numOfSites; i++) // n times
        {
            if (abs(sites[i]->getPR() - PRVec[i]) > MOE)
                sites[i]->setPR(PRVec[i]);
            else
                moe[i] = true;

            if (!moe[i])
                allmoe = false;
        }

        ++j;
    }
}

void graph::Print()
{
    for (int i = 0; i < sites.size(); i++)
    {
        sites[i]->print();

        cout << endl;
    }
}

void graph::PrintAdvanced()
{
    for (int i = 0; i < sites.size(); i++)
    {
        sites[i]->printAdvanced();

        cout << "=============================================";

        cout << endl;
    }
}

vector<webpage *> graph::getSites()
{
    return this->sites;
}

void graph::checkPRs()
{
    double total = 0.0;
    for (int i = 0; i < sites.size(); i++)
        total += sites[i]->getPR();
}
