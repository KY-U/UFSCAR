#include <stdio.h>
#include <stdlib.h>

#include "binSrchTree.h"

int main(int argc, char *argv[]){
    
    printf("Vamos criar a seguinte árvore:\n");
    printf("              60        \n           /     |	\n          40     80	\n         /  |   /  |	\n       30   50 70   90 \n");
    arvore t = newArvore();
    t = insereNo(t, 60);
    t = insereNo(t, 40);
    t = insereNo(t, 80);
    t = insereNo(t, 30);
    t = insereNo(t, 70);
    t = insereNo(t, 50);
    t = insereNo(t, 90);

    //imprimindo tudo
    printf("Imprimindo In Ordem:\n");
    printInOrder(t);
    printf("\n");

    //calculando a soma da arvore
    printf("A soma da árvore é: %d\n",soma(t));

    //calculando a altura
    printf("A altura da árvore é: %d\n",altura(t));

    //destroi
    printf("Destruindo a árvore por completo:\n");
    destroi(t);
    printf("\n");
    return 0;
}