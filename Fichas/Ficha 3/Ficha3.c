#include <stdio.h>

/*

Exercicio 1

(a)

int main ()
{
    int x [15] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15}; ---Declaração de um array de inteiros com os valores de 1 a 15.
    int *y, *z, i; ---Declaração de dois apontadores para inteiros y e z e uma váriavel de inteiros i.
    y = x; ---y aponta para o array x.
    z = x+3; ---z aponta para o terceiro elemento do array.
    for (i=0; i<5; i++)
    {
        printf ("%d %d %d\n", x[i], *y, *z);
        y = y+1;
        z = z+2;
    }
}

---OUTPUT:
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12

(b)

int main ()
{
    int i, j, *a, *b; ---Declaração de duas váriaveis de inteiros, i e j // Dois apontadores para inteiros a e b.
    i=3; j=5; ---Valor de i: 3 // Valor de j: 5.
    a = b = 42; ---Apontador a aponta para o mesmo valor de b. Valor apontado b.
    a = &i; b = &j; ---Apontador a aponta para o endereço de i, ou seja aponta para i. // Apontador b aponta para o endereço de j, ou seja aponta para j.
    i++; ---Valor de i: 4.
    j = i + *b; ---Valor de j: 4 + *b -> 4 + j -> 4 + 5 = 9.
    b = a; --- Apontador b agora aponta para o mesmo endereço que a, ou seja b aponta para i.
    j = j + *b; ---Valor de j: 9 + *b -> 9 + i -> 9 + 4 = 13.
    printf ("%d\n", j); ---OUTPUT: 13
    return 0;
}


*/

// Exercicio 2

void swapM(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Exercicio 3

void swap1(int v[], int i, int j)
{
    int temp = v[i];
    *(v + i) = *(v + j); //É equivalente a *v[i] = *v[j]; (Apesar de esta declaração ser errada.)
    *(v + j) = temp;
}

// Tambem podemos usar a função swapM.
void swap2(int v[], int i, int j)
{
    swapM(&v[i], &v[j]);
}

// Exercicio 4

int soma(int v[], int N)
{
    int soma = 0;
    for (int i = 0; i < N; i++)
    {
        soma += v[i];
    }
    return soma;
}

// Exercicio 5

void inverteArray1(int v[], int N)
{
    int len = N - 1;
    for (int i = 0; i < N / 2; i++)
    {
        swap1(v, i, len);
        len--;
    }
}

void inverteArray2(int v[], int N)
{
    int len = N - 1;
    for (int i = 0; i < N / 2; i++)
    {
        swapM(&v[i], &v[len]);
        len--;
    }
}

// Exercicio 6

int maximum(int v[], int N, int *m)
{
    if (N > 0)
    {
        for (int i = 0; i < N; i++)
        {
            if (v[i] > *m)
            {
                *m = v[i];
            }
        }
        return 0;
    }
    return 1;
}

// Exercicio 7

void quadrados1(int q[], int N)
{
    for (int i = 0; i < N; i++)
    {
        q[i + 1] = q[i] + 2 * i + 1;
    }
}

void quadrados2(int q[], int N)
{
    for (int i = 0; i < N; i++)
    {
        q[i] = i * i;
    }
}

//Exercicio 8

// (a)

void pascal(int v[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        v[i - 1] = 1;
        for (int j = i - 2; j > 0; j--)
        {
            v[j] = v[j] + v[j - 1];
        }
    }
    
}

// (b)

void printPascal(int N)
{
    for (int i = 1; i <= N; i++)
    {
        int v[i];
        pascal(v,i);
        for (int j = 0; j < i; j++)
        {
            printf("%d ",v[j]);
        }
        putchar('\n');
    }
    
}