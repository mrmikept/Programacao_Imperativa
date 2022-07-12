#include <stdio.h>
#include <stdlib.h>
#include "Stack.h"

void initStack (Stack *s)
{
    (*s) = NULL;
}

int SisEmpty (Stack s){
    if(s == NULL)
    {
        return 1;
    }
    return 0;
}
int push (Stack *s, int x){
    (*s) = newLInt(x, (*s));
    return (*s) != NULL;
}

int pop (Stack *s, int *x)
{
    int r = -1;
    if((*s) != NULL)
    {
        *x = (*s)->valor;
        (*s) = (*s)->prox;
        r = 0;
    }
    return r;
}

int top (Stack s, int *x)
{
    int r = -1;
    if(s != NULL)
    {
        *x = s->valor;
        r = 0;
    }
    return r;
}
