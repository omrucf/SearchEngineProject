#include "screen.h"

screen::screen()
{
    emptyString = "   ";
    emptyString[0] = '"';
    emptyString[1] = ' ';
    emptyString[2] = '"';

    s.setSites(g.getSites());
}

void screen::startingScreen()
{
    string keywords;

    vector<webpage *> output;

    char choice;
    char choicee;

    int i;

    std::cout << "Welcome!" << endl;

    do
    {
        if (choice != '1' && choice != '2')
        {
            std::cout << "\nPlease choose from the following:" << endl
                      << "1. New Search" << endl
                      << "2. Exit" << endl;

            cin >> choice;
        }

        clear();

        if (choice != '1' && choice != '2' && choice != '0')
        {
            std::cout << "*INVALID INPUT*\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else if (choice == '1')
        {
            std::cout << "\nSearch: ";

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
                output = s.ORSearch(keywords);
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

                cout << "select any website you want by typing its number: " << endl;

                for (int j = 0; j < output.size(); j++)
                {
                    output[j]->setImpressions(output[j]->getImpressions() + 1);

                    cout << j + 1 << ". " << output[j]->getURL() << endl;

                    output[j]->calculateScore();
                }

                cout << "or type:\n(" << output.size() + 1 << ") New search\n(" << output.size() + 2 << ") Exit" << endl;

                cin >> i;

                if (i > 0 && i <= output.size())
                {
                    choicee = '0';
                    clear();
                    cout << "You are now viewing " << output[i - 1]->getURL() << " !\n";

                    output[i - 1]->print();
                    output[i - 1]->setClicks(output[i - 1]->getClicks() + 1);

                    cout << "Would you like to :\n1. Back to search results\n2. New search\n3. Exit\n\n";

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
                    cout << "invlaid input!\nplease try again later!\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

            } while (choicee == '1');
        }

    } while (choice != '2');

    clear();

    std::cout << "\nThank You for using our search engine!\nGoodBye!\n";
}