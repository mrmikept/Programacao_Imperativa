#include <stdio.h>

// Exercicio 1

float multInt1(int n, float m)
{
    float r = 0; // Declaramos uma váriavel com o valor inicial 0.
    int i = 1;
    for (i = 1; i <= n; i++) // Enquanto i for menor ou igual a n...
    {
        r += m; // Somamos o valor de m a r.
    }
    return r;
}

// Exercicio 2

float multInt2(int n, float m)
{
    float r = 0;   // Declaramos uma váriavel com o valor incial 0.
    while (n >= 1) // Enquanto n for maior ou igual 1...
    {
        if (n % 2 != 0) // Se o resto da divisão de n por 2 for diferente de 0(ou seja se n for ímpar)
        {
            r += m; // Soma o valor de m a r.
        }
        n = n / 2; // Divide o n por 2.
        m = m * 2; // Multiplica m por 2.
    }
    return r;
}

// Exercicio 3

int mdc1(int a, int b)
{
    int menor = a <= b ? a : b;      // Primeiro temos de saber qual o menor(short if condition).
    int div = 1;                     // Declaramos div com o divisor comum conhecido de qualquer número
    for (int i = 1; i <= menor; i++) // Enquanto i for menor ou igual ao menor
    {
        if (a % i == 0 && b % i == 0) // Verificamos se i é divisor de a e de b...
        {
            div = i; // Se for então damos o valor de i à variavel div.
        }
    }
    return div;
}

// Exercicio 4

int mdc2(int a, int b)
{
    while (a != 0 && b != 0) // Enquanto a e b forem diferentes de 0...
    {
        if (a < b) // Se a for menor que b...
        {
            b -= a; // Subtraimos o valor de a em b.
        }
        else // caso contrario...
        {
            a -= b; // Subtraimos o valor de b em a.
        }
    }
    int r = a != 0 ? a : b; // O valor de r usa uma short if statment.
    return r;
}

// Exercicio 5

int mdc3(int a, int b)
{
    int r = 0;     // Declaramos uma váriavel para guardar o valor do resto da divisão
    while (b != 0) // Enquanto b for diferente de 0...
    {
        r = a % b; // r é o resto da divisão de a com b.
        a = b;     // valor de a é igual a b.
        b = r;     // valor de b é igual a r.
    }
    return r;
}

// Exercicio 6

// (a)

int fib1(int n)
{
    int val = 0;
    if (n <= 0)
    {
        val = 0;
    }
    else if (n < 2)
    {
        val = 1;
    }
    else
    {
        val = fib1(n - 1) + fib1(n - 2);
    }
    return val;
}

// (b)

int fib2(int n)
{
    int val = 1;
    int n1 = 1, n2 = 1;
    for (int i = 2; i < n; i++)
    {
        n2 += n1;
        n1 = n2 - n1;
        val = n2;
    }
    return val;
}

