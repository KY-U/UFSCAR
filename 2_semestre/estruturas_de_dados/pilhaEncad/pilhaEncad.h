typedef struct celula
{
    char conteudo;
    struct celula *prox;
}Pilha_t;

Pilha_t *criaPilha();
void push(Pilha_t *s, char x);
char pop(Pilha_t *s);
int empty(Pilha_t *s);
char peek(Pilha_t *s);
int tamanho(Pilha_t *s);