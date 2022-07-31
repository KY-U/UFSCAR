//Competição Literária		Trabalho de AED 2
//Caio Ueda Sampaio			Turma B		802215

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

//nó da árvore AVL
struct no{
	char chave[MAX];
	struct no *dir;
	struct no *esq;
	int altura;
	int ponto;
};
typedef struct no noh_t;

//protótipos
int max(int, int);
int altura(noh_t *);
int getBal(noh_t *);
noh_t *novoNo(char *, int);
noh_t *rotDir(noh_t *);
noh_t *rotEsq(noh_t *);
noh_t *insere(noh_t *, char*, int);
noh_t *minNo(noh_t*);
noh_t *removeNoh(noh_t *, char *);
noh_t *busca(noh_t *, char *);

//Implementações da árvore AVL

//retorna o maior termo
int max(int a, int b){ return (a > b)? a : b;}

//retorna altura da árvore
int altura(noh_t *no){
	if(no == NULL) return -1;
	return 1 + max(altura(no->esq), altura(no->dir));
}

//retorna balanceamento
int getBal(noh_t *no){
	if(no == NULL) return 0;
	return altura(no->dir) - altura(no->esq);
}

//retorna novo nó
noh_t *novoNo(char *chave, int ponto){
	noh_t *novo = (noh_t *) malloc(sizeof(noh_t));
	strcpy(novo->chave, chave);
	novo->esq = NULL;
	novo->dir = NULL;
	novo->altura = 0;
	novo->ponto = ponto;
	return novo;
}

//rotaciona a direita
noh_t *rotDir(noh_t *y){
	noh_t *x = y->esq;
	y->esq = x->dir;
	x->dir = y;
	y->altura = altura(y);
	x->altura = altura(x);
	return x;
}

//rotaciona a esquerda
noh_t *rotEsq(noh_t *x){
	noh_t *y = x->dir;
	x->dir = y->esq;
	y->esq = x;
	x->altura = altura(x);
	y->altura = altura(y);
	return y;
}

//insere o no
noh_t *insere(noh_t *r, char *chave, int  ponto){
	//caso a árvore esteja vazia
	if(r ==NULL) 
		return novoNo(chave, ponto);
	//caso não esteja vazia, descer a esquerda ou direita
	if(strcmp(chave, r->chave) < 0)
		r->esq = insere(r->esq, chave, ponto);
	else if(strcmp(chave, r->chave) > 0)	//chave > no->chave
		r->dir = insere(r->dir, chave, ponto);
    else return r;
	//atualiza a altura do nó "ancestral" do que foi inserido
	r->altura = altura(r);
	//balançeamento do nó ancestral
	int bal = getBal(r);
	//casos em que o nó ficou desbalanceado:
	//esq esq
	if(bal < -1 && (strcmp(chave, (r->esq)->chave) < 0))
		return rotDir(r);
	//dir dir
	if(bal > 1 && (strcmp(chave, (r->dir)->chave) > 0))
		return rotEsq(r);
	//esq dir
	if(bal < -1 && (strcmp(chave, r->esq->chave) > 0)){
		r->esq = rotEsq(r->esq);
		return rotDir(r);
	}
	//dir esq
	if(bal > 1 && (strcmp(chave, (r->esq)->chave) < 0)){
		r->dir = rotDir(r->dir);
		return rotEsq(r);
	}
	return r;
}

