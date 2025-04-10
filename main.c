#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int read_line(char buffer[], int size)
{
    memset(buffer, 0, size);
    return fgets(buffer, size, stdin) != NULL;
}

void extract_digits(const char *input, char *output)
{
    int j = 0;
    // memset(digits, 0, sizeof(digits));
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isdigit(input[i]))
        {
            output[j++] = input[i];
        }
    }
    output[j] = '\0';
}

int parse_positive_long_long(const char *number, long long *value)
{
    if (number[0] == '\0')
        return 0; // number é vazio
    *value = strtoll(number, NULL, 10);
    return *value > 0; // zero não é positivo
}

void ler_inteiro_positivo(char prompt[], long long *value)
{
    const int buffer_len = 100;
    char buffer[buffer_len];
    char digits[buffer_len];

    while (1)
    {
        // print prompt
        printf("%s", prompt);

        // read answer from user
        if (!read_line(buffer, buffer_len))
        {
            printf("Ocorreu um erro ao ler sua entrada. Tente novamente\n");
            continue;
        }

        extract_digits(buffer, digits);

        if (!parse_positive_long_long(digits, value))
        {
            printf("O valor digitado deve ser um número inteiro positivo não zero. Por favor tente novamente.\n");
            continue;
        }

        break;
    }
}

int main()
{
    long long base;
    long long exponent;
    long long modulus;
    long long result;

    ler_inteiro_positivo("Base: ", &base);
    ler_inteiro_positivo("Expoente: ", &exponent);
    ler_inteiro_positivo("Módulo: ", &modulus);
    printf("\n");

    result = 1;
    base = base % modulus; // otimização

    for (long long i = 0; i < exponent; i++)
    {
        result = (result * base) % modulus;
    }

    printf("Resultado: %lld", result);

    return 0;
}