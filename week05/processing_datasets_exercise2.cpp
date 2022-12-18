#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    vector<int> a;
    vector<int> b;

    char input;
    while (cin.get(input))
    {
        // break loop on newline
        if (input == '\n')
        {
            break;
        }
        // lets ignore whitespace
        if (input == ' ')
        {
            continue;
        }

        switch (input)
        {
        case 'a':
            break;
        }
        if (input == 'a')
        {
            cin >> input;
            int number = atoi(&input);
            a.push_back(number);
        }
        else if (input == 'b')
        {
            cin >> input;
            int number = atoi(&input);
            b.push_back(number);
        }
    }

    // write into a string stream
    stringstream ss;

    if (a.size() < b.size())
    {
        int i = 0;
        for (; i < a.size(); i++)
        {
            ss << a[i] << " " << b[i] << " ";
        }

        for (; i < b.size(); i++)
        {
            ss << b[i] << " ";
        }
    }
    else if (a.size() > b.size())
    {
        int i = 0;
        for (; i < b.size(); i++)
        {
            ss << a[i] << " " << b[i] << " ";
        }

        for (; i < a.size(); i++)
        {
            ss << a[i] << " ";
        }
    }
    else
    {
        int i = 0;
        for (; i < a.size(); i++)
        {
            ss << a[i] << " " << b[i] << " ";
        }
    }

    // lets remove the last whitespace
    auto s = ss.str();
    s.erase(s.length() - 1, 1);

    cout << s << endl;

    return 0;
}