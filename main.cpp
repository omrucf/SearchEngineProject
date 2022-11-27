
#include "screen.h"
// #include "graph.h"

void clear();
string getTillChar(string &, char);

int main()
{
    // screen SS;

    // SS.startingScreen();

    graph test;

    test.readSites();

    test.Print();


    
   return 0;
}

void clear()
{
   system("clear");
}

string getTillChar(string &word, char c)
{
    string result = "";

    int i;

    for (i = 0; i < word.size() && word[i] != c; i++)
    {
        result += word[i];
    }
    if (i != word.size())
        word = word.substr(i + 1, word.size() - 1);
    else
    {
        result = word;
        word = "";
    }
    return result;
}