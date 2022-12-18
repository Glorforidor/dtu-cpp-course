#include <iostream>
#include <vector>

using namespace std;

// addZeros adds n number of trailing zeros to the vector.
void addZeros(vector<int> &v, int n);

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

    auto difference = b.size() - a.size();

    if (a.size() < b.size())
    {
        addZeros(a, difference);
    }
    else if (a.size() > b.size())
    {
        addZeros(b, difference);
    }

    int sum = 0;
    for (int i = 0; i < a.size(); i++)
    {
        sum += a[i] * b[i];
    }

    cout << sum << endl;

    return 0;
}

void addZeros(vector<int> &v, int n)
{
    for (int i = 0; i < n; i++)
    {
        v.push_back(0);
    }
}