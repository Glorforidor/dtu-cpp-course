#ifndef __v2d__
#define __v2d__

#include <cmath>
#include <cstdarg>

template <typename T, unsigned int N>
class v2d
{
public:
    // standard constructor
    // builds a vector (a,b)

    v2d(T a...);

    // copy constructor
    // builds a vector that is exactly as v
    v2d(const v2d &v);

    // destructor
    ~v2d(void);

    // assignment
    // updates the vector to make it as v
    v2d &operator=(const v2d &v);

    // vector addition
    // updates the vector by adding v
    v2d &operator+(const v2d &v);

    // scalar multiplication
    // updates the vector by scaling by k
    v2d &operator*(T k);

    // scalar product of the current vector
    // by another vector v
    T operator*(const v2d &v);

    // computes the length of a vector
    double length(void);

private:
    // internal representation of a vector
    // with just two doubles x and y
    T val[N];
};

template <typename T, unsigned int N>
inline v2d<T, N>::v2d(T a...)
{
    val[0] = a;
    va_list args;
    va_start(args, a);
    for (unsigned int i = 1; i < N; i++)
    {
        val[i] = va_arg(args, T);
    }
    va_end(args);
}

template <typename T, unsigned int N>
inline v2d<T, N>::~v2d()
{
    // nothing special to clean up here!
}

template <typename T, unsigned int N>
inline v2d<T, N>::v2d(const v2d &v)
{
    for (unsigned int i = 0; i < N; i++)
    {
        val[i] = v.val[i];
    }
}

template <typename T, unsigned int N>
inline v2d<T, N> &v2d<T, N>::operator=(const v2d &v)
{
    for (unsigned int i = 0; i < N; i++)
    {
        val[i] = v.val[i];
    }

    return *this;
}

template <typename T, unsigned int N>
inline v2d<T, N> &v2d<T, N>::operator+(const v2d &v)
{
    for (unsigned int i = 0; i < N; i++)
    {
        val[i] += v.val[i];
    }

    return *this;
}

template <typename T, unsigned int N>
inline T v2d<T, N>::operator*(const v2d &v)
{

    T tmp = 0;
    for (unsigned int i = 0; i < N; i++)
    {
        tmp += this->val[i] * v.val[i];
    }

    return tmp;
}

template <typename T, unsigned N>
inline v2d<T, N> &v2d<T, N>::operator*(T k)
{

    for (unsigned int i = 0; i < N; i++)
    {
        val[i] *= k;
    }

    return *this;
}

template <typename T, unsigned int N>
inline double v2d<T, N>::length()
{
    return sqrtf64(*this * *this);
}

#endif