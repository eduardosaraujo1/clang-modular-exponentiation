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

long long askPositiveNumber(char prompt[])
{
    long long response = 0;

    // read response
    int valid = 0;
    do
    {
        printf("%s", prompt);

        if (scanf("%lld", &response) == 1 && response > 0)
        {
            valid = 1;
        }
        else
        {
            puts("Valor inválido. Tente novamente");
            int ch;
            while ((ch = getchar()) != '\n' && ch != EOF)
                ;
        }
    } while (!valid);

    return response;
}

int main()
{
    long long base = askPositiveNumber("Calculation base: ");
    long long modulo = askPositiveNumber("Calculation modulo: ");
    long long result;
    long long exponent;
    while (1)
    {
        exponent = askPositiveNumber("Type in exponent: ");
        printf("Result: %lld\n", result);
    }
}