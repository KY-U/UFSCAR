#define TAM_MAX 100
typedef struct 
{
    char *vetor;
    int topo;
}Pilha_t;

Pilha_t *criaPilha();
void push(Pilha_t *s, char x);
char pop(Pilha_t *s);
int empty(Pilha_t *s);
char peek(Pilha_t *s);
int full(Pilha_t *s);
void imprimePilha(Pilha_t *s);
Pilha_t *liberaPilha(Pilha_t *s);