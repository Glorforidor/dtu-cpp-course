#include <algorithm>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
#include <vector>

using namespace std;

vector<string> tokenise(string s);

int main()
{
    string input;
    getline(cin, input);

    auto tokens = tokenise(input);

    multiset<double> bag;

    for (int i = 0; i < tokens.size(); i += 2)
    {
        string cmd = tokens[i];
        if (cmd == "quit")
        {
            break;
        }
        double number = stod(tokens[i + 1]);

        if (cmd == "add")
        {
            bag.insert(number);
        }
        else if (cmd == "del")
        {
            auto found = bag.find(number);
            if (found != bag.cend())
            {
                bag.erase(found);
            }
        }
        else if (cmd == "qry")
        {
            bool inBag = find(bag.cbegin(), bag.cend(), number) != bag.cend();
            if (inBag)
            {
                cout << "T";
            }
            else
            {
                cout << "F";
            }
        }
    }

    cout << endl;

    return 0;
}

vector<string> tokenise(string s)
{
    vector<string> tokens;

    stringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ' '))
    {
        tokens.push_back(tmp);
    }

    return tokens;
}