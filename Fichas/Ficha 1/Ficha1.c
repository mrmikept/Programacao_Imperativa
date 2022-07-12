#include <stdio.h>
/*
PARTE 1 - Estados e atribuições

->Exercicio 1

int x, y; ---Declaração das váriaveis.
x = 3;  --- valor de x: 3.
y = x+1; --- valor de y: 3 + 1 = 4.
x = x*y; --- valor de x: 3 * 4 = 12.
y = x + y; --- valor de y: 12 + 4 = 16.
printf("%d %d\n", x, y); --- OUTPUT: "12 16"

->Exercicio 2

int x, y; ---Declaração das váriaveis.
x = 0; ---Valor de x: 0.
printf("%d %d\n", x, y); ---OUTPUT: "0, ?" (Como y é uma váriavel não iniciada então o seu valor é aleatorio, por normal será 0)

->Exercicio 3

char a, b, c; ---Declaração das váriaveis.
a = ’A’; ---Valor de a: (char)'A', (Int)65.
b = ’ ’; ---Valor de b: (char)' ', (Int)32.
c = ’0’; ---Valor de c: (char)'0', (Int)48
printf ("%c %d\n", a, a); ---OUTPUT: "A 65".
a = a+1; ---Valor de a: 65 + 1 = 66.
c = c+2; ---Valor de c: 48 + 2 = 50.
printf ("%c %d %c %d\n", a, a, c, c); ---OUTPUT: "B 66 2 50"
c = a + b; ---Valor de c: 66 + 32 = 98.
printf ("%c %d\n", c, c); ---OUTPUT: "b 98"

->Exercicio 4

int x, y; ---Declaração das váriaveis
x = 200; ---Valor de x: 200.
y = 100; ---Valor de y: 100.
x = x+y; ---Valor de x: 200 + 100 = 300.
y = x-y; ---Valor de y: 300 - 100 = 200.
x = x-y; ---Valor de x: 300 - 200 = 100.
printf ("%d %d\n", x, y); ---OUTPUT: "100 200"

PARTE 2 - Estruturas de controlo

->Exercicio (a)

int x, y; ---Declaração das váriaveis.
x = 3; ---Valor de x: 3.
y = 5; ---Valor de y: 5.
if (x > y) ---Se 3 > 5 (FALSO)
y = 6; ---Não muda o valor de y pois a condição do if é falsa.
printf ("%d %d\n", x, y); ---OUTPUT: "3 5"

->Exercicio (b)

int x, y; ---Declaração das váriaveis.
x = y = 0; ---Valor de x: 0 // Valor de y: 0.
while (x != 11) { ---Enquanto o valor de x for diferente de 11 então...
x = x+1; ---Soma a x mais 1.
y += x; ---Soma o valor de x a y.
}
printf ("%d %d\n", x, y); ---OUTPUT: "11 66"

->Exercicio (c)

int i; ---Declaração das váriaveis.
for (i=0; (i<20) ; i++) ---Para(valor inicial, condição de repetição, incremento da váriavel de controlo)
{
    if (i%2 == 0)  ---Se o resto da divisão do valor de i por 2 por igual a 0 então...
    {
        putchar (’_’); ---Dá output deste caracter.
    }
    else ---Caso contrário
    {
        putchar (’#’); ---Dá output deste caracter.
    }
}
---OUTPUT: "_#_#_#_#_#_#_#_#_#_#"
(Basicamente se o valor de i for par dá output de _, se for ímpar dá output de #)

->Exercicio (d)

void f (int n)
{
    while (n>0) ---Enquanto n for maior que 0...
    {
        if (n%2 == 0) putchar (’0’); ---Se o resto da divisão de n por 2 for igual a 0 então dá OUTPUT de '0'
        else putchar (’1’); ---Caso contrario dá OUTPUT de '1'.
        n = n/2; ---Divide o valor de n por 2 e repete o processo.
    }
    putchar (’\n’); ---No final do ciclo da output do caracter '\n'(Mudança de linha)
}

int main () ---Função main.
{
    int i; ---Declaração das váriaveis.
    for (i=0;(i<16);i++) ---Enquanto i for menor de 16 chama a função auxiliar f e incrementa i.
    {
        f (i); ---Chama a função f dando-lhe o valor de i como argumento.
    }
    return 0;
}

OUTPUT:
1
01
11
001
101
011
111
0001
1001
0101
1101
0011
1011
0111
1111

*/

// PARTE 3 - Programas iterativos

// Exercicio 1

void quadrado(int n)
{
    for (int l = 0; l < n; l++)
    {
        for (int c = 0; c < n; c++)
        {
            putchar('#');
        }
        putchar('\n');
    }
    putchar('\n');
}

// Exercicio 2

