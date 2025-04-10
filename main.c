#include <stdio.h>

int main()
{
    long long base;
    long long exponent;
    long long modulus;
    long long result;

    printf("Aviso: não utilize números decimais, negativos ou zero como valores, caso contrário erros podem ocorrer.\n");
    printf("Base: ");
    scanf("%lld", &base);
    printf("Expoente: ");
    scanf("%lld", &exponent);
    printf("Módulo: ");
    scanf("%lld", &modulus);
    printf("\n");

    result = 1;
    base = base % modulus;

    for (long long i = 0; i < exponent; i++)
    {
        result = (result * base) % modulus;
    }

    printf("Resultado: %lld", result);

    return 0;
}