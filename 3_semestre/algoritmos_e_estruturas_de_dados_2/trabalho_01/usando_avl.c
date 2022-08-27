//Competição Literária		Trabalho de AED 2
//Caio Ueda Sampaio			Turma B		802215

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 35

//nó da árvore AVL
struct no{
	char *chave;
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
void desaloca_tudo(noh_t *);

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
	novo->chave = chave;
	novo->esq = NULL;
	novo->dir = NULL;
	novo->altura = 0;
	novo->ponto = ponto;
	return novo;
}

//rotaciona a direita
noh_t *rotDir(noh_t *y){
	noh_t *x = y->esq;
	noh_t *h2 = x->dir;
	x->dir = y;
	y->esq = h2; 
	//y->esq = x->dir;  	ao invés de escrever as 3 linhas superiores, se eu utilizar 
	//x->dir = y;			apenas essas 2 linhas, fica mais lento, não sei porque.
	y->altura = altura(y);
	x->altura = altura(x);
	return x;
}

//rotaciona a esquerda
noh_t *rotEsq(noh_t *x){
	noh_t *y = x->dir;
	noh_t *h2 = y->esq;
	y->esq = x;
	x->dir = h2;
	//x->dir = y->esq;
	//y->esq = x;
	x->altura = altura(x);
	y->altura = altura(y);
	return y;
}

//insere o no
noh_t *insere(noh_t *r, char *chave, int  ponto){
	//caso a árvore esteja vazia
	if(r == NULL) 
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
	if(bal < -1 && (strcmp(chave, (r->esq)->chave) > 0)){
		r->esq = rotEsq(r->esq);
		return rotDir(r);
	}
	//dir esq
	if(bal > 1 && (strcmp(chave, (r->dir)->chave) < 0)){
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
//função que deleta um nó(que eu nem usei pq criei uma função pra deletar a arv inteira de uma vez)
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
				*temp = *r;
				r = NULL;
			}
			else{	//caso tenha um filho
				//copia os conteúdos do filho não nulo
				*r = *temp;
				free(temp);
			}
		}
		else{
			//caso tenha 2 filhos, pega o menor nó da sub-árvore direita(sucessor inOrder)
			noh_t *temp = minNo(r->dir);
			//copia os dados do sucessor inOrder para o nó atual
			*r = *temp;
			free(temp);
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
	if(bal > 1 && (strcmp(chave, (r->dir)->chave) < 0)){
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

//desaloca tudo
void desaloca_tudo(noh_t *r){
	if(r != NULL){
		desaloca_tudo(r->esq);
		desaloca_tudo(r->dir);
		free(r->chave);
		free(r);
	}
}
//função main
int main(int argc, char *argv[]){

	//M, N, pontuação, hashes palavras escolhidas, resultados finais e árvore AVL;
	int M, N;		
	char palavra[MAX];
	noh_t *arv = NULL;
	//lendo o número de palavras e participantes
	scanf("%d%d", &M, &N);
	//as palavras serão gravadas em um vetor para serem consultadas
	//na hora de removê-las da árvore
	char **chaves = (char **) malloc(M * sizeof(char *));
    for(int i = 0; i < M; i++)
        chaves[i] = (char *) malloc(MAX * sizeof(char));
    //variável para guardar os pontos de cada palavra
    int pontos;
	//vetor para guardar os resultados;
	int resultados[N];
	for(int i = 0; i < N; i++)
		resultados[i] = 0;
	//lendo as palavras e suas pontuações
	for(int i = 0; i < M; i++){
		scanf("%s%d", chaves[i], &pontos);
		arv = insere(arv, chaves[i], pontos);
	}

	//lendo os textos e calculando as pontuações totais
	for(int i = 0; i < N; i++){
		noh_t *achou = NULL;
		while(palavra[0] != '.'){
			scanf("%s", palavra);
			//verifica se a palavra pontua, se não, subtrai 10 pontos
			achou = busca(arv, palavra);
			if(achou != NULL){
				resultados[i] += achou->ponto;
			}
            //depois de ter buscado pela palavra, se não achou, subtrai 10
            else{
				if(palavra[0] != '.'){
                	resultados[i] -= 10;
				}
			}
		}
		//ao final do while, o valor de palavra é '.', logo, temos que
		//mudar a palavra para que o novo while() seja capaz de rodar
        palavra[0] = '~';
	}

	//mostrando os resultados
	for(int i = 0; i < N; i++){
		printf("%d\n", resultados[i]);
	}

	//desalocando toda a memória alocada
	desaloca_tudo(arv);

	return 0;
}