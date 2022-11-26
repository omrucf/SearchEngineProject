#include "graph.h"

extern string getTillChar(string &, char);

graph::graph(){}

void graph::readSites()
{
    ifstream inWK, inWIC; // inputs from keywords.csv and impressions.csv

    inWIC.open("impressions.csv");

    string temp; // to store temp strings

    pair<string, pair<int, int>> wic; // to store temp urls with their impressions and clicks

    vector<pair<string, pair<int, int>>> WIC; // to store urls with their impressions and clicks

    while (!inWIC.eof())
    {
        getline(inWIC >> ws, temp);

        wic.first = getTillChar(temp, ','); // url
        wic.second.first = stoi(getTillChar(temp, ',')); // impressions
        wic.second.second = stoi(getTillChar(temp, ',')); // clicks
        WIC.push_back(wic);
    }
    inWIC.close();

    // vector<string> hyperlinks;

    // ifstream inWH;

    // inWH.open("webgraph.csv");

    // while(!inWH.eof())
    // {

    // }
    inWK.open("keywords.csv");

    

    string tempURL;

    int tempImpressions;
    int tempClicks;

    

    while (!inWK.eof())
    {
        vector<string> tempKeywords(0);

        getline(inWK >> ws, temp);

        tempURL = getTillChar(temp, ',');

        while (!temp.empty())
            tempKeywords.push_back(getTillChar(temp, ','));

        for (int i = 0; i < WIC.size(); i++)
        {
            if (WIC[i].first == tempURL)
            {
                tempImpressions = WIC[i].second.first;
                tempClicks = WIC[i].second.second;
            }
        }

        webpage *tempPage = new webpage(tempURL, tempKeywords, tempImpressions, tempClicks);

        sites.push_back(tempPage);
    }

    inWK.close();
}

void graph::Print()
{
    for(int i = 0; i < sites.size(); i++)
    {
        sites[i]->print();

        cout << endl;
    }
}

vector<webpage *> graph::getSites()
{
    return this->sites;
}