#include <iostream>
#include "ex01-library.h"
using namespace std;

// Task 1(a).  Implement this function
Complex **createMatrix(unsigned int m, unsigned int n, Complex c)
{
    // Initialise the matrix.
    Complex **matrix = new Complex *[m];
    for (unsigned int i = 0; i < m; i++)
    {
        matrix[i] = new Complex[n];
    }

    // Assign complex number to the matrix.
    for (unsigned int row = 0; row < m; row++)
    {
        for (unsigned int col = 0; col < n; col++)
        {
            matrix[row][col] = c;
        }
    }

    return matrix;
}

// Task 1(b).  Implement this function
void displayMatrix(Complex **A, unsigned int m, unsigned int n)
{
    for (unsigned int row = 0; row < m; row++)
    {
        for (unsigned int col = 0; col < n; col++)
        {
            // Get the complex number from the matrix.
            Complex c = A[row][col];
            // The sign of the imaginary part.
            string sign = "";
            if (c.im >= 0)
            {
                sign = "+";
            }

            cout << c.re << sign << c.im << "i";

            // Do not add space to last element.
            if (col != n - 1)
            {
                cout << " ";
            }
        }
        cout << endl;
    }
}

// Task 1(c).  Implement this function
Complex **createIdentityMatrix(unsigned int n)
{
    // Create matrix with all complex numbers zero valued.
    Complex **matrix = createMatrix(n, n, {0, 0});

    // Could just use row without col, but makes the intend clear.
    for (unsigned int row = 0, col = 0; row < n; row++, col++)
    {
        matrix[row][col] = {1, 0};
    }

    return matrix;
}

// Task 1(d).  Implement this function
void multMatrix(Complex **A, Complex **B, Complex **C,
                unsigned int m, unsigned int n, unsigned int p)
{
    for (unsigned int i = 0; i < m; i++)
    {
        for (unsigned int j = 0; j < p; j++)
        {
            // Clear data in the matrix C.
            C[i][j] = {0, 0};
            for (unsigned int k = 0; k < n; k++)
            {
                C[i][j] = add(C[i][j], mult(A[i][k], B[k][j]));
            }
        }
    }
}

// Do not modify
Complex add(Complex c, Complex d)
{
    Complex result = {c.re + d.re, c.im + d.im};
    return result;
}

// Do not modify
Complex mult(Complex c, Complex d)
{
    Complex result;
    result.re = (c.re * d.re) - (c.im * d.im);
    result.im = (c.re * d.im) + (c.im * d.re);
    return result;
}

// Do not modify
void deleteMatrix(Complex **A, unsigned int nRows)
{
    for (unsigned int i = 0; i < nRows; i++)
    {
        delete[] A[i];
    }
    delete[] A;
}
