#include "graph.h"

extern string getTillChar(string &, char);

graph::graph() {}

void graph::readImpressions() // O(n)
{
    
    // webpage tempPage;

    ifstream inWIC;

    inWIC.open("impressions.csv");

    string temp; // to store temp strings

    // pair<string, pair<int, int>> wic; // to store temp urls with their impressions and clicks

    // vector<pair<string, pair<int, int>>> WIC; // to store urls with their impressions and clicks

    while (!inWIC.eof())
    {
        webpage *tempPage = new webpage;

        getline(inWIC >> ws, temp);

        // wic.first = getTillChar(temp, ',');               // url
        // wic.second.first = stoi(getTillChar(temp, ','));  // impressions
        // wic.second.second = stoi(getTillChar(temp, ',')); // clicks
        // WIC.push_back(wic);

        cout << "temp = " << temp << endl;

        tempPage->setURL(getTillChar(temp, ','));
        tempPage->setImpressions(stoi(getTillChar(temp, ',')));
        tempPage->setClicks(stoi(getTillChar(temp, ',')));
        tempPage->setCTR(stoi(getTillChar(temp, ',')));
        tempPage->setPR(stoi(getTillChar(temp, ',')));
        tempPage->setScore(stoi(getTillChar(temp, ',')));

        // tempPage.setURL(getTillChar(temp, ','));
        // cout << "after setURL\n";
        // tempPage.setImpressions(stoi(getTillChar(temp, ',')));
        // cout << "after aetImpressions\n";
        // tempPage.setClicks(stoi(getTillChar(temp, ',')));
        // cout << "after setClicks\n";
        // tempPage.setCTR(stoi(getTillChar(temp, ',')));
        // cout << "after setCTR\n";
        // tempPage.setPR(stoi(getTillChar(temp, ',')));
        // cout << "after setPR\n";
        // tempPage.setScore(stoi(getTillChar(temp, ',')));
        // cout << "after setScore\n";

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
        // webpage *tempPage = new webpage;

        vector<string> tempKeywords(0);

        getline(inWK >> ws, temp);

        tempURL = getTillChar(temp, ',');

        while (!temp.empty())
            tempKeywords.push_back(getTillChar(temp, ','));

        for (int i = 0; i < sites.size(); i++) // n times
        {
            if (sites[i]->getURL() == tempURL)
            {
                cout << "URL: " << sites[i]->getURL() << endl;
                cout << "keyword[0]: " << tempKeywords[0];
                sites[i]->setKeywords(tempKeywords);
                cout << "sites[i].getkeyword[0]: " << sites[i]->getKeywords()[0];
            }    
        }

        // sites.push_back(tempPage);
    }

    inWK.close();
}
void readWebgraph(); // 

void graph::readSites()
{
    webpage *tempPage = new webpage();

    readImpressions();
    readKeywords();

    // vector<string> hyperlinks;

    // ifstream inWH;

    // inWH.open("webgraph.csv");

    // while(!inWH.eof())
    // {

    // }

    // ifstream inWK; // inputs from keywords.csv and impressions.csv

    // inWK.open("keywords.csv");

    // string tempURL;

    // int tempImpressions;
    // int tempClicks;

    // while (!inWK.eof())
    // {
    //     vector<string> tempKeywords(0);

    //     getline(inWK >> ws, temp);

    //     tempURL = getTillChar(temp, ',');

    //     while (!temp.empty())
    //         tempKeywords.push_back(getTillChar(temp, ','));

    //     for (int i = 0; i < WIC.size(); i++)
    //     {
    //         if (WIC[i].first == tempURL)
    //         {
    //             tempImpressions = WIC[i].second.first;
    //             tempClicks = WIC[i].second.second;
    //         }
    //     }

    //     sites.push_back(tempPage);
    // }

    // inWK.close();
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