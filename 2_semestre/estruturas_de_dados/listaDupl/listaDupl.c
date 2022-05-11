#include <stdio.h>
#include <stdlib.h>

#include "listaDupl.h"
no_t *newNo(int x){
    no_t *novo =(no_t *) malloc(sizeof(no_t));
    novo->conteudo = x;
    novo->prox = NULL;
    novo->ant = NULL; //adicao
    return novo;
}
lis_t *newLista(){
   lis_t *nova =(lis_t *) malloc(sizeof(lis_t));
    nova->head = NULL;
    return nova;
}
no_t *busca(lis_t *lista_atual, int x){
    no_t *p = lista_atual->head;
    while(p != NULL && p->conteudo != x)
    p = p->prox;
    return p;
}
no_t *buscaPrev(lis_t *lista_atual, int x){
    no_t *p = lista_atual->head->prox;
    while(p->prox != NULL && p->prox->conteudo != x)
    p = p->prox;
    return p;
}
void insereNo(lis_t *lista_atual,int valor){
    no_t *novo = newNo(valor);
    if(lista_atual->head == NULL){
        lista_atual->head = novo;
        novo->ant = lista_atual->head; //adicao
        return;
    }
    novo->prox = lista_atual->head->prox;
    if(novo->prox != NULL)      //
        novo->prox->ant = novo; //adicao
    lista_atual->head->prox = novo;
    novo->ant = lista_atual->head; //adicao
}
void removeNo(lis_t *lista_atual, int valor){
    if(lista_atual->head->conteudo == valor){
        no_t *morto = lista_atual->head;
        lista_atual->head = lista_atual->head->prox;
        free(morto);
        return;
    }
    no_t *p = buscaPrev(lista_atual, valor);
    if(p->prox != NULL){
        no_t *morta = p->prox;
        p->prox = p->prox->prox;
        p->prox->ant = p; //adicao
        free(morta);
    }
}
void printList(lis_t *lista_atual){
    no_t *p = lista_atual->head;
    while(p != NULL){
        printf("%d ",p->conteudo);
        p = p->prox;
    }
    printf("\n");
}