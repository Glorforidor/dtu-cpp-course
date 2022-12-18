#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool palindrome(vector<string> s)
{
    string forward = "";
    for (auto v : s)
    {
        forward += v;
    }

    string backward = "";
    for (auto r = s.rbegin(); r != s.rend(); r++)
    {
        backward += *r;
    }

    return forward == backward;
}

int main()
{
    vector<string> input;

    string s;
    while (cin >> s)
    {
        input.push_back(s);
    }

    if (palindrome(input))
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "no" << endl;
    }

    return 0;
}