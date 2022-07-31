//Competição Literária		Trabalho de AED 2
//Caio Ueda Sampaio			Turma B		802215

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

//implementando skip-list
typedef struct noh{
    char palavra[40];

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

	//lendo as palavras e suas pontuações
	for(int i = 0; i < num_pal; i++)
		scanf("%s %d", palavra, &pont);

	//lendo os textos e calculando as pontuações totais
	for(int i = 0; i< num_part; i++){
		noh_t *p;
		while(palavra[0] != '.'){
			scanf("%s", palavra);
			//verifica na skipllist se a palavra está presente
		}
	}
	//mostrando os resultados
	for(int i = 0; i < num_part; i++){
		printf("%d\n", resultados[i]);
	}
	return 0;
}