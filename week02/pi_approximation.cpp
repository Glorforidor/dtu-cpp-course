#include <iostream>
#include <math.h>

double pi(int n);

using namespace std;

int main()
{
    int n;
    cin >> n;

    double res = pi(n);

    cout << res << endl;

    return 0;
}

double pi(int n)
{
    double approx = 0.0;
    for (int i = 0; i < n; i++)
    {
        double x = pow(-1, i);
        double y = 2 * i + 1;

        approx += x / y;
    }

    return approx * 4;
}