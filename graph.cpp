#include "graph.h"

extern string getTillChar(string &, char);

graph::graph()
{
}

void graph::readSites()
{
    ifstream inWK, inWIC;

    inWIC.open("impressions.csv");

    string temp;

    pair<string, pair<int, int>> wic;

    vector<pair<string, pair<int, int>>> WIC;

    while (!inWIC.eof())
    {
        getline(inWIC >> ws, temp);

        wic.first = getTillChar(temp, ',');
        wic.second.first = stoi(getTillChar(temp, ','));
        wic.second.second = stoi(getTillChar(temp, ','));
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