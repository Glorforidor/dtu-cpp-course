#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    multiset<int> a;
    multiset<int> b;

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
            a.insert(number);
        }
        else if (input == 'b')
        {
            cin >> input;
            int number = atoi(&input);
            b.insert(number);
        }
    }

    // write into a string stream
    stringstream ss;

    for (auto &i : a)
    {
        ss << i << " ";
    }
    for (auto &i : b)
    {
        ss << i << " ";
    }

    // lets remove the last whitespace
    auto s = ss.str();
    s.erase(s.length() - 1, 1);

    cout << s << endl;

    return 0;
}