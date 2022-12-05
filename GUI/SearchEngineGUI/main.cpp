#include "screen.h"

#include <QApplication>
#include <iostream>

using std::string;

string getTillChar(string &, char);

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    screen w;
    w.show();
    return a.exec();
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
