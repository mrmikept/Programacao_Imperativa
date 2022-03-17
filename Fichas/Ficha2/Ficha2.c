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

int main()
{
    int n;
    float m;
    scanf("%i %f", &n, &m);
    float res = multInt2(n, m);
    printf("%f\n", res);
    return 0;
}
