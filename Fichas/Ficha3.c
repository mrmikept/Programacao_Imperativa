#include <stdio.h>
#include <stdlib.h>

/*
Exercicio 1

(a)
Os outputs serão por ordem:
1 1 4
2 2 6
3 3 8
4 4 10
5 5 12
Justificação: O array está populado com os inteiros de 1 a 15 tendo de comprimento 14 (15 - 1), v[0] = 1, v[1] = 2, ..., v[14] = 15.
Depois do array é declarado os apontadores de inteiros y e z, e a variavel de inteiros i.
y = x -> basicamente o apontador y esta a apontar para v[0] = 1
z = x + 3 -> Aponta para a celula v[0] + 3 = v[3] = 4.
no ciclo de for, a cada iteração do ciclo fazemos print de v[i](que imprime os valores do array), o valor que o apontador y esta a "apontar" e o valor que o apontador
z esta a "apontar". No final de cada printf temos que y = y + 1(basicamente o apontador y passa a apontar para a proxima celula do array) e temos z = z + 2 (o apontador
z passa a apontar para a celula que esta duas casas à frente, exemplo no inicio z esta a apontar para v[3] e quando i = 1 z = v[5] = 6).

(b)

int main () {
  int i, j, *a, *b;

  i=3; j=5;
  a = b = 42;
  a = &i; b = &j;
  i++;
  j = i + *b;
  b = a;
  j = j + *b;
  printf ("%d\n", j);

  return 0;
}
Output = 13
Justificação: Inicialmente as variaveis i e j são declaradas com o valor 3 e 5 respectivamente de seguida os apontadores a e b apontam para a memoria com o endereço
42(completamente inutil), na próxima linha o apontador a começa a apontar para o endereço da variavel i e o apontador b aponta para o endereço da variavel j.
Seguidamente i é incrementado passando a ter o valor de i=4.
j = i + *b = 4 + 5 = 9. i tem o valor de 4 e o apontador b esta a "apontar" para j que tem o valor de 5, j = 9
b = a -> o apontador b passa a apontar tambem para i que tem o valor de 4.
j = j + *b = 9 + i = 9 + 4 = 13 -> Nesta fase j tem o valor de 9 e *b esta a apontar para o endereço de i(i = 4).
Finalmente é usado o printf para imprimir o valor de j que é 13.

*/

// Exercicio 2

void swapM(int *x, int *y)
{
    int c = *x;
    *x = *y;
    *y = c;
}

// Exercicio 3

void swap(int v[], int i, int j)
{
    int aux;
    aux = v[i];
    v[i] = v[j];
    v[j] = aux;
}

// Exercicio 4

int soma(int v[], int N)
{
    int soma = 0;
    for (int i = 0; i < 10; i++)
    {
        soma += v[i];
    }
    return soma;
}

// Exercico 5

void inverteArrayV1(int v[], int N) // usando a função swap que troca os elementos das celulas do array
{
    for (int i = 0; i < N / 2; i++)
    {
        swap(v, i, N - 1 - i);
    }
}

void inverteArrayV2(int v[], int N) // usando a função swapM que usa os endereços de memoria
{
    for (int i = 0; i < N / 2; i++)
    {
        swapM(v + i, v + N - 1 - i);
    }
}

// Exercicio 6

int maximum(int v[], int N, int *m)
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

// Exercicio 7

void quadrados(int q[], int N)
{
    for (int i = 0; i < N; i++)
    {
        q[i] = i * i;
    }
}

// Exercicio 8

// (a)

void pascal1(int v[], int N)
{
    for (int i = 1; i <= N; i++)
    {
        v[i - 1] = 1; // acrescenta 1 na posição N;
        for (int j = i - 2; j > 0; j--)
        {
            v[j] = v[j] + v[j - 1]; // desde N-1 até 1 é a soma de si proprio com o elemento anterior
        }
    }
}

// (b)

void pascal2(int v[], int N)
{
    if (N == 0)
    {
        v[0] = 1;
    }
    else
    {
        for (int i = 1; i <= N; i++)
        {
            v[i - 1] = 1; // acrescenta 1 na posição N;
            for (int j = i - 2; j > 0; j--)
            {
                v[j] = v[j] + v[j - 1]; // desde N-1 até 1 é a soma de si proprio com o elemento anterior
            }
        }
    }
    for (int j = 0; j < N; j++)
    {
        printf("%d ", v[j]);
    }
    printf("\n");
}

void drawPascal (int n) {
    //for (int i = 0; i < N; i++)
    //{
    //    int q[i+1];
    //    pascal2(q, i+1);
    //}
        for (int l = 1; l <= n; l++)
    {
        for (int c = 1; c <= n-l; c++)
        {
                putchar(' ');
        }
        for (int j=1; j<=2*l-1; j++)
        {
            int q[j+1];
            pascal2(q, j+1);
        }
        
        putchar('\n');
    }
    putchar('\n');
}

int main()
{
    int N = 10;
    drawPascal(N);
    return 0;
}
