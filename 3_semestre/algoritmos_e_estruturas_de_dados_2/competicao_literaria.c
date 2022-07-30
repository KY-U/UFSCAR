//Competição Literária		Trabalho de AED 2
//Caio Ueda Sampaio			Turma B		802215

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40
//protótipos
int max(int, int);
int altura(no_t *);
int bal(no_t *);
no_t *novoNo(char *, int);
no_t *rotDir(no_t *);
no_t *rotEsq(no_t *);
no_t *insere(no_t *, int);

//Implementações da árvore AVL

//nó da árvore AVL
typedef struct no{
	char *chave;
	struct no *esq;
	struct no *dir;
	int altura;
	int ponto;
}no_t;

//retorna o maior termo
int max(int a, int b){ return (a > b)? a : b;}

//retorna altura da árvore
int altura(no_t *no){
	if(no == NULL) return -1;
	return 1 + max(altura(no->esq), altura(no->dir));
}

//retorna balanceamento
int bal(no_t *no){
	if(no == NULL) return 0;
	return altura(no->dir) - altura(no->esq);
}

//retorna novo nó
no_t *novoNo(char *chave, int ponto){
	no_t *novo = (no_t *) malloc(sizeof(no_t));
	novo->chave = (char *) malloc(MAX * sizeof(char));
	strcpy(novo->chave, chave);
	novo->esq = NULL;
	novo->dir = NULL;
	novo->alt = 0;
	novo->ponto = ponto;
	return novo;
}

//rotaciona a direita
no_t *rotDir(no_t *y){
	no_t *x = y->esq;
	y->esq = x->dir;
	x->dir = y;
	y->altura = altura(y);
	x->altura = altura(x);
	return x;
}

//rotaciona a esquerda
no_t *rotEsq(no_t *x){
	no_t *y = x->dir;
	x->dir = y->esq;
	y->esq = x;
	x->altura = altura(x);
	y->altura = altura(y);
	return y;
}

//insere o no
no_t *insere(no_t *r, char *chave, int  ponto){
	//caso 1: árvore vazia
	if(r ==NULL) 
		return novoNo(chave, ponto);
	//caso não esteja vazia, descer a esquerda ou direita
	if(strcmp(chave, r->chave) <= 0)
		r->esq = insere(r->esq, chave, ponto);
	else	//chave > no->chave
		r->dir = insere(r->dir, chave, ponto);
	//atualiza a altura do nó "ancestral" do que foi inserido
	r->altura = altura(r);
	//balançeamento do nó ancestral
	int bal = bal(r);
	//casos em que o nó ficou desbalanceado:
	//esq esq
	if(bal < -1 && (strcmp(chave, r->esq->chave) <= 0))
		return rotDir(r);
	//dir dir
	if(bal > 1 && (strcmp(chave, r->dir->chave) > 0))
		return rotEsq(r);
	//esq dir
	if(bal < -1 && (strcmp(chave, r->esq->chave) > 0)){
		r->esq = rotEsq(r->esq);
		return rotDir(r);
	}
	//dir esq
	if(bal > 1 && (strcmp(chave, r->esq->chave) <= 0)){
		r->dir = rotDir(r->dir);
		return rotEsq(r);
	}
	return r
}

//função main
int main(int argc, char *argv[]){
	
	//as palavras serão gravadas em um vetor para serem consultadas
	//na hora de removê-las da árvore para liberar a memória alocada pela AVL
	char **lista_de_palavras;
	//M, N, pontuação, palavras escolhidas e resultados finais;
	int num_pal, num_part, pont;		
	char palavra[MAX];
	int *resultado;

	//lendo o número de palavras e participantes
	scanf("%d %d", &num_pal, &num_part);

	//alocando espaço pro vetor com os resultados finais
	resultado = (int *) malloc(num_part * sizeof(int));

	//lendo as palavras e suas pontuações
	for(int i = 0; i < num_pal; i++){
		scanf("%s", palavra);
		//guardar a palavra e pontuação na AVL
	}

	//lendo os textos e calculando as pontuações totais
	for(int i = 0; i< num_part; i++){
		while(palavra[0] != "."){
			scanf("%s", palavra);
			//verifica na arvore AVL e adiciona a pontuacao
		}
	}

	//mostrando os resultados
	for(int i = 0; i < num_part; i++){
		printf("%d\n", resultado[i]);
	}

	return 0;

}
