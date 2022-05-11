#include <stdio.h>
#include <stdlib.h>

#include "pilhaEncad.h"

Pilha_t *criaPilha(){
    Pilha_t *s;
    s = (Pilha_t *)malloc(sizeof(Pilha_t));
    s->prox = NULL;
    return s;
}
void push(Pilha_t *s, char x){
    Pilha_t *nova;
    nova = malloc(sizeof(Pilha_t));
    nova-> conteudo = x;
    nova->prox = s->prox;
    s->prox = nova;
}
char pop(Pilha_t *s){
    char valor;
    Pilha_t *morta;
    morta = s->prox;
    valor = morta->conteudo;
    s->prox = morta->prox;
    free(morta);
    morta = NULL;
    return valor;
}
int empty(Pilha_t *s){
    return s->prox== NULL;
}
char peek(Pilha_t *s){
    return s->prox->conteudo;
}
int tamanho(Pilha_t *s){
    Pilha_t *p;
    int tam = 0;
    p = s->prox;
    while(p != NULL){
        tam++;
        p = p->prox;
    }
    return tam;
}