//pega o menor nó da árvore 
noh_t *minNo(noh_t *no){
	noh_t *p = no;
	while(p->esq != NULL)
		p = p->esq;
	return p;
}
//deletando um nó
noh_t *removeNoh(noh_t *r, char *chave){
	//caso a árvore esteja vazia
	if(r == NULL)
		return r;
	//caso não esteja vazia, descer a esquerda ou direita
	if(strcmp(chave, r->chave) < 0)
		r->esq = removeNoh(r->esq, chave);
	else if(strcmp(chave, r->chave) > 0)
		r->dir = removeNoh(r->dir, chave);
	else{
		//caso o nó tenha apenas um nó filho ou nenhum
		if((r->esq == NULL) || (r->dir == NULL)){
			noh_t *temp = r->esq ? r->esq : r->dir;
			//caso não tenha nenhum filho
			if(temp == NULL){
				temp = r;
				r = NULL;
			}
			else{	//caso tenha um filho
				//copia os conteúdos do filho não nulo
				r->altura = temp->altura;
				r->ponto = temp->ponto;
				r->esq = temp->esq;
				r->dir = temp->dir;
				strcpy(r->chave, temp->chave);
				
				free(temp);
			}
		}
		else{
			//caso tenha 2 filhos, pega o menor nó da sub-árvore direita(sucessor inOrder)
			noh_t *temp = minNo(r->dir);
			//copia os dados do sucessor inOrder para o nó atual
			r->altura = temp->altura;
			r->ponto = temp->ponto;
			r->esq = temp->esq;
			r->dir = temp->dir;
			strcpy(r->chave, temp->chave);
			//deleta o sucessor inOrder
			r->dir = removeNoh(r->dir, temp->chave);
		}	
	}
	//caso a árvore apenas tenha apenas um nó
	if(r == NULL)
		return r;
	//atualizando o fator de balançeamento do nó atual
	int bal = getBal(r);
	//casos em que o nó ficou desbalanceado:
	//esq esq
	if(bal < -1 && (strcmp(chave, (r->esq)->chave) < 0))
		return rotDir(r);
	//dir dir
	if(bal > 1 && (strcmp(chave, (r->dir)->chave) > 0))
		return rotEsq(r);
	//esq dir
	if(bal < -1 && (strcmp(chave, (r->esq)->chave) > 0)){
		r->esq = rotEsq(r->esq);
		return rotDir(r);
	}
	//dir esq
	if(bal > 1 && (strcmp(chave, (r->esq)->chave) < 0)){
		r->dir = rotDir(r->dir);
		return rotEsq(r);
	}
	return r;
}

//busca o nó da palavra
noh_t *busca(noh_t *r, char *chave){
	if(r == NULL || (strcmp(chave, r->chave) == 0))
		return r;
	if(strcmp(chave, r->chave) < 0)
		return busca(r->esq, chave);
	return busca(r->dir, chave);
}
//função main
int main(int argc, char *argv[]){
	
	//as palavras serão gravadas em um vetor para serem consultadas
	//na hora de removê-las da árvore para liberar a memória alocada pela AVL
	char **lista_de_palavras = NULL;
	//M, N, pontuação, palavras escolhidas, resultados finais e árvore AVL;
	int num_pal, num_part, pont;		
	char palavra[MAX];
	noh_t *arv = NULL;
	//lendo o número de palavras e participantes
	scanf("%d %d", &num_pal, &num_part);

	//vetor para guardar os resultados;
	int resultados[num_part];
	for(int i = 0; i < num_part; i++)
	//alocando espaço pro vetor de palavras
	lista_de_palavras = (char **) malloc(num_pal * sizeof(char *));
	for(int i = 0; i < num_pal; i++){
		lista_de_palavras[i] = (char *) malloc(MAX * sizeof(char));
	}
	//lendo as palavras e suas pontuações
	for(int i = 0; i < num_pal; i++){
		scanf("%s %d", palavra, &pont);
		//guardar a palavra e pontuação na AVL
		insere(arv, palavra, pont);
		//guardando a palavra no vetor de palavras
		strcpy(lista_de_palavras[i], palavra);
	}

	//lendo os textos e calculando as pontuações totais
	for(int i = 0; i< num_part; i++){
		noh_t *p;
		while(palavra[0] != 'c'){
			scanf("%s", palavra);
			//verifica na arvore AVL e adiciona a pontuacao
			if((p = busca(arv, palavra)) != NULL){
				resultados[i] += p->ponto;
			}
		}
	}

	//mostrando os resultados
	for(int i = 0; i < num_part; i++){
		printf("%d\n", resultados[i]);
	}

	//desalocando as memórias usadas
	for(int i = 0; i < num_pal; i++){
		removeNoh(arv, lista_de_palavras[i]);
		free(lista_de_palavras[i]);
	}

	return 0;
}