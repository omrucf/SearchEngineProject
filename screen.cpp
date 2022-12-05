#include "screen.h"

screen::screen()
{
    emptyString = "   ";
    emptyString[0] = '"';
    emptyString[1] = ' ';
    emptyString[2] = '"';

    s.setSites(g.getSites());

    g.checkPRs();
}

void screen::startingScreen()
{
    string keywords;

    vector<webpage *> output;

    char choice;
    char choicee;

    int i;

    std::cout << "\t\t\t\t\t\t\tWelcome!" << endl;

    do
    {
        if (choice != '1' && choice != '2')
        {
            std::cout << "\t\t  ======================================================================================" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                            Please choose from the following:                         ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                            1. New Search                                             ||" << endl
                      << "\t\t||                            2. Exit                                                   ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t  ======================================================================================" << endl
                      << "\t\t||                            " << endl
                      << "\t\t||                            " << endl
                      << "\t\t||___________________________Type here: ";

            cin >> choice;
        }

        clear();

        if (choice != '1' && choice != '2' && choice != '0')
        {
            std::cout << "\t\t  ======================================================================================" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                    INVALID INPUT                                     ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                  Please try again!                                   ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t  ======================================================================================" << endl;
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == '1')
        {
            std::cout << "\t\t||                            " << endl
                     << "\t\t||                            " << endl
                     << "\t\t||___________________________Search: ";

            getline(cin >> ws, keywords);

            if (keywords.find(emptyString) != string::npos ||
                (keywords.find("AND") != string::npos))
            {
                output = s.ANDSearch(keywords);
            }
            else if (keywords.find("OR") != string::npos)
            {
                output = s.ORSearch(keywords);
            }
            else if (keywords[0] == '"' && keywords[keywords.size() - 1] == '"')
            {
                output = s.QuoteSearch(keywords);
            }
            else
            {
                output = s.ORSearch(keywords);
            }

            std::sort(output.begin(),
                      output.end(),
                      [](webpage *lhs, webpage *rhs)
                      {
                          return lhs->getScore() > rhs->getScore();
                      });

            do
            {
                choicee = 0;

                if (output.size() > 0)
                {
                    cout << "\t\t  ======================================================================================" << endl
                         << "\t\t||                                                                                      ||" << endl
                         << "\t\t||              select any website you want, make a new search, or exit:                ||" << endl
                         << "\t\t||                                                                                      ||" << endl;

                    for (int j = 0; j < output.size(); j++)
                    {
                        output[j]->setImpressions(output[j]->getImpressions() + 1);

                        cout << "\t\t||              " << j + 1 << ". " << output[j]->getURL() << endl;

                        output[j]->calculateScore();
                    }
                }
                else
                {
                    clear();

                    cout << "\t\t  ======================================================================================" << endl
                         << "\t\t||                                                                                      ||" << endl
                         << "\t\t||                                                                                      ||" << endl
                         << "\t\t||                                                                                      ||" << endl
                         << "\t\t||                                  No results found!                                   ||" << endl
                         << "\t\t||                                                                                      ||" << endl;
                }

                    cout << "\t\t||              " << output.size() + 1 << ". New search                                                           ||" << endl
                         << "\t\t||              " << output.size() + 2 << ". Exit                                                                 ||" << endl;

                    cout << "\t\t||                                                                                      ||" << endl
                         << "\t\t||                                                                                      ||" << endl
                         << "\t\t  ======================================================================================" << endl
                        << "\t\t||                            " << endl
                        << "\t\t||                            " << endl
                        << "\t\t||___________________________Type here: ";

                cin >> i;

                if (i > 0 && i <= output.size())
                {
                    choicee = '0';

                    clear();

                    cout << "\t\t  ======================================================================================" << endl
                         << "\t\t||                                                                                      ||" << endl
                         << "\t\t||                      You are now viewing " << output[i - 1]->getURL() << " !" << endl
                         << "\t\t||                                                                                      ||" << endl
                         << "\t\t  ======================================================================================" << endl;

                    output[i - 1]->print();
                    output[i - 1]->setClicks(output[i - 1]->getClicks() + 1);
                    output[i - 1]->calculateScore();

                    std::cout << "\t\t  ======================================================================================" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                            Please choose from the following:                         ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                            1. Back to search results                                 ||" << endl
                      << "\t\t||                            2. New search                                             ||" << endl
                      << "\t\t||                            3. Exit                                                   ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t  ======================================================================================" << endl
                      << "\t\t||                            " << endl
                      << "\t\t||                            " << endl
                      << "\t\t||___________________________Type here: ";

                    cin >> choicee;

                    if (choicee != 1)
                        choice = choicee - 1;

                    clear();
                }
                else if (i == output.size() + 1)
                    choice = '1';
                else if (i == output.size() + 2)
                    choice = '2';
                else
                {
                    choice = '0';
                     std::cout << "\t\t  ======================================================================================" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                    INVALID INPUT                                     ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                               Please try again later!                                ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t  ======================================================================================" << endl;
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            } while (choicee == '1');
        }

    } while (choice != '2');

    clear();

   std::cout << "\t\t  ======================================================================================" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                      THANK YOU FOR CHOOSING OUR SEARCH EGNING!                       ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                      GOOD BYE!                                       ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t||                                                                                      ||" << endl
                      << "\t\t  ======================================================================================" << endl;
}