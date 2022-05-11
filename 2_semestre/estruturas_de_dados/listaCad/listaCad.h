typedef struct no no_t;
typedef struct lista lis_t;
struct no{
    int conteudo;
    no_t *prox;
};
struct lista{
    no_t *head;
};
no_t *newNo(int x);
lis_t *newLista();
no_t *busca(lis_t *lista_atual, int x);
no_t *buscaPrev(lis_t *lista_atual, int x);
void insereNo(lis_t *lista_atual, int valor);
void removeNo(lis_t *lista_atual, int valor);
void printList(lis_t *lista_atual);