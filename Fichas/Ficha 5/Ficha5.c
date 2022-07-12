#include <stdio.h>
#include <string.h>

/*TODOS os exercicios foram testados na plataforma codeboard fornecida no enunciado da Ficha!*/

// Exercicio 1

int nota(Aluno a)
{
    int miniTestes = 0;
    for (int i = 0; i < 6; i++)
    {
        miniTestes += a.miniT[i];
    }
    int mediaMiniT = miniTestes / 6;
    int nota = (30 * mediaMiniT + 70 * a.teste) / 100;
    return nota;
}

// Exercicio 2

int procuraNum(int num, Aluno t[], int N)
{
    int indice = -1;
    int i = 0;
    for (i = 0; i < N; i++)
    {
        if (t[i].numero == num)
        {
            return i;
        }
    }
    return -1;
}

// Exercicio 3
void ordenaPorNum(Aluno t[], int N)
{
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (j == N - 1)
            {
                break;
            }
            if (t[j].numero > t[j + 1].numero)
            {
                Aluno temp = t[j];
                t[j] = t[j + 1];
                t[j + 1] = temp;
            }
        }
    }
}

// Exercicio 4

void criaIndPorNum(Aluno t[], int N, int ind[])
{
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        ind[i] = i;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (j == N - 1)
            {
                break;
            }
            if (t[ind[j]].numero > t[ind[j + 1]].numero)
            {
                int temp = ind[j];
                ind[j] = ind[j + 1];
                ind[j + 1] = temp;
            }
        }
    }
}

// Exercicio 5

void imprimeTurma(int ind[], Aluno t[], int N)
{
    int k;
    ordenaPorNum(t, N);
    for (k = 0; k < N; k++)
    {
        printf("Nº aluno: %d, Nome: %s, Nota: %d\n", t[ind[k]].numero, t[ind[k]].nome, nota(t[ind[k]]));
    }
}

// Exercicio 6

int procuraNumInd(int num, int ind[], Aluno t[], int N)
{
    int i;
    for (i = 0; t[i].numero != num; i++)
        ;

    if (i < N && t[i].numero == num)
    {
        return ind[i];
    }

    return -1;
}

// Exercicio 7

void criaIndPorNome(Aluno t[], int N, int ind[])
{
    int i = 0, j = 0;
    for (i = 0; i < N; i++)
    {
        ind[i] = i;
    }
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (j == N - 1)
            {
                break;
            }
            if (strcmp(t[ind[j]].nome , t[ind[j + 1]].nome) > 0)
            {
                int temp = ind[j];
                ind[j] = ind[j + 1];
                ind[j + 1] = temp;
            }
        }
    }
}
