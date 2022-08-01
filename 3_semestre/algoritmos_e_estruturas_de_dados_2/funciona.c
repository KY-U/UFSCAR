
//Competição Literária		Trabalho de AED 2
//Caio Ueda Sampaio			Turma B		802215

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 40

//função main
int main(int argc, char *argv[]){
	
	//M, N, pontuação, hashes palavras escolhidas, resultados finais e árvore AVL;
	int M, N;		
	char palavra[MAX];
	//lendo o número de palavras e participantes
	scanf("%d%d", &M, &N);
	//as hashs das palavras serão gravadas em um vetor para serem consultadas
	//na hora de removê-las da árvore
	char **chaves = (char **) malloc(M * sizeof(char *));
    for(int i = 0; i < M; i++)
        chaves[i] = (char *) malloc(MAX * sizeof(char));
    //vetor para guardar os pontos de cada palavra
    int pontos[M];
    for(int i = 0; i < M; i++){
        pontos[i] = 0;
    }
	//vetor para guardar os resultados;
	int resultados[N];
	for(int i = 0; i < N; i++)
		resultados[i] = 0;
	//lendo as palavras e suas pontuações
	for(int i = 0; i < M; i++){
		scanf("%s%d", chaves[i], &pontos[i]);
	}

	//lendo os textos e calculando as pontuações totais
	for(int i = 0; i < N; i++){
		while(palavra[0] != '.'){
			scanf("%s", palavra);
			//verifica se a palavra pontua, se não, subtrai 10 pontos
            int achou = 0;
            for(int j = 0; j < M; j++){
                if(strcmp(palavra, chaves[j]) == 0){
                    achou = 1;
                    resultados[i] += pontos[j];
                    //printf("\nsomou a palavra %s de %d pontos, total %d pontos", palavra, pontos[j], resultados[i]);
                }
            }
            //depois de ter varrido o vetor de palavras, se não achou, subtrai 10
            if(!achou && (palavra[0] != '.')){
                resultados[i] -= 10;
                //printf("\nsubtraiu 10 pela palavra %s, total %d", palavra, resultados[i]);
            }
		}
		//mudando a palavra para que o novo while() seja capaz de rodar
        palavra[0] = '~';
	}

	//mostrando os resultados
	for(int i = 0; i < N; i++){
		printf("%d\n", resultados[i]);
	}

	return 0;
}