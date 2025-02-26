#include <stdio.h>
#include <math.h>

int modularExponentiation(int exponent, int base, int modulo)
{
    if (exponent == 1)
    {
        return base % modulo;
    }

    long long expo = modularExponentiation(exponent / 2, base, modulo);
    long long result = (expo * expo) % modulo;

    if (exponent % 2 == 1)
    {
        result *= base;
        result = result % modulo;
    }

    return result;
}

int main()
{
    int result = modularExponentiation(5, 50, 101);

    printf("Final Response: %d\n", result);
}