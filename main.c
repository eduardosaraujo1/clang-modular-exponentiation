#include <stdio.h>

int main()
{
    long long base;
    long long exponent;
    long long modulus;
    long long result;

    puts("Aviso: valores depois da vírgula serão ignorados e negativos se tornarão positivos");

    printf("Base: ");
    scanf("%lld", &base);
    printf("Expoente: ");
    scanf("%lld", &exponent);
    printf("Módulo: ");
    scanf("%lld", &modulus);
    printf("\n");

    // remover negativos
    base = base >= 0 ? base : -base;
    exponent = exponent >= 0 ? exponent : -exponent;
    modulus = modulus >= 0 ? modulus : -modulus;

    result = 1;
    base = base % modulus;

    for (long long i = 0; i < exponent; i++)
    {
        result = (result * base) % modulus;
    }

    printf("Resultado: %lld", result);

    return 0;
}