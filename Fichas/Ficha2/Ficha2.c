#include <stdio.h>

/*Exercicio 1

float multInt1 (int n, float m) {
    float r = 0;
    for (int i = 1; i <= n; i++)
    {
        r +=m;
    }
    return r;
}
*/

/* Exercicio 2

float multInt2(int n, float m) {
    float r = 0, i;
    for (i = 1; n != 0; i++)
    {
        if (n % 2 != 0)
        {
            r += m;
        }
        n /= 2;
        m *= 2;
    }
    return r;
}
*/

/* Exercicio 3

int mdc1(int a, int b)
{
    // Primeiro temos de descubrir qual o menor
    int menor = a <= b ? a : b;
    int divisor = 1;
    for (int i = 1; i < menor; i++)
    {
        if (a % i == 0 && b % i == 0)
        {
            divisor = i;
        }
    }
    return divisor;
} */

/* Exercicio 4*/

int mdc2(int a, int b)
{
    int div = 1;
    for (int i = 0; (a != 0 && b != 0); i++)
    {
        if (a > b)
        {
            //printf("HERE");
            a -= b;
        }
        else
        {
            b -= a;
        }
        if (a == 0)
        {
            div = b;
            break;
        }
        if (b == 0)
        {
            div = a;
            break;
        }
    }
    return div;
}

int main()
{
    int a = 12;
    int b = 9;
    // scanf("%i %f", &n, &m);
    int res = mdc2(a, b);
    printf("%d\n", res);
    return 0;
}
