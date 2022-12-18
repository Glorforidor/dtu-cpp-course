#include <iostream>
#include <string>

int main()
{
    float x, y, z;
    scanf("%f", &x);
    scanf("%f", &y);
    scanf("%f", &z);

    std::cout << (x + y) - z << std::endl;
}