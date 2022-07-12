#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"
#define Max 10

struct staticQueue {
	int front;
	int length;
	int values [Max];
};
typedef struct staticQueue *SQueue;

struct dinQueue {
	int size;
	int front;
	int length;
	int *values;
};
typedef struct dinQueue *DQueue;

// Static queues 

void SinitQueue (SQueue q){
	q->front = 0;
	q->length = 0;
}

int  SisEmptyQ (SQueue q){
    if(q->length == 0)
    {
        return 0;
    }
	return 1;
}

int  Senqueue (SQueue q, int x){
	int r = 1;
	if(q->length < 10)
	{
	    q->values[(q->front + (q->length)++)] = x;
	    r = 0;
	}
	return r;
}

int  Sdequeue (SQueue q, int *x) {
	int r = 1;
	
	if(q->length > 0)
	{
	    *x = q->values[(q->front)++];
	    (q->length)--;
	}
	return r;
}

int  Sfront (SQueue q, int *x) {
	int r = 1;
	
	if(q->length > 0)
	{
	    *x = q->values[(q->front)++];
	}
	return r;
}

void ShowSQueue (SQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%Max;
    }
    putchar ('\n');
}

// Queues with dynamic arrays

int dupQueue (DQueue q) {
    int r = 0, i, p;
    int *t = malloc(sizeof(int) * 2 * q->size);
    
    if (t == NULL) r = 1;
    else {
        for (i = 0, p = q->front; i < q->length; i++) {
            t[i] = q->values[p];
            p = (p+1) % q->size;
        }
        free (q->values);
        q->values = t;
        q->front = 0;
        q->size *= 2;
    }
	return r;
}

void DinitQueue (DQueue q) {
	q->size = 10;
	q->front = 0;
	q->length = 0;
	q->values = malloc(sizeof(int) * q->size);
}

int  DisEmptyQ (DQueue q) {
	if(q->length == 0)
	{
	    return 0;
	}
	return 1;
}

int  Denqueue (DQueue q, int x){
	int r = 0;
	
	if(q->length == q->size)
	{
	    dupQueue(q);
	}
	q->values[q->front + (q->length)++] = x;
	return r;
}

int  Ddequeue (DQueue q, int *x){
	int r = 1;
	if(q->length > 0)
	{
	    *x = q->values[(q->front)++];
	    (q->length)--;
	}
	return r;
}

int  Dfront (DQueue q, int *x){
	int r = 1;
	if(q->length > 0)
	{
	    *x = q->values[(q->front)++];
	}
	return r;
}

void ShowDQueue (DQueue q){
    int i, p;
    printf ("%d Items: ", q->length);
    for (i=0, p=q->front; i<q->length; i++) {
        printf ("%d ", q->values[p]);
        p = (p+1)%q->size;
    }
    putchar ('\n');
}
