#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"
#define Max 10

struct staticStack {
	int sp;
	int values [Max];
};
typedef struct staticStack *SStack;

struct dinStack {
	int size;
	int sp;
	int *values;
};
typedef struct dinStack *DStack;

// Static stacks 

void SinitStack (SStack s){
	s->sp = 0;
}

int  SisEmpty (SStack s){
    if(s->sp == 0)
    {
        return 0;
    }
	return 1;
}

int  Spush (SStack s, int x){
	int r = 1;
	if(s->sp < 10)
	{
	    s->values[s->sp++] = x;
	    r = 0;
	}
	return r;
}

int  Spop (SStack s, int *x) {
	int r=1;
	if(s->sp > 0)
	{
	    *x = s->values[s->sp];
	    s->sp--;
	    r = 0;
	}
	return r;
}

int  Stop (SStack s, int *x) {
	int r=0;
	if(s->sp > 0)
	{
	    *x = s->values[s->sp];
	    r = 0;
	}
	return r;
}

void ShowSStack (SStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}

// Stacks with dynamic arrays

int dupStack (DStack s) {
	int r = 0, i;
	int *t = malloc (2*s->size*sizeof(int));

	if (t == NULL) r = 1;
	else {
		for (i=0; i<s->size; i++) 
			t[i] = s->values[i];
		free (s->values);
		s->values = t;
		s->size*=2;
	}
	return r;
}

void DinitStack (DStack s) 
{
	s->size = 10;
	s->values = malloc(sizeof(s->values) * s->size);
	s->sp = 0;
}

int  DisEmpty (DStack s) 
{
    if(s->sp == 0)
    {
        return 0;
    }
	return 1;
}

int  Dpush (DStack s, int x)
{
	int r=0;
	if(s->sp == s->size)
	{
        dupStack(s);
	}
	s->values[s->sp++] = x;
	return r;
}

int  Dpop (DStack s, int *x){
	int r=1;
	if(s->sp > 0)
	{
	    *x = s->values[s->sp];
	    s->sp--;
	    r = 0;
	}
	return r;
}

int  Dtop (DStack s, int *x){
	int r=1;
	if(s->sp > 0)
	{
	    *x = s->values[s->sp];
	    r = 0;
	}
	return r;
}

void ShowDStack (DStack s){
    int i;
    printf ("%d Items: ", s->sp);
    for (i=s->sp-1; i>=0; i--) 
        printf ("%d ", s->values[i]);
    putchar ('\n');
}
