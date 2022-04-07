#include <stdio.h>
#include <string.h>

// Exercicio 1

void maiorElemSeq()
{
    int num;
    int maior = 0;
    printf("Insere uma sequencia de numeros 1 por linha terminada em 0:\n");
    while (1)
    {
        if (scanf("%d", &num) == 1)
        {
            if (num == 0)
            {
                break;
            }
            if (num > maior)
            {
                maior = num;
            }
        }
    }
    printf("Maior da seq.: %d\n", maior);
}

// Exericico 2

void mediaSeq()
{
    int contagem = 0;
    int soma = 0;
    int num;
    printf("Insere uma sequencia de numeros 1 por linha terminada em 0:\n");
    while (1)
    {
        if (scanf("%d", &num) == 1)
        {
            if (num == 0)
            {
                break;
            }

            soma += num;
            contagem++;
        }
    }
    float media = soma / contagem;
    printf("A media da sequencia é: %f\n", media);
}

// Exercicio 3

void segMaiorSeq()
{
    int maior = 0;
    int segmaior = 0;
    int num;
    while (1)
    {
        printf("Insere uma sequencia de numeros 1 por linha terminada em 0:\n");
        if (scanf("%d", &num) == 1)
        {
            if (num == 0)
            {
                break;
            }

            if (num > segmaior)
            {
                if (num > maior)
                {
                    segmaior = maior;
                    maior = num;
                }
                else
                {
                    segmaior = num;
                }
            }
        }
    }
    printf("O segundo maior da sequencia é: %d\n", segmaior);
}

// Exercicio 4

int bitsUm(unsigned int n)
{
    int r = 0;
    while (n >= 1)
    {
        r += (n % 2);
        n /= 2;
    }
    return r;
}

// Exercicio 5

int trailingZ(unsigned int n)
{
    if (n % 2)
        return 0;
    else
        return 1 + trailingZ(n >> 1);
}

// Exercicio 6

int qDig(unsigned int n)
{
    int count = 0;
    while (n >= 1)
    {
        n /= 10;
        count++;
    }
    return count;
}

// Exercicio 7

char *mystrcat(char s1[], char s2[])
{
    while (*s1)
    {
        s1++;
    }
    while (*s1 = *s2)
    {
        s1++;
        s2++;
    }
    return s1;
}

// Exercicio 8

char *mystrcpy(char s1[], const char s2[])
{
    while (*s1 = *s2)
    {
        s1++;
        s2++;
    }
    return s1;
}

// Exercicio 9

int mystrcmp(char s1[], char s2[])
{
    int flag = 0;
    while (*s1 == *s2)
    {
        s1++;
        s2++;
    }
    flag = (*s1) - (*s2);
    return flag;
}

// Exercicio 10

char *mystrstr(char s1[], char s2[])
{
}

// Exercicio 11

void mystrrev(char s[])
{
    int tamanho = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        tamanho++;
    }
    char aux[tamanho];
    for (int i = 0; i < tamanho; i++)
    {
        aux[i] = s[tamanho - i - 1];
    }
    for (int i = 0; i < tamanho; i++)
    {
        s[i] = aux[i];
    }
}

// Exercicio 12

void strnoV(char s[])
{
    int tam = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        tam++;
    }
    for (int i = 0; i < tam; i++)
    {
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
        {
            for (int j = i; s[j] != '\0'; j++)
            {
                s[j] = s[j + 1];
                i--;
            }
        }
    }
}

// Exercicio 13

void truncW(char t[], int n)
{
      //  printf("HERE");
      int tamPL = 0;
    while (*t)
    {
        if (*t == ' ' || *t == '\n')
        {
            tamPL = 0;
            t++;
        }
        else
        {
            if (tamPL++ >= n)
            {
                for ( ; *t; t++)
                {
                    *t = *(t+1);
                    t+=2;
                }
            }
            else t++;
        }
        
    }
    
}

int main()
{
    char s1[] = "liberdade, igualdade e fraternidade";
    // char s2[] = {'A', 'E', 'I', 'o', 'u'};
    truncW(s1, 4);
    printf("%s", s1);
    return 0;
}
