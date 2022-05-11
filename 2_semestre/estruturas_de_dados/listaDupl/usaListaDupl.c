#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "listaDupl.h"

lis_t *innerJoin(lis_t *l1, lis_t *l2){
    no_t *p1 = l1->head, *p2 = l2->head;
    lis_t *l3 = newLista();
    while(p1 != NULL){
        while(p2 != NULL){
            if(p1->conteudo == p2->conteudo){
            insereNo(l3, p1->conteudo);
            }
        p2 = p2->prox;
        }
    p1 = p1->prox;
    }
    return l3;
}
lis_t *outerJoin(lis_t *l1, lis_t *l2){
    no_t *p1 = l1->head, *p2 = l2->head;
    lis_t *l3 = newLista();
    while(p1 != NULL){
        if(busca(l3,p1->conteudo) == NULL){
            insereNo(l3,p1->conteudo);
        }
        p1 = p1->prox;
    }
     while(p2 != NULL){
        if(busca(l3,p2->conteudo) == NULL){
            insereNo(l3,p2->conteudo);
        }
        p2 = p2->prox;
    }
    return l3;
}
int main(int argc, char *argv[]){
srand(time(NULL));
//declaracao de variaveis
lis_t *l1 = newLista(), *l2 = newLista();
//preenchendo duas listas
for(int i = 0; i<5; i++){
    insereNo(l1, (rand()%5)*2);
    insereNo(l2, (rand()%5)*2 + 1);
}
printf("listas antes de alterar:\n");
printList(l1);
printf("\n");
printList(l2);
printf("interseccionando as listas:\n");
printList(innerJoin(l1,l2));
printf("unindo as listas:\n");
printList(outerJoin(l1,l2));
return 0;
}