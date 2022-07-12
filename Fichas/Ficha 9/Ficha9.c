#include <stdio.h>
#include <stdlib.h>

typedef struct nodo {
    int valor;
    struct nodo *esq, *dir;
} * ABin;



ABin newABin (int r, ABin e, ABin d) {
   ABin a = malloc (sizeof(struct nodo));
   if (a!=NULL) {
      a->valor = r; a->esq = e; a->dir = d;
   }
   return a;
}

ABin RandArvFromArray (int v[], int N) {
   ABin a = NULL;
    int m;
    if (N > 0){
    	m = rand() % N;
    	a = newABin (v[m], RandArvFromArray (v,m), RandArvFromArray (v+m+1,N-m-1));
    }
    return a;	
}

int altura (ABin a)
{
    if(a == NULL)
    {
        return 0;
    }
    int esq = altura(a->esq);
    int dir = altura(a->dir);
    int alt = 0;
    if(esq > dir)
    {
        alt = esq + 1;
    }
    else
    {
        alt = dir + 1;
    }
    return alt;
}

int nFolhas (ABin a){
    if(a == NULL)
    {
        return 0;
    }
    if(a->esq == NULL && a->dir == NULL)
    {
        return 1;
    }
    return nFolhas(a->esq) + nFolhas(a->dir);
}

ABin maisEsquerda (ABin a)
{
    if(a == NULL)
    {
        return NULL;
    }
    while(a->esq != NULL)
    {
        a = a->esq;
    }
    return a;
}

void imprimeNivel (ABin a, int l)
{
    if(l == 0)
    {
        printf("%d ",a->valor);
    }
    else
    {
        if(a->esq != NULL)
        {
            imprimeNivel(a->esq, l-1);
        }
        if(a->dir != NULL)
        {
            imprimeNivel(a->dir,l-1);
        }
    }
}

int procuraE (ABin a, int x)
{
    if (a == NULL)
    {
        return 0;
    }
    if(a->valor == x)
    {
        return 1;
    }
    int count = 0;
    if(a->esq != NULL)
    {
        count += procuraE(a->esq, x);
    }
    if(a->dir != NULL)
    {
        count += procuraE(a->dir, x);
    }
    return count;
}

struct nodo *procura (ABin a, int x)
{
    if(a == NULL)
    {
        return NULL;
    }
    while(a != NULL && a->valor != x)
    {
        if(a->valor > x)
        {
            a = a->esq;
        }
        else
        {
            a = a->dir;
        }
    }
    return a;
}

int nivel (ABin a, int x)
{
    int count = 0;
    while(a != NULL && a->valor != x)
    {
        if(a->valor > x)
        {
            a = a->esq;
        }
        else
        {
            a = a->dir;
        }
        count++;
    }
    return (a == NULL) ? -1 : count;
}

void imprimeAte (ABin a, int x)
{
    if(a != NULL)
    {
        if(a->esq != NULL)
        {
            imprimeAte(a->esq, x);
        }
        if(a->valor < x)
        {
            printf("%d ", a->valor);
        }
        if(a->dir != NULL)
        {
            imprimeAte(a->dir, x);
        }
    }
}
