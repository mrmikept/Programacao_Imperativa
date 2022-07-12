#include <stdio.h>
#include <stdlib.h>

typedef struct celula {
    char *palavra;
    int ocorr;
    struct celula * prox;
} * Palavras;

/* TODAS as funções foram testadas no endereço da codeboard fornecido no enunciado*/

// Exercicio 1

void libertaLista (Palavras l){
    free(l);
}

// Exercicio 2

int quantasP (Palavras l){
    Palavras temp = l;
    int i = 0;
    for(i = 0; temp != NULL; i++)
    {
        temp = temp->prox;
    }
    return i;
}

// Exercicio 3

void listaPal (Palavras l){
    Palavras temp = l;
    while(temp != NULL)
    {
        printf("\"%s\" ocorrencias: %d\n",temp->palavra, temp->ocorr);
        temp = temp->prox;
    }
}

// Exercicio 4

char * ultima (Palavras l){
    Palavras temp = l;
    char *palavra = NULL;
    
    while(temp != NULL)
    {
        palavra = temp->palavra;
        temp = temp->prox;
    }
    return palavra;
}

// Exercicio 5

Palavras acrescentaInicio (Palavras l, char *p){
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = p;
    new->ocorr = 1;
    new->prox = l;
    return new;
}

// Exercicio 6

Palavras acrescentaFim (Palavras l, char *p)
{
    Palavras temp = l;
    
    Palavras new = malloc(sizeof(struct celula));
    new->palavra = p;
    new->ocorr = 1;
    
    if(l == NULL)
    {
        return new;
    }
    
    while(temp -> prox != NULL)
    {
        temp = temp->prox;
    }
    temp->prox = new;
    return l;
}

// Exercicio 7

Palavras acrescenta (Palavras l, char *p){
    Palavras temp = l;
    
    if(temp == NULL) return acrescentaInicio(l, p);
    
    while(temp->prox != NULL)
    {
        if(!strcmp(temp->palavra,p))
        {
            (temp->ocorr)++;
            break;
        }
        temp = temp->prox;
    }
    if(!strcmp(temp->palavra,p))
    {
        (temp->ocorr)++;
    }
    else
    {
        l = acrescentaInicio(l,p);
    }
    return l;
}

// Exercicio 8

struct celula * maisFreq (Palavras l){
    int r = 0;
    Palavras temp = l;
    struct celula *res = NULL;
    
    while (temp != NULL)
    {
        if(temp->ocorr > r)
        {
            r = temp->ocorr;
            res = temp;
        }
        temp = temp->prox;
    }
    
    return res;
}