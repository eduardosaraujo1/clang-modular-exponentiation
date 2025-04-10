#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_LEN 100

void ler_inteiro_positivo(char prompt[], long long *value)
{
    char buffer[BUFFER_LEN];
    char digits[BUFFER_LEN];

    int success = 0;

    while (success == 0)
    {
        // print prompt
        printf("%s", prompt);

        // read answer from user
        memset(buffer, 0, sizeof(buffer));
        if (fgets(buffer, BUFFER_LEN, stdin) == NULL)
        {
            printf("Ocorreu um erro ao ler sua entrada. Tente novamente\n");
            continue;
        }

        // replace \n with \0
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (buffer[i] == '\n')
            {
                buffer[i] = '\0';
                break;
            }
        }

        // remove invalid characters
        int j = 0;

        memset(digits, 0, sizeof(digits));
        for (int i = 0; buffer[i] != '\0'; i++)
        {
            if (isdigit(buffer[i]))
            {
                digits[j++] = buffer[i];
            }
        }

        // if j is null, probably the string had no numbers
        if (j <= 0)
        {
            printf("O valor digitado deve ser um número inteiro positivo. Por favor tente novamente.\n");
            continue;
        }

        // parse digits to long long
        *value = strtoll(digits, NULL, 10);

        if (*value <= 0)
        {
            printf("O valor digitado não pode ser 0. Por favor tente novamente.\n");
            continue;
        }

        // end the loop
        success = 1;
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