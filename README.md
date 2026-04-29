# libmath

Simple math library for integer arithmetic operations.

## Overview

The library provides basic arithmetic functions.

## API

All functions are defined in namespace `libmath`.

### int addition(int value1, int value2, int& result)

Adds two integers.

---

### int subtraction(int value1, int value2, int& result)

Subtracts `value2` from `value1`.

---

### int multiplication(int value1, int value2, int& result)

Multiplies two integers.

---

### int division(int value1, int value2, int& result)

Divides `value1` by `value2`.

---

### int power(int value1, int value2, int& result)

Calculates `value1` raised to the power of `value2`.

---

### int factorial(int value, int& result)

Calculates factorial of a number.

---

## Return values

All functions return a status code:

| Code | Meaning |
|---:|---|
| `0` | Success |
| `-1` | Division by zero |
| `2` | Raising to a negative power |
| `3` | Factorial of a negative number |
| `4` | Type overflow |

---

## Example

```cpp
#include "libmath.h"

int result;

if (libmath::addition(2, 3, result) == 0)
{
    // result = 5
}
