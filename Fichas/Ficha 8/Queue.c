#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void initQueue (Queue *q)
{
    q->inicio = NULL;
    q->fim = NULL;
}

int QisEmpty (Queue q)
{
    return q.inicio == NULL;
}

int enqueue (Queue *q, int x)
{
    LInt temp = newLInt(x, NULL);
    if(q->inicio == NULL)
    {
        q->inicio = temp;
        q->fim = temp;
    }
    else
    {
        q->fim->prox = temp;
        q->fim = temp;
    }
    return 0;
}
int dequeue (Queue *q, int *x)
{
    int r = -1;
    if(q->inicio != NULL)
    {
        *x = q->inicio->valor;
        LInt temp = q->inicio;
        q->inicio = q->inicio->prox;
        free(temp);
        r = 0;
    }
    return r;
}
int frontQ (Queue q, int *x){
    int r = -1;
    if(q.inicio != NULL)
    {
        *x = q.inicio->valor;
        r = 0;
    }
    return r;
}

typedef LInt QueueC;

void initQueueC (QueueC *q)
{
    (*q) = NULL;
}

int QisEmptyC (QueueC q){
    return q == NULL;
}

int enqueueC (QueueC *q, int x)
{
    if(*q == NULL)
    {
        *q = newLInt(x, NULL);
        (*q)->prox = *q;
    }
    else
    {
        (*q)->prox = newLInt(x, (*q)->prox);
        (*q) = (*q)->prox;
    }
    return 0;
}
int dequeueC (QueueC *q, int *x)
{
    int r = -1;
    LInt temp = NULL;
    if(*q == (*q)->prox)
    {
        temp = *q;
        *q = NULL;
    }
    else
    {
        temp = (*q)->prox;
        (*q)->prox = temp->prox;
    }
    *x = temp->valor;
    free(temp);
    return 0;
}
int frontC (QueueC q, int *x)
{
    int r = -1;
    if(q != NULL)
    {
        *x = q->valor;
        r = 0;
    }
    return 0;
}
