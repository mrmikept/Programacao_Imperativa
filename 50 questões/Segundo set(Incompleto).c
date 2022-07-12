#include <stdio.h>
#include <stdlib.h>

typedef struct lligada
{
    int valor;
    struct lligada *prox;
} * LInt;

// Ex 1

int length(LInt l)
{
    int size = 0;
    int i = 0;
    for (i = 0; l != NULL; i++)
    {
        size++;
        l = l->prox;
    }
    return size;
}

// Ex 2

void freeL(LInt)
{
    Lint aux;
    while (l != NULL)
    {
        aux = l;
        l = l->prox;
        free(aux);
    }
}

// Ex 3

void imprimeL(LInt)
{
    while (l != NULL)
    {
        printf("%d\n", l->valor);
        l = l->prox;
    }
}

// Ex 4

LInt reverseL(LInt l)
{
    LInt last = NULL;
    LInt next = NULL;
    LInt now = l;
    while (now != NULL)
    {
        next = now->prox;
        now->prox = last;
        last = now;
        now = next;
    }
    return last;
}

// Ex 5

void insertOrd(LInt *l, int x)
{
    LInt new = (LInt)malloc(sizeof(struct lligada));
    new->valor = x;
    LInt now = *l;
    LInt last = NULL;
    while (now != NULL && now->valor < x)
    {
        last = now;
        now = now->prox;
    }
    if (last == NULL)
    {
        new->prox = *l;
        *l = new;
    }
    else
    {
        new->prox = now;
        last->prox = new;
    }
}

// Ex 6

int removeOneOrd(LInt *l, int x)
{
    LInt last = NULL;
    while (*l && x != (*l)->valor)
    {
        last = *l;
        l = &((*l)->prox);
    }
    if ((*l) == NULL)
    {
        return 1;
    }
    if (last == NULL)
    {
        (*l) = (*l)->prox;
    }
    else
    {
        last->prox = (*l)->prox;
    }
    return 0;
}

// Ex 7

void merge(LInt *r, LInt l1, LInt l2)
{
    if (l1 == NULL)
    {
        *r = l2;
    }
    else if (l2 == NULL)
    {
        *r = l1;
    }
    else if (l1->valor <= l2->valor)
    {
        *r = l1;
        l1 = l1->prox;
        merge(&(*r)->prox, l1, l2);
    }
    else
    {
        *r = l2;
        l2 = l2->prox;
        merge(&(*r)->prox, l1, l2);
    }
}

// Ex 8

void splitQS (LInt l, int x, LInt *mx, LInt *Mx){
    if(l == NULL)
    {
        return;
    }
    if(l->valor < x)
    {
        (*mx) = l;
        (*Mx) = NULL;
        splitQS(l->prox, x, &((*mx)->prox), Mx);
    } else
    {
        (*Mx) = l;
        (*mx) = NULL;
        splitQS(l->prox, x, mx, &((*Mx)->prox));
    }
}


