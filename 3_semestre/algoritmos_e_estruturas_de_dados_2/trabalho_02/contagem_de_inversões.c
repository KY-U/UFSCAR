//AED 2 Trabalho 2 Distancia Genômica
//Caio Ueda Sampaio 802215 Turma B

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

unsigned long long contaInv(int *, int);
unsigned long long mergeSort(int *, int *, int, int);
unsigned long long intercala(int *, int *, int, int, int);

//Funcao envelope pra simplicidade
unsigned long long contaInv(int *v, int n){
    int *aux = (int *) malloc(n * sizeof(int));
    unsigned long long num_inv = mergeSort(v, aux, 0, n - 1);
    free(aux);
    return num_inv;
}

//contagem de inversão utilizando 
//o algoritmo de mergesort
unsigned long long mergeSort(int *v, int *aux, int esq, int dir){
    int meio;
    unsigned long long num_inv = 0;
    if(esq < dir){
        meio = (esq + dir) / 2;
        num_inv += mergeSort(v, aux, esq, meio);
        num_inv += mergeSort(v, aux, meio + 1, dir);
        num_inv += intercala(v, aux, esq, meio + 1, dir);
    }
    return num_inv;
}

//contagem das intercalações que ocorrem
//entre uma partição e outra durante a 
//fase de intercalação
unsigned long long intercala(int *v, int *aux, int esq, int meio, int dir){
    int i = esq;
    int j = meio;
    int k = esq;    //índice do subvetor resultante;
    unsigned long long num_inv = 0;
    while((i <= meio - 1) && (j <= dir)){
        if(v[i] <= v[j]){
            aux[k++] = v[i++];
        }
        else{
            aux[k++] = v[j++];
            num_inv += meio - i;
        }
    }
    while(i <= meio - 1) aux[k++] = v[i++];
    while(j <= dir) aux[k++] = v[j++];
    for(i = esq; i <= dir; i++)
        v[i] = aux[i];
    return num_inv;
}
void imprime(int v[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", v[i]);
    printf("\n");
}

int main(int argc, char *argv[])
{
    char file_name[MAX];
    FILE *entrada;
    int i, n;

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
    // lendo do arquivo da instância
    fscanf(entrada, "%d", &n);
    int *v = (int *)malloc(n * sizeof(int));
    for (i = 0; i < n; i++)
        fscanf(entrada, "%d", &v[i]);
    // imprime(v, n);

    // printf("%I64u\n", num_inv);
    unsigned long long num_inv = contaInv(v, n);
    printf("%llu\n", num_inv);

    fclose(entrada);
    
    return 0;
}
