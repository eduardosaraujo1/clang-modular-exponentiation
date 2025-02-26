#include <stdio.h>
#include <math.h>

long long modularExponentiation(long long exponent, long long base, long long modulo)
{
    if (exponent == 1)
    {
        return base % modulo;
    }

    long long expo = modularExponentiation(exponent / 2, base, modulo);
    long long result = (expo * expo) % modulo;

    if (exponent % 2 == 1)
    {
        result = (result * base) % modulo;
    }

    return result;
}

int main()
{
    // Ask user what base is
    // Ask user what modulo is
    // While true, accept user input on the exponent, and
    long long result = modularExponentiation(5, 50, 101);

    printf("Final Response: %lld\n", result);
}