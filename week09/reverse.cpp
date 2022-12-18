// Reverse
#include <iostream>
#include <string>

using namespace std;

void reverse()
{
    // base case
    if (cin.eof())
    {
        return;
    }

    string input;
    cin >> input;

    // recurse
    reverse();

    cout << input << " ";
}

int main()
{
    reverse();
    return 0;
}