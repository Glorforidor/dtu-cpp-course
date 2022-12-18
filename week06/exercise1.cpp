#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include "fraction.h"

using namespace std;

vector<string> tokenise(string);

int main()
{
    vector<string> inputLines;
    string input;
    while (getline(cin, input))
    {
        inputLines.push_back(input);
    }

    for (auto line : inputLines)
    {
        auto tokens = tokenise(line);
        fraction f1(stoi(tokens[0]), stoi(tokens[1]));
        fraction f2(stoi(tokens[3]), stoi(tokens[4]));
        auto op = tokens[2];

        if (op == "+")
        {
            f1.add(f2);
        }
        else if (op == "*")
        {
            f1.mult(f2);
        }
        else if (op == "div")
        {
            f1.div(f2);
        }

        f1.display();
    }

    return 0;
}

vector<string> tokenise(string s)
{
    vector<string> tokens;
    istringstream ss(s);
    string tmp;
    while (getline(ss, tmp, ' '))
    {
        if (tmp == "/")
        {
            continue;
        }
        tokens.push_back(tmp);
    }

    return tokens;
}