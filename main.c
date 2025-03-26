#include <stdio.h>

int main()
{
    long long base;
    long long exponent;
    long long modulus;

    // USER INPUT
    printf("Base: ");
    scanf("%lld", &base);
    printf("Expoente: ");
    scanf("%lld", &exponent);
    printf("Módulo: ");
    scanf("%lld", &modulus);
    printf("\n");

    // EVALUATE base^exponent % modulus
    long long accumulator = 1;
    for (long long i = 0; i < exponent; i++)
    {
        accumulator = (accumulator * base) % modulus;
    }

    // PRINT RESULT
    printf("Resultado: %lld", accumulator);

    return 0;
}