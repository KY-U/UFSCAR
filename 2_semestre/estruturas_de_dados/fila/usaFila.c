#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

//funcao para preencher uma fila com termos aleatorios
void preencheFila(fila_t *f){
    int n = rand()%50;
    for(int i=0;i<n;i++){
        insereFila(f, rand());
    }
}
//funcao que junta duas filas f1 e f2 em uma f3
void juntaFila(fila_t *f1, fila_t *f2, fila_t *f3){
    char aux;
    fila_t *filaAux;
    filaAux = criaFila();
    while(!empty(f1)){
        aux = removeFila(f1);
        insereFila(f3, aux);
        insereFila(filaAux, aux);
    }
    while(!empty(filaAux)){
        aux = removeFila(filaAux);
        insereFila(f1, aux);
    }
    while(!empty(f2)){
        aux = removeFila(f2);
        insereFila(f3, aux);
        insereFila(filaAux, aux);
    }
    while(!empty(filaAux)){
        aux = removeFila(filaAux);
        insereFila(f2, aux);
    }
    filaAux = liberaFila(filaAux);
}
//funcao que troca os elementos de 2 filas
void trocaFila(fila_t *f1, fila_t *f2){
    char aux;
    fila_t *filaAux;
    filaAux = criaFila();
    while(!empty(f1)){
        aux = removeFila(f1);
        insereFila(filaAux, aux);
    }
    while(!empty(f2)){
        aux = removeFila(f2);
        insereFila(f1, aux);
    }
    while(!empty(filaAux)){
        aux = removeFila(filaAux);
        insereFila(f2, aux);
    }
    filaAux = liberaFila(filaAux);
}
int main(){

    //criando 2 filas e preenchendo-as com chars aleatorios
    srand(time(0));
    fila_t *f1, *f2;
    f1 = criaFila();
    f2 = criaFila();
    preencheFila(f1);
    preencheFila(f2);

    //mostrando as filas para comparacao
    printf("Primeira fila:\n");
    imprimeFila(f1);
    printf("\n");
    printf("Segunda fila:\n");
    imprimeFila(f2);
    printf("\n");

    //juntando os elementos das 2 filas em uma fila f3
    fila_t *f3;
    f3 = criaFila();
    juntaFila(f1, f2, f3);
    //mostrando a fila para comparacao
    printf("Apos juntar as filhas, este foi o resultado:");
    imprimeFila(f3);
    printf("\n");

    //trocando os elementos das filhas 
    trocaFila(f1, f2);
    
    //mostrando as filas para comparacao
    printf("Primeira fila apos trocar:\n");
    imprimeFila(f1);
    printf("\n");
    printf("Segunda fila apos trocar:\n");
    imprimeFila(f2);

    return 0;
}