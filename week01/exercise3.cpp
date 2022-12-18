#include <iostream>
#include <string>

int main()
{
    int x, y;
    scanf("%d", &x);
    scanf("%d", &y);

    std::string output;
    if (x == y)
    {
        output = " is equal to ";
    }
    else if (x < y)
    {
        output = " is smaller than ";
    }
    else if (x > y)
    {
        output = " is bigger than ";
    }
    else
    {
        output = "ERROR!";
    }

    std::cout << x << output << y << std::endl;
}