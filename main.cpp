#include <iostream>

using namespace std;

// copy by value
// so we only shift the pointers to point to another address
// within the scope of swap.
void swap(int *x, int *y)
{
    int *z = x;
    x = y;
    y = z;
}

// copy by value
// here we swap as we change the value at the address of the pointers
// therefore making the change to x and y.
void swap_classic(int *x, int *y)
{
    int tmp = *x;
    *x = *y;
    *y = tmp;
}

// copy by reference
// we are not copying the value of the x and y but where they are referenced,
// which mean we change their values.
void swap_modern(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}

template <class T>
T mymax(T a, T b)
{
    if (a < b)
    {
        return b;
    }

    return a;
}

template <>
int mymax(int a, int b)
{
    return a + b;
}

int main()
{
    int x = 10;
    int y = 20;
    swap(&x, &y);

    cout << &x << " " << &y << endl;
    cout << x << " " << y << endl;

    swap_classic(&x, &y);

    cout << &x << " " << &y << endl;
    cout << x << " " << y << endl;

    swap_modern(x, y);

    cout << &x << " " << &y << endl;
    cout << x << " " << y << endl;

    cout << mymax<int>(2, 3) << endl;

    int **t = new int*[10];
    for (int i = 0; i < 10; i++)
    {
        t[i] = new int[10];
    }

    cout << t[9] << endl;
    return 0;
}
