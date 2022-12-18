#pragma once

class fraction
{
private:
    int numerator;
    int denominator;

public:
    fraction(int n, int d);

    void add(fraction);
    void mult(fraction);
    void div(fraction);

    void display(void);
};