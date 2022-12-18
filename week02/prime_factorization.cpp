#include <iostream>

using namespace std;

bool isPrime(int n);

int main()
{
    int n;
    cin >> n;

    for (int i = 0; n != 1;)
    {
        if (!isPrime(i) || n % i != 0)
        {
            i++;
            continue;
        }

        cout << i;
        n /= i;
        if (n != 1)
        {
            cout << " * ";
        }
        else
        {
            cout << endl;
        }
    }

    return 0;
}

bool isPrime(int n)
{
    if (n == 0 || n == 1)
    {
        return false;
    }

    bool isPrime = true;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
        {
            isPrime = false;
            break;
        }
    }

    return isPrime;
}
