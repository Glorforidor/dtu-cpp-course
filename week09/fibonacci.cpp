#include <iostream>
#include <vector>

using namespace std;

int fibonacci(int n, int current = 1, int next = 1)
{
    // base cases
    if (n == 0)
    {
        return current;
    }
    if (n == 1)
    {
        return next;
    }

    // tail recursive baby!
    return fibonacci(n - 1, next, current + next);
}

int main()
{

    vector<int> ints;

    int number;
    while (cin >> number)
    {
        ints.push_back(number);
    }

    for (auto i : ints)
    {
        cout << fibonacci(i) << " ";
    }

    return 0;
}