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


// Questão 1
ABin removeMenor (ABin *a)
{
    ABin last, temp = *a;
    if(*a == NULL)
    {
        return NULL;
    }
    
    while(temp->esq != NULL)
    {
        last = temp;
        temp = temp->esq;
    }
    last->esq = temp->dir;
    return temp;
}
void removeRaiz (ABin *a)
{
    if((*a)->esq == NULL)
    {
        *a = (*a)->dir;
    }
    else if((*a)->dir == NULL)
    {
        *a = (*a)->esq;
    }
    else
    {
        ABin temp = (*a)->dir;
        ABin last = *a;
        while(temp->esq != NULL)
        {
            last = temp;
            temp = temp->esq;
        }
        if(last == *a)
        {
            last->dir = temp->dir;
        }
        else
        {
            last->esq = temp->dir;
        }
        (*a)->valor = temp->valor;
        free(temp);
    }
}

int removeElem (ABin *a, int x){
    if(*a == NULL)
    {
        return (-1);
    }
    if((*a)->valor == x)
    {
        removeRaiz(a);
        return 0;
    }
    if((*a)->valor < x)
    {
        ABin new = (*a)->dir;
        if(!removeElem(&new, x))
        {
            (*a)->dir = new;
            return 0;
        }
        return -1;
    }
    ABin new = (*a)->esq;
    if(!removeElem(&new, x))
    {
        (*a)->esq = new;
        return 0;
    }
    return -1;
}

// Questão 2
void rodaEsquerda (ABin *a){
    ABin b = (*a)->dir;
    (*a)->dir = b->esq;
    b->esq = (*a);
    *a = b;
}
void rodaDireita (ABin *a){
    ABin b = (*a)->esq;
    (*a)->esq = b->dir;
    b->dir = *a;
    *a = b;
}
void promoveMenor (ABin *a)
{
    while((*a)->esq != NULL)
    {
        rodaDireita(a);
    }
}

void promoveMaior (ABin *a)
{
    while((*a)->dir != NULL)
    {
        rodaEsquerda(a);
    }
}

ABin removeMenorAlt (ABin *a)
{
    while((*a)->esq != NULL)
    {
        rodaDireita(a);
    }
    ABin temp = malloc(sizeof(struct nodo));
    temp->esq = temp->dir = NULL;
    temp->valor = (*a)->valor;
    removeRaiz(a);
    return temp;
}

// Questão 3
int constroiEspinhaAux (ABin *a, ABin *ult)
{
    ABin esq = (*a)->esq;
    ABin dir = (*a)->dir;
    ABin nodo = *a;
    ABin last;
    *ult = *a;
    if(*a == NULL)
    {
        return 0;
    }
    int r = 1;
    if(nodo->esq != NULL)
    {
        r += constroiEspinhaAux(&esq, &last);
        last->dir = *a;
        *a = esq;
        nodo->esq = NULL;
    }
    if(nodo->dir != NULL)
    {
        r += constroiEspinhaAux(&dir,&last);
        (*ult)->dir = dir;
        (*ult) = last;
    }
    return r;
}
int constroiEspinha (ABin *a){
    ABin ult;
    return (constroiEspinhaAux (a,&ult));
}

ABin equilibraEspinha (ABin *a, int n) 
{
    if(n<0 || *a == NULL)
    {
        return *a;
    }
    int i = 0;
    int meio = n/2;
    ABin temp = *a;
    for(i = 0; i < meio && temp != NULL; i++)
    {
        temp = temp->dir;
    }
    
    ABin nodo = (*a)->dir;
    ABin ant = *a;
    while(nodo != temp)
    {
        ABin next = ant->dir;
        ant->dir = NULL;
        nodo->esq = ant;
        ant = next;
        nodo = nodo->dir;
    }
    ant->dir = NULL;
    nodo->esq = ant;
    *a = temp;
    for(; i < n && temp != NULL; i++, temp = temp->dir)
    {
        ant = temp;
    }
    ant->dir = NULL;
	return temp;
}

void equilibra (ABin *a) 
{
    int n = constroiEspinha(a);
    equilibraEspinha(a,n);
}
