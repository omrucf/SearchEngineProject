#include "search.h"

Search::Search(){}

vector<webpage *> Search::ANDSearch(string input)
{
    string results(""), urls;
    vector<string> URLs;
    vector<string> KWs;
    vector<webpage *> res;

    while (!input.empty())
    {
        string temp;

        do
            temp = getTillChar(input, ' ');
        while (temp == "AND");

        temp.erase(remove(temp.begin(), temp.end(), '"'), temp.end());

        if (temp[0] == ' ')
            temp = temp.substr(1, temp.size() - 1);

        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

        KWs.push_back(temp);
    }

    for (int i = 0; i < sites.size(); i++)
    {
        bool Flag(true);

        string URL = sites[i]->getURL();

        string keys;

        for (int j = 0; j < sites[i]->getKeywords().size(); j++)
            keys += sites[i]->getKeywords()[j] + " ";

        transform(keys.begin(), keys.end(), keys.begin(), ::toupper);

        for (int i = 0; i < KWs.size(); i++)
        {
            if (keys.find(KWs[i]) == string::npos)
                Flag = false;
        }

        if (Flag)
            if (results.find(URL) == string::npos)
            {
                results += URL + " ";
                res.push_back(sites[i]);
            }
    }

    if (results.empty())
        cout << "no results found!!\n";

    return res;
}

vector<webpage *> Search::ORSearch(string input)
{
    string results(""), urls;
    vector<string> URLs;
    vector<string> KWs;
    vector<webpage *> res;

    while (!input.empty())
    {
        string temp;

        do
            temp = getTillChar(input, ' ');
        while (temp == "AND");

        temp.erase(remove(temp.begin(), temp.end(), '"'), temp.end());

        if (temp[0] == ' ')
            temp = temp.substr(1, temp.size() - 1);

        transform(temp.begin(), temp.end(), temp.begin(), ::toupper);

        KWs.push_back(temp);
    }

    for (int i = 0; i < sites.size(); i++)
    {
        bool Flag(false);

        string URL = sites[i]->getURL();

        string keys;

        for (int j = 0; j < sites[i]->getKeywords().size(); j++)
            keys += sites[i]->getKeywords()[j] + " ";

        transform(keys.begin(), keys.end(), keys.begin(), ::toupper);

        for (int i = 0; i < KWs.size(); i++)
        {
            if (keys.find(KWs[i]) != string::npos)
                Flag = true;
        }

        if (Flag)
            if (results.find(URL) == string::npos)
            {
                results += URL + " ";
                res.push_back(sites[i]);
            }
    }

    if (results.empty())
        cout << "no results found!!\n";

    return res;
}

void Search::setSites(vector<webpage *> sites)
{
    this->sites = sites;
}