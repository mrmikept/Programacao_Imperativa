#include <stdio.h>

int main() {
    int x, y;
    x = 200; 
    y = 100;
    x = x+y; //200+100=300 <- x 
    y = x-y; // 300 - 100 = 200 <- y
    x = x-y; //300 - 200 = 100 <- x
    printf ("%d %d\n", x, y); //Esperado x= 100 e y= 200
    return 0;
}