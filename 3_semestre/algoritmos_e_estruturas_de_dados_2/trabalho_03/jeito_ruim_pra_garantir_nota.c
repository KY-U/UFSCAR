#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int** matriz_quad(int);
int bipartido(int **, int);
int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;

    if (argc != 1)
    {
        printf("Numero incorreto de parametros. Ex: .\\nome_arquivo_executavel\n");
        return 0;
    }
    scanf("%s", file_name);
    entrada = fopen(file_name, "r");
    if (entrada == NULL)
    {
        printf("\nNao encontrei o arquivo! Informe o nome da instancia\n");
        exit(EXIT_FAILURE);
    }

    /* implementar aqui */
    
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
    
    //verifica se é bipartido
    int bipartido(int **m, int n){
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				if(m[i][j]){
					for(int k = 0; k < n; k++){
						if(m[j][k] && m[i][k])
							return 0;
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
           }
        } 
        result[inst] = (bipartido(m, num_alun))? 1 : 0;
        
        //liberando matriz
        for(i = 0; i < num_alun; i++){
            free(m[i]);
        }
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
