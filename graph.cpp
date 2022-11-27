#include "graph.h"

extern string getTillChar(string &, char);

graph::graph() {}

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
        tempPage->setCTR(stoi(getTillChar(temp, ',')));
        tempPage->setPR(stoi(getTillChar(temp, ',')));
        tempPage->setScore(stoi(getTillChar(temp, ',')));

        sites.push_back(tempPage);
    }

    inWIC.close();
}

void graph::readKeywords() // O(n^2)
{
    ifstream inWK; // inputs from keywords.csv and impressions.csv

    string temp; // to store temp strings

    inWK.open("keywords.csv");

    string tempURL;

    int tempImpressions;
    int tempClicks;

    while (!inWK.eof()) // n times
    {
        vector<string> tempKeywords(0);

        getline(inWK >> ws, temp);

        tempURL = getTillChar(temp, ',');

        while (!temp.empty())
            tempKeywords.push_back(getTillChar(temp, ','));

        for (int i = 0; i < sites.size(); i++) // n times
        {
            if (sites[i]->getURL() == tempURL)
                sites[i]->setKeywords(tempKeywords);   
        }
    }
    inWK.close();
}
void graph::readWebgraph() //
{

}

void graph::readSites()
{
    webpage *tempPage = new webpage();

    readImpressions();
    readKeywords();
}

void graph::Print()
{
    for (int i = 0; i < sites.size(); i++)
    {
        sites[i]->print();

        cout << endl;
    }
}

vector<webpage *> graph::getSites()
{
    return this->sites;
}