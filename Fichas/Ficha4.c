#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

// Funções sobre Strings

// Exercicio 1

int contaVogais(char *s)
{
    int contagem = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            contagem++;
        }
    }
    return contagem;
}

int contaVogaisC(char *s)
{ // maneira mais compacta
    int contaV = 0;
    for (int i = 0; s[i] != 0; i++)
    {
        s[i] = tolower(s[i]);
        if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            contaV++;
        }
    }
    return contaV;
}

// Exercicio 2

int retiraVogaisRep(char *s)
{
    int vogRet = 0;
    char aux[50];
    int j = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == s[i + 1])
        {
            vogRet++;
        }
        else
        {
            aux[j] = s[i];
            j++;
        }
    }
    strcpy(s, aux); // função que copia o array auxiliar para o array argumento.
    return vogRet;
}

int retiraVogaisRep2(char *s)
// função que não usa um array auxiliar
{
    int vogRet = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == s[i + 1])
        {
            // se s[i] == s[i+1] então ele copia todos os elementos da string uma casa para trás decrementando o i.
            for (int j = i + 1; s[j] != '\0'; j++)
            {
                s[j] = s[j + 1];
            }
            i--;
            vogRet++;
        }
    }
    return vogRet;
}

// Exercicio 3

int duplicaVogais(char *s)
{
    int tamanhoStringArg = strlen(s);
    char aux[tamanhoStringArg * 2];
    int j = 0, vogAdd = 0;
    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            aux[j] = aux[j + 1] = s[i];
            j += 2;
            vogAdd++;
        }
        else
        {
            aux[j] = s[i];
            j++;
        }
    }
    strcpy(s, aux);
    return vogAdd;
}

int duplicaVogais2(char *s)
// Esta função duplica as vogais sem necessitar de um array auxiliar
{
    int vogAdd = 0;
    for (int i = 0; s[i + 1] && s[i] != '\0'; i++)
    {
        if (s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U' || s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u')
        {
            char c = ' ';
            for (int j = i; s[j + 1] && s[j] != '\0'; j++)
            {
                char c2 = s[j + 1];
                s[j + 1] = c;
                c = c2;
            }
            // printf("%s", s);
            s[i + 1] = s[i];
            i++;
            vogAdd++;
        }
    }
    return vogAdd;
}

// Arrays ordenados

// Exercicio 1

int ordenado(int v[], int N)
{
    int flag = 0;
    for (int i = 0; i < N; i++)
    {
        if (v[i] > v[i + 1])
        {
            flag = 1;
            break;
        }
    }
    return flag;
}

// Exercicio 2

void merge(int a[], int na, int b[], int nb, int r[])
{
    for (int i = 0; i < na; i++)
    {
        r[i] = a[i];
    }
    for (int j = 0; j < nb; j++)
    {
        r[na] = b[j];
        na++;
    }
}

// Exercicio 3

int partition(int v[], int N, int x)
// uso de um array auxiliar.
{
    int contagem = 0;
    int aux[N];
    for (int i = 0; i < N; i++)
    {
        if (v[i] <= x)
        {
            aux[contagem] = v[i];
            contagem++;
        }
        else
        {
            
            
        }
    }
    for (int j = 0; j < N; j++)
    {
        v[j] = aux[j];
    }
    
    return contagem;
}

int main()
{
    int S = 10, x = 66;
    int s[] = {10, 30, 50, 40, 70, 60, 20, 80, 100, 90};
    int c = partition(s,S,x);
    for (int i = 0; i < S; i++)
    {
        printf("%d ", s[i]);
    }
    printf("\n");
    printf("%d",c);
    return 0;
}
