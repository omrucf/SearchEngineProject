#include "graph.h"

extern string getTillChar(string &, char);

graph::graph()
{
    readSites();
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
        tempPage->setScore(stoi(getTillChar(temp, ',')));

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

        getline(inWK >> ws, temp);

        tempURL = getTillChar(temp, ',');

        while (!temp.empty())
            tempKeywords.push_back(getTillChar(temp, ','));

        sites[i++]->setKeywords(tempKeywords);
    }

    inWK.close();
}

void graph::readWebgraph() // O(n^2)
{
    ifstream inWH; // inputs from keywords.csv and impressions.csv

    string temp; // to store temp strings

    inWH.open("webgraph.csv");

    string tempURL;

    int i = 0;

    while (!inWH.eof()) // n times
    {
        string tempHyper;

        vector<webpage *> tempHypers;

        getline(inWH >> ws, temp);

        tempURL = getTillChar(temp, ',');

        while (!temp.empty())
        {
            tempHyper = getTillChar(temp, ',');
            for(int j = 0; j < sites.size(); j++) // n times
            {
                if(sites[j]->getURL() == tempHyper)
                {
                    tempHypers.push_back(sites[j]);
                    sites[j]->pushInbound(sites[i]);
                }
            }
        }

        sites[i++]->setHyperlinks(tempHypers);
    }

    inWH.close();
}

void graph::readSites()
{
    readImpressions(); // O(n)
    readKeywords();    // O(n)
    readWebgraph(); // O(n^2)
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

        cout << endl;
    }
}

vector<webpage *> graph::getSites()
{
    return this->sites;
}