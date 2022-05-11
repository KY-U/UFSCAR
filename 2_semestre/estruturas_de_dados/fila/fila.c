#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

#define TAM_MAX 100

struct fila
{
    char *vetor;
    int ini;
    int fim;
};
fila_t *criaFila()
{
    fila_t *q = (fila_t *)malloc(sizeof(fila_t));
    q->vetor = (char *)malloc(TAM_MAX * sizeof(char));
    q->ini = 0;
    q->fim = 0;
return q;
}
void insereFila(fila_t *q, char x)
{
    q->vetor[q->fim] = x;
    (q->fim)++;
}
char removeFila(fila_t *q)
{
    char x;
    x = q->vetor[q->ini];
    (q->ini)++;
    return x;
}
int empty(fila_t *q)
{
    return q->fim == q->ini;
}
int full(fila_t *q)
{
    return q->fim == TAM_MAX;
}
void imprimeFila(fila_t *q)
{
    for (int i = q->ini; i < q->fim; i++)
        printf("%c ", q->vetor[i]);
        printf("\n");
}
int tamFila(fila_t *q)
{
    return q->fim - q->ini;
}
fila_t *liberaFila(fila_t *q)
{

    free(q->vetor);
    free(q);
    return NULL;
}