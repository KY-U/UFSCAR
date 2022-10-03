#include <stdio.h>
#include <stdlib.h>

int **matriz_quad(int);
int bipartido(int**, int);

//fila
typedef struct node Node;
typedef struct node {
    Node *proximo;
    int conteudo;
} Node;

typedef struct fila {
    Node *inicio;
    Node *fim;
    int tam;
} Fila;

Fila *criar() {
    Fila* fila = malloc(sizeof(Fila));
    fila->inicio = NULL;
    fila->fim = NULL;
    fila->tam = 0;
    return fila;
}

void inserir(Fila *fila, int valor) {

    Node *nova;
    nova = malloc(sizeof(Node));

    nova->conteudo = valor;
    nova->proximo = NULL;

    if (fila->inicio == NULL) {
        fila->inicio = nova;
        fila->fim = nova;
    } else {
        fila->fim->proximo = nova;
        fila->fim = nova;
    }
    (fila->tam)++;
}

int remover(Fila *fila) {
    if (fila->inicio == NULL) return '\0';

    Node *paraRemover = fila->inicio;
    int valor = paraRemover->conteudo;
    
    fila->inicio = paraRemover->proximo;
    if (fila->inicio == NULL) {
        fila->fim = NULL;
    }

    free(paraRemover);
    return valor;
}
int main(int argc, char **argv){

    FILE *entrada; 
    char file_name[30];
    if(argc != 1){
        printf("Numero incorreto de parametros. Ex: ..\\nome_arquivo_executavel\n");
        return 0;
    }
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if(entrada == NULL){
        printf("\nNao encontrei o arquivo! Informe o nome da instancia\n");
        exit(EXIT_FAILURE);
    }

    //numero de instancias e alunos
    int num_inst, num_alun;
    int i,j;
    //le o numero de instancias
    fscanf(entrada, "%d", &num_inst);

    //funcao que cria a matriz de adjacencia dos alunos
    int** matriz_quad(int num_alun){
        int i,j;
        int **m = (int**)malloc(num_alun * sizeof(int*));
            for(i = 0; i < num_alun; i++){
                m[i] = (int*)malloc(num_alun * sizeof(int));
            }
        for(i = 0; i < num_alun; i++){
            for(j = 0; j < num_alun; j++){
                m[i][j] = 0;
            }
        }
        return m;
    }

    //funcao que verifica se o grafo eh bipartido
    int bipartido(int **m, int num_alun){
       int i, j;
       int visitado[num_alun];
       for(i = 0; i < num_alun; i++)
			visitado[i] = 0;
	   //vetor de cores
	   //0:sem cor, 1:azul, 2:vermelho
	   int cores[num_alun];
	   for(i = 0; i < num_alun; i++)
			cores[i] = 0;
	   for(int k = 0; k < num_alun; k++){
			if(!(visitado[k])){
				cores[k] = 1;
				Fila *fil = criar();
				inserir(fil, k);
				while(fil->inicio != NULL){
					i = remover(fil);
					visitado[i] = 1;
					for(j = 0; j < num_alun; j++){
						if(((m[i][j]) != 0) && !(cores[j])){
							if(cores[i] == 1)
								cores[j] = 2;
							else if(cores[i] == 2)
								cores[j] = 1;
							inserir(fil, j);
						}else if((m[i][j] != 0) && (cores[i] == cores[j])){
							return 0;
						}
					}	
				}
			}
		}
		return 1;
    }
    //vetor de resultados
    int *result = (int*)malloc(num_inst * sizeof(int));

    //leitura de todas as instancias
    for(int inst = 0; inst < num_inst; inst++){
        int num_perg, aluno;
        int **m;
        fscanf(entrada, "%d", &num_alun);
        m = matriz_quad(num_alun);
        for(i = 0; i < num_alun; i++){
           fscanf(entrada, "%d", &num_perg);
           for(j = 0; j < num_perg; j++){
               fscanf(entrada, "%d", &aluno);
               m[i][aluno] = 1;
               m[aluno][i] = 1;
           }
        }
        result[inst] = (bipartido(m, num_alun))? 1 : 0;
        //liberando matriz
        for(i = 0; i < num_alun; i++){
            free(m[i]);
        }
        free(m);
    }
    //printando resultados
    for(i = 0; i < num_inst; i++){
        if(result[i])
            printf("Vai ter debate\n");
        else printf("Impossivel\n");
    }
    
    //liberando o vetor de resultados
    free(result);

    fclose(entrada);
    return 0;

}
