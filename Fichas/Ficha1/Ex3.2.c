#include <stdio.h>

int main() {
    int x;
    if (scanf("%d",&x) == 1) {
        //codigo aqui
    }
    return 0;
}

void linhaXadrex(char x, char y, int n) {
    int i = 0;
    while (i < (n-1)/2) { // n=6 i<2 n=5 i<2
        putchar(x);putchar(y);
        i++;
    }
    //final
    putchar(x);
    if (n/2 == 0)
        putchar(y);
}

void xadrez (int n) {
    int linha = 0;
    while(linha <n) {
        if linha()
    }
}