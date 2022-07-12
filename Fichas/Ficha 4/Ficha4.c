#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/* FUNÇÕES SOBRE STRINGS */

// Exercicio 1

int contaVogais(char *s)
{
    int count = 0;
    while (*s != '\0')
    {
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U')
        {
            count++;
        }
        s++;
    }
    return count;
}

// Exercicio 2

int retiraVogaisRepAux(char *s) // Função com string auxiliar.
{
    int ret = 0;
    int len = strlen(s);
    char aux[len];
    int i = 0, j = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') && (s[i] == s[i + 1]))
        {
            ret++;
        }
        else
        {
            aux[j] = s[i];
            j++;
        }
    }
    strcpy(s, aux);
    return ret;
}

int retiraVogaisRep(char *s) // Função sem string aux.
{
    int ret = 0;
    int i = 0, j = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') && (s[i] == s[i + 1]))
        {
            ret++;
            for (j = i + 1; s[j] != '\0'; j++)
            {
                s[j] = s[j + 1];
            }
            i--;
        }
    }
    return ret;
}

// Exercicio 3

int duplicaVogaisAux(char *s) // Função que usa uma string aux.
{
    int acc = 0;
    int len = strlen(s);
    char aux[len * 2];
    int i = 0, j = 0;
    for (i = 0; s[i] != '\0'; i++)
    {
        if ((s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u'))
        {
            acc++;
            aux[j] = aux[j + 1] = s[i];
            j += 2;
        }
        else
        {
            aux[j] = s[i];
            j++;
        }
    }
    strcpy(s, aux);
    return acc;
}

int duplicaVogais(char *s) // Função que não usa uma string aux.
{
    int acc = 0;
    int i = 0, j = 0;
    int max = strlen(s);
    while (*s != '\0')
    {
        if (*s == 'a' || *s == 'e' || *s == 'i' || *s == 'o' || *s == 'u' || *s == 'A' || *s == 'E' || *s == 'I' || *s == 'O' || *s == 'U')
        {
            for (i = max; i > 0; i--)
            {
                s[i] = s[i - 1];
            }
            s++;
            acc++;
        }
        max--;
        s++;
    }

    return acc;
}

/* ARRAYS ORDENADOS */

// Exercicio 1

int ordenado(int a[], int N)
{
    int ord = 1;
    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            break;
        }
        if (a[i] > a[i + 1])
        {
            ord = 0;
            break;
        }
    }
    return ord;
}

// Exercicio 2

void merge(int a[], int na, int b[], int nb, int r[])
{
    int i = 0;
    int aPos = 0;
    int bPos = 0;
    int len = na + nb;
    for (i = 0; i < len; i++)
    {
        if (aPos >= na)
        {
            r[i] = b[bPos];
            bPos++;
        }
        else if (bPos >= nb)
        {
            r[i] = a[aPos];
            aPos++;
        }
        else if (b[bPos] > a[aPos])
        {
            r[i] = a[aPos];
            aPos++;
        }
        else
        {
            r[i] = b[bPos];
            bPos++;
        }
    }
}

// Exercicio 3

int partitionAux(int v[], int N, int x) //Uso de um array aux.
{
    int i = 0, j = 0;
    int count = 0;
    int aux[N];
    for (i = 0; i < N; i++)
    {
        if (v[i] <= x)
        {
            aux[j] = v[i];
            j++;
            count++;
        }
    }
    for (i = 0; i < N; i++)
    {
        if (v[i] > x)
        {
            aux[j] = v[i];
            j++;
        }
    }
    for (i = 0; i < N; i++)
    {
        v[i] = aux[i];
    }
    
    return count;
}

int partition(int v[], int N, int x) //Sem usar array auxiliar.
{
    int i = 0;
    int pos = 0;
    for (i = 0; i < N; i++)
    {
        if (v[i] <= x)
        {
            int temp = v[i];
            v[i] = v[pos];
            v[pos] = temp;
            pos++;
        }
    }
    return pos;
}