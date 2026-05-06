#pragma once

#include "libmath.h"

#include <climits>

namespace libmath
{

inline int addition(int a, int b, int& c)
{
    if ((b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b))
        return 4;
    c = a + b;
    return 0;
}

inline int subtraction(int a, int b, int& c)
{
    if (b == INT_MIN && a >= 0)
        return 4;
    if ((b < 0 && a > INT_MAX + b) || (b > 0 && a < INT_MIN + b))
        return 4;
    c = a - b;
    return 0;
}

inline int multiplication(int a, int b, int& c)
{
    long long res = (long long)a * b;
    if (res > INT_MAX || res < INT_MIN)
        return 4;
    c = (int)res;
    return 0;
}

inline int division(int a, int b, int& c)
{
    if (b == 0)
    {
        return -1;
    }
    if (a == INT_MIN && b == -1)
        return 4;
    c = a / b;
    return 0;
}

inline int power(int a, int b, int& c)
{
    if (b < 0)
        return 2;
    c = 1;

#pragma unroll
    for (int i = 0; i < b; ++i)
    {
        long long res = (long long)c * a;
        if (res > INT_MAX || res < INT_MIN)
            return 4;
        c = (int)res;
    }
    return 0;
}

inline int factorial(int a, int& c)
{
    if (a < 0)
        return 3;
    if (a > 12)
        return 4;
    if (a == 0 || a == 1)
    {
        c = 1;
        return 0;
    }
    int prev = 0;
    int err = factorial(a - 1, prev);
    if (err != 0)
        return err;

    c = a * prev;
    return 0;
}

} // namespace libmath
