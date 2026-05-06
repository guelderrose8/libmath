#pragma once

#include "libmath.h"

#include <climits>

namespace libmath
{

inline int addition(int value1, int value2, int& result)
{
    if ((value2 > 0 && value1 > INT_MAX - value2) ||
        (value2 < 0 && value1 < INT_MIN - value2))
        return 4;
    result = value1 + value2;
    return 0;
}

inline int subtraction(int value1, int value2, int& result)
{
    if (value2 == INT_MIN && value1 >= 0)
        return 4;
    if ((value2 < 0 && value1 > INT_MAX + value2) ||
        (value2 > 0 && value1 < INT_MIN + value2))
        return 4;
    result = value1 - value2;
    return 0;
}

inline int multiplication(int value1, int value2, int& result)
{
    long long res = (long long)value1 * value2;
    if (res > INT_MAX || res < INT_MIN)
        return 4;
    result = (int)res;
    return 0;
}

inline int division(int value1, int value2, int& result)
{
    if (value2 == 0)
    {
        return -1;
    }
    if (value1 == INT_MIN && value2 == -1)
        return 4;
    result = value1 / value2;
    return 0;
}

inline int power(int value1, int value2, int& result)
{
    if (value2 < 0)
        return 2;
    result = 1;

#pragma unroll
    for (int i = 0; i < value2; ++i)
    {
        long long res = (long long)result * value1;
        if (res > INT_MAX || res < INT_MIN)
            return 4;
        result = (int)res;
    }
    return 0;
}

inline int factorial(int value, int& result)
{
    if (value < 0)
        return 3;
    if (value > 12)
        return 4;
    if (value == 0 || value == 1)
    {
        result = 1;
        return 0;
    }
    int prev = 0;
    int err = factorial(value - 1, prev);
    if (err != 0)
        return err;

    result = value * prev;
    return 0;
}

} // namespace libmath
