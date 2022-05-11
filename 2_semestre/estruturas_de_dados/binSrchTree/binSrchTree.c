#include <stdio.h>
#include <stdlib.h>

#include "binSrchTree.h"

struct no{
    int conteudo;
    no_t *esq;
    no_t *dir;
};
no_t *newNo(int conteudo){
    no_t *novo = (no_t *)malloc(sizeof(no_t));
    novo->conteudo = conteudo;
    novo->esq = NULL;
    novo->dir = NULL;
    return novo;
}
arvore newArvore(){
    arvore novo = NULL;
    return novo;
}
int empty(no_t * r){
    return r == NULL;
}
no_t *insereNo(no_t *r, int x){
    //caso a arvore esteja vazia(caso base)
    if(r==NULL)
        r = newNo(x);
    //caso contrário, percorre recursivamente a arvore ate achar o local correto
    else if(x <= r->conteudo)
        r->esq = insereNo(r->esq, x);
    else
        r->dir = insereNo(r->dir, x);
    return r;
}
int estaNaArvore(no_t *r, int x){
    return (busca(r, x) != NULL)? 1:0;
}
void printInOrder(no_t * r){
    if(r!=NULL){
        printInOrder(r->esq);
        printf("|%d|\t", r->conteudo);
        printInOrder(r->dir);
    }
}
no_t *removeNo(no_t * r, int x){
    //caso base
    if(r == NULL)
        return NULL;
    //caso o termo a ser removido esteja na sub-árvore esquerda
    if(x < r->conteudo)
        r->esq = removeNo(r->esq, x);
    //caso o termo esteja na sub-árvore direita
    else if(x > r->conteudo)
        r->dir = removeNo(r->dir, x);
    //caso este seja o nó a ser removido
    else {
        //nó com um filho ou menos
        if(r->esq == NULL){
            no_t *temp = r->dir;
            free(r);
            return temp;
        }
        else if(r->dir == NULL){
            no_t *temp = r->esq; 
            free(r);
            return temp;
        }
        //nó com dois filhos
        //pegar o nó com o termo sucessor(poderia ser feito com o anterior)
        //que é o menor nó da sub-árvore direita
        no_t *temp = menorNo(r->dir);

        //copiar o conteudo do no sucessor para o no atual
        r->conteudo = temp->conteudo;

        //deletar o sucessor
        removeNo(r->dir, temp->conteudo);
    }
    return r;
}
void destroi(no_t * r){
    if(r != NULL){
        destroi(r->esq);
        destroi(r->dir);
        printf("%d deletado\t", r->conteudo);
        free (r);
    }
}
int altura(no_t * r){
    if(r==NULL)
        return -1;
    int hesq = altura(r->esq);
    int hdir = altura(r->dir);
    if(hesq > hdir)
        return hesq + 1;
    return hdir + 1;
}
void somaPorRef(no_t * r, int *x){
    if(r!=NULL){
        *x = *x + r->conteudo;
        somaPorRef(r->esq, x);
        somaPorRef(r->dir, x);
    }
}
int soma(no_t *r){
    int x = 0;
    somaPorRef(r, &x);
    return x;
}
no_t *busca(no_t *r, int x){
    //arvore NULL 
    if(r == NULL)
        return NULL;
    //termo procurado eh o primeiro
    if(r->conteudo == x)
        return r;
    //termo eh maior que o valor da arvore(primeiro no)
    if(x > r->conteudo)
        return busca(r->dir, x);
    //se o termo for menor...
    return busca(r->esq, x);
}
no_t * menorNo(no_t * r){
    no_t *atual = r;
    //achar o menor no nessa árvore
    while(atual && atual->esq != NULL)
        atual = atual->esq;
    return atual;
}