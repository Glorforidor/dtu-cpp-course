#include <iostream>
#include "fraction.h"

fraction::fraction(int n, int d)
{
    numerator = n;
    denominator = d;
}

void fraction::add(fraction f)
{
    if (denominator == f.denominator)
    {
        numerator += f.numerator;
    }
    else
    {
        numerator = numerator * f.denominator + denominator * f.numerator;
        denominator = denominator * f.denominator;
    }

    if (numerator % 2 == 0 && denominator % 2 == 0)
    {
        numerator /= 2;
        denominator /= 2;
    }
}

void fraction::mult(fraction f)
{
    numerator *= f.numerator;
    denominator *= f.denominator;

    if (numerator % 2 == 0 && denominator % 2 == 0)
    {
        numerator /= 2;
        denominator /= 2;
    }
}

void fraction::div(fraction f)
{
    numerator *= f.denominator;
    denominator *= f.numerator;

    if (numerator % 2 == 0 && denominator % 2 == 0)
    {
        numerator /= 2;
        denominator /= 2;
    }
}

void fraction::display(void)
{
    std::cout << numerator << " / " << denominator << std::endl;
}