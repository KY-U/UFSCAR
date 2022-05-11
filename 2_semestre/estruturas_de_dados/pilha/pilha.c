#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

Pilha_t *criaPilha()
{
    Pilha_t *s;
    s = (Pilha_t *)malloc(sizeof(Pilha_t));
    s->vetor = (char *)malloc(TAM_MAX * sizeof(char));
    s->topo = 0;
    return s;
}
void push(Pilha_t *s, char x)
{
    s->vetor[s->topo] = x;
    (s->topo)++;
}
char pop(Pilha_t *s)
{
    (s->topo)--;
    return s->vetor[s->topo];
}
int empty(Pilha_t *s)
{
return s->topo <= 0;
}
char peek(Pilha_t *s)
{
return s->vetor[(s->topo) - 1];
}
int full(Pilha_t *s)
{
return s->topo == TAM_MAX;
}
void imprimePilha(Pilha_t *s)
{
for (int i = (s->topo) - 1; i >= 0; i--)
printf("%c ", s->vetor[i]);

printf("\n");
}
Pilha_t *liberaPilha(Pilha_t *s)
{
free(s->vetor);
free(s);
return NULL;
}
