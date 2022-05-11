typedef struct no no_t;
typedef no_t *arvore;
                                    //operações básicas pedidas pela professora:
no_t *newNo(int);                   //cria
arvore newArvore();
int empty(no_t *);                  //vazia
no_t *insereNo(no_t *, int);         //insere
no_t *removeNo(no_t *, int);         //remove
void destroi(no_t *);               //destrói
int estaNaArvore(no_t *, int);      //está_na_árvore
void printInOrder(no_t *);
int altura(no_t *);
void somaPorRef(no_t *, int *);
int soma(no_t *);
no_t *busca(no_t *, int);
no_t * menorNo(no_t *);

