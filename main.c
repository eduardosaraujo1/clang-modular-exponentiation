#include <stdio.h>
#include <math.h>

int modularExponentiation(int exponent, int base, int modulo, int increment)
{
    if (increment == exponent)
    {
        return fmod(pow(base, increment), modulo);
    }

    return modularExponentiation(exponent, base, modulo, increment + 1);
}

int main()
{
    int result = modularExponentiation(200, 30, 100, 1);

    printf("%d", result);
}