void xadrez(int n)
{                     // funcao que escreve no terminal um tabuleiro de xadrez (ex: #_#_#) de dimensão n
    int l = 0, c = 0; // l = numero de linhas // c = qual caracter
    for (l = 0; l < n; l++)
    {                           // ciclo de for que escreve cada linha
        for (c = 0; c < n; c++) // ciclo de for que decide qual caracter escrever( # ou _) conforme de o resto da divisão do numero da linha e coforme o resto da divisão de qual caracter com 2 for igual a 0
        {
            if ((l % 2 == 0 && c % 2 == 0) || (l % 2 != 0 && c % 2 != 0))
            /* Usamos estes operadores logicos para termos os simbolos # e _ alternados mesmo na mudança de linha, por exemplo quando o primeiro ciclo de for se inicia
            para escrever a primeira linha l = 0 e conforme cada caracter o segundo ciclo de for decide atravez da condição if se escreve um # ou _ , mas na segunda linha
            o primeiro caracter a aparecer tem de ser diferente do ultimo caracter da ultima linha escrita. Por exemplo, considerando que a primeira linha é l = 0, a segunda l = 1
            ou seja se l e c forem numeros pares então escreve # se ambos ou pelo menos um deles for impar escreve _.
            Na segunda linha (l=1) como o primeiro caracter (c=0) ambas as condições do If serão falsas e irá ser escrito um _ no ecra mas o segundo caracter tem de ser um # logo
            como l = 1 e c = 1 o resto da divisão de l e c com 2 vão ser AMBOS diferentes de 0 logo a condição do if statment será cumprida e será escrito um #. */
            {
                putchar('#');
            }
            else
            {
                putchar('_');
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

// Exercicio 3

void trianH(int n)
{
    for (int l = 1; l <= n; l++)
    {
        for (int c = 1; c <= n - l; c++)
        {
            putchar(' ');
        }
        for (int j = 1; j <= 2 * l - 1; j++)
        {
            putchar('#');
        }

        putchar('\n');
    }
    putchar('\n');
}

void trianV(int n)
{
    for (int l = 0; l < n * 2; l++)
    {
        for (int c = 0; c < 2 * n - l; c++)
        {
            if (c <= l)
            {
                putchar('#');
            }
        }
        putchar('\n');
    }
    putchar('\n');
}

// Exercicio 4

void circulo(int r)
{ // para fazer esta função vamos imaginar que o terminal é um eixo ortonormado xy onde a circunferencia tem centro (r,r) e diametro 2*r
    int chr = 0;
    for (int x = 0; x < r * 2 + 1; x++) // ciclo for que muda de linha
    {
        for (int y = 0; y < r * 2 + 1; y++) // ciclo for que em cada coluna decide qual caracter usar
        {
            float a = r - x;               // posição vertical
            float b = r - y;               // posição horizontal
            float c = sqrt(a * a + b * b); // formula da circunferencia
            if (c <= r)
            { // se o valor do c for menor ou igual a r escreve um # no ecrã se for maior que o r então coloca o caracter espaço.
                putchar('#');
                chr++;
            }
            else
            {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    putchar('\n');
    printf("O circulo tem %d caracteres '#'.\n", chr);
}

// Outra forma de fazer as mesmas funções

void linhaEsp(int n)
{ // função que imprime n espaços sucessivos.
    int i = 0;
    for (i = 0; i < n; i++)
    {
        putchar(' ');
    }
}

void linha(int n)
{              // Funcao que escreve n vezes o '#'
    int i = 0; // valor inicial
    while (i < n)
    { // condição de paragem.
        // açao a realizar por cada valor de i
        printf("#");
        // ---
        i++; // incremento ao i
    }
}

void quadrado(int n)
{
    int l = 0;
    while (l < n)
    {
        linha(n);
        putchar('\n');
        l++;
    }
}

void trianV(int n)
{
    int l = 0;
    for (l = 1; l < n; l++)
    {
        linha(l);
        putchar('\n');
    }
    linha(n);
    putchar('\n');
    for (l = n - 1; l > 0; l = l - 1)
    {
        linha(l);
        putchar('\n');
    }
}

void trianH(int n)
{
    int l = 0;     // valor inicial, numero da linha
    int e = n - 1; // e equivale ao numero de espaços por linha, se n=5 cada linha tem 4 espaços de cada lado da sequencia de #
    for (l = 0; l < n; l++)
    {
        linhaEsp(e);   // imprime n-1 espaços.
        linha(l);      // imprime l vezes o #.
        linha(1);      // imprime o eixo central de #.
        linha(l);      // imprime l vezes o # depois do eixo central.
        putchar('\n'); // muda de linha.
        e--;           // a cada linha o numero de espaços diminiu em 1.
    }
}