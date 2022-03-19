// Exercicio 1

float multInt1(int n, float m)
{
    float r = 0;
    for (int i = 1; i <= n; i++)
    {
        r += m;
    }
    return r;
}

// Exercicio 2

float multInt2(int n, float m)
{
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

// Exercicio 3

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
}

// Exercicio 4

int mdc2(int a, int b)
{
    int div = 1;
    for (int i = 0; (a != 0 && b != 0); i++)
    {
        if (a > b)
        {
            // printf("HERE");
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

// Exercicio 5

int mdc3(int a, int b)
{
    int resto = 1, c;
    if (b > a)
    {
        c = b;
        b = a;
        a = c;
    }

    for (int i = 0; resto != 0; i++)
    {
        if (a % b == 0)
        {
            resto = b;
            break;
        }
        else
        {
            resto = a % b;
            a = b;
            b = resto;
        }
    }
    return resto;
}

// Exercicio 6 (a)

int fib1(int n)
{
    int somafib = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i < 2)
        {
            somafib = 1;
        }
        else
        {
            somafib = fib1(n - 1) + fib1(n - 2);
        }
    }
    return somafib;
}

// Exercicio 6 (b)

int fib2(int n)
{
    int somafib = 1;
    int vn1 = 1, vn2 = 1;
    for (int i = 2; i < n; i++)
    {
        vn2 += vn1;
        vn1 = vn2 - vn1;
        somafib = vn2;
    }
    return somafib;
}
