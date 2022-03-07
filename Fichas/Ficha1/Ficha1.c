#include <stdio.h>
#include <math.h>

void quadrado();
void xadrez();
void trianV();
void trianH();
void linha();
void linhaEsp();
void circulo();
int main() {
    int x;
    scanf("%d",&x);
    quadrado(x);
    xadrez(x);
    trianV(x);
    trianH(x);
    circulo(x);
    return 0;
}

void quadrado(int n) {
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

void xadrez(int n) {   //funcao que escreve no terminal um tabuleiro de xadrez (ex: #_#_#) de dimensão n
    int l = 0, c = 0; //l = numero de linhas // c = qual caracter
    for (l = 0; l < n; l++) { //ciclo de for que escreve cada linha
        for (c = 0; c < n; c++) //ciclo de for que decide qual caracter escrever( # ou _) conforme de o resto da divisão do numero da linha e coforme o resto da divisão de qual caracter com 2 for igual a 0
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
            } else {
                putchar('_');
            }
            
        }
        putchar('\n');
    }
    putchar('\n');
}  

void trianH(int n) {
    for (int l = 1; l <= n; l++)
    {
        for (int c = 1; c <= n-l; c++)
        {
                putchar(' ');
        }
        for (int j=1; j<=2*l-1; j++)
        {
            putchar('#');
        }
        
        putchar('\n');
    }
    putchar('\n');
}

void trianV(int n) {
    for (int l = 0; l < n*2 ; l++)
    {
        for (int c = 0; c<2*n-l; c++)
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

void circulo (int r) { //para fazer esta função vamos imaginar que o terminal é um eixo ortonormado xy onde a circunferencia tem centro (r,r) e diametro 2*r
    int chr = 0;
    for (int x = 0; x < r*2+1; x++) //ciclo for que muda de linha
    {
        for (int y = 0; y < r*2 +1; y++) //ciclo for que em cada coluna decide qual caracter usar
        {
            float a = r - x; //posição vertical
            float b = r - y; //posição horizontal
            float c = sqrt(a*a+b*b); //formula da circunferencia
            if (c <= r) { //se o valor do c for menor ou igual a r escreve um # no ecrã se for maior que o r então coloca o caracter espaço.
                putchar('#');
                chr++;
            } else {
                putchar(' ');
            }
        }
        putchar('\n');
    }
    putchar('\n');
    printf("O circulo tem %d caracteres '#'.\n",chr);
}

//As mesmas funções feitas de maneira diferente(maneira mais estupida)

void linhaEsp(int n){ //função que imprime n espaços sucessivos.
    int i = 0;
    for (i = 0; i<n; i++) {
        putchar(' ');
    }
}

void linha(int n) {  //Funcao que escreve n vezes o '#'
    int i = 0; //valor inicial
    while (i < n) { //condição de paragem.
        //açao a realizar por cada valor de i
        printf("#");
        // ---
        i++; //incremento ao i
    }
}

/*
void quadrado(int n) {
   int l = 0;
   while ( l < n) {
       linha(n); putchar('\n');
       l++;
   }
} */

/* void trianV(int n) { VERSAO FEITA DE MANEIRA ESTUPIDA
    int l = 0;
    for (l = 1; l < n; l++) {
        linha(l);
        putchar('\n');
    }
    linha(n);
    putchar('\n');
    for (l = n-1; l > 0; l = l -1) {
        linha (l);
        putchar('\n');
    }
    
} */

/*void trianH (int n) { VERSAO FEITA DE MANEIRA ESTUPIDA.
    int l = 0; //valor inicial, numero da linha
    int e = n-1; //e equivale ao numero de espaços por linha, se n=5 cada linha tem 4 espaços de cada lado da sequencia de #
    for (l = 0; l < n; l++)
    {
        linhaEsp(e); //imprime n-1 espaços.
        linha(l); //imprime l vezes o #.
        linha(1); //imprime o eixo central de #.
        linha(l); //imprime l vezes o # depois do eixo central.
        putchar('\n'); //muda de linha.
        e--; //a cada linha o numero de espaços diminiu em 1.
    }
        
} */

