#include <stdio.h>
#include <math.h>

int modularExponentiation(int exponent, int base, int modulo)
{
    printf("Starting function call with exponent=%d, base=%d, modulo=%d\n", exponent, base, modulo);
    if (exponent == 1)
    {
        return base % modulo;
    }

    int expo = modularExponentiation(exponent / 2, base, modulo);
    int result = (expo * expo) % modulo;

    if (exponent % 2 == 1)
    {
        result *= base;
        result = result % modulo;
    }
    printf("Result is %d\n", result);

    return result;
}

int main()
{
    int result = modularExponentiation(5, 50, 101);

    printf("Final Response: %d\n", result);
}