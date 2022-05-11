typedef struct fila fila_t;
fila_t *criaFila();
void insereFila(fila_t *q, char x);
char removeFila(fila_t *q);
int empty(fila_t *q);
int full(fila_t *q);
void imprimeFila(fila_t *q);
int tamFila(fila_t *q);
fila_t *liberaFila(fila_t *q);