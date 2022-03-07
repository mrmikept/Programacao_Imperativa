#include <stdio.h>
//Baseado no exercicio 1. 2) da ficha 1.
int main() {
    int x, y;
    int nova;
    x= 6; 
    y= 5;
    if (x>y) {
        nova = x;
        x=y;
        y=nova;
    }
    printf ("%d %d\n", x, y);
    return 0; 
}