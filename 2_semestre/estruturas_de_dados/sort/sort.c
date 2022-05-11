#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void insertionSort(int v[], int n){
    /*versao básica sem otimizar
    int aux, i, j;
    //percorre o vetor inteiro
    for(i = 1; i < n; i++){
        aux = v[i];
        //percorre o vetor de trás pra frente para cada membro do vetor até encontrar sua posição correta
        for(j = i - 1; i >= 0 && aux < v[j]; i--)
            v[j + 1] = v[j];
        //após achar a posição correta, insere;
        v[j + 1] = aux;
    }*/

    //versão otimizada que antes delimita um prefixo com os menores termos para começãr a ordenação depois desse prefixo
    int aux, i, j;
    //para começar a partir de um prefixo com os menores elementos do vetor:
    j = n - 1;
    for(i = n - 1; i > 0; i--)
        if(v[i - 1] > v[i]){
            aux = v[i];
            v[i] = v[i - 1];
            v[i - 1] = aux;
            j = i;
        }
    //ordenação de fato
    for(j++; j < n; j++){
        aux = v[j];
        //percorre o subvetor do final para o início para encontrar a posição correta
        for(i = j - 1; aux < v[i]; i--)
            //desloca os termos maiores que o aux para a direita
            v[i + 1] = v[i];
        //após achar a posição correta, insere;
        v[i + 1] = aux;
    }
}
void selectionSort(int v[], int  n){
    int aux, indMin, i, j;
    for(i = 0; i < n - 1; i++){
        //acha o menor elemento em dado subvetor
        indMin = i;
        for(j = i + 1; j < n; j++)
            if(v[j] < v[indMin])
                indMin = j;
        //após achar o termo mínimo, o coloca no limiar do subvetor já ordenado
        aux = v[i];
        v[i] = v[indMin];
        v[indMin] = aux;
    }
}
void bubbleSort(int v[], int n){
    //bubblesort otimizado
    int aux, i, j, lastInvert, limDir;
    limDir = n;
    for(j = 0; j < n; j++){
        lastInvert = 0;
        for(i = 1; i < limDir; i++)
            //se o termo esquerdo da "bolha" for maior que o direito, trocam-se os termos
            if(v[i - 1] > v[i]){
                aux = v[i - 1];
                v[i - 1] = v[i];
                v[i] = aux;
                lastInvert = i;
            }
        //quando possível, o limite do caminho total da "bolha" é diminuído para otimização
        limDir = lastInvert;
    }
}
int main(int argc, char **argv){
    //marcadores de tempo
    srand(time(0));
    clock_t start, end;
    long double insertTime, selectTime, bubbleTime;   

    //preenchendo 3 vetores com os mesmos números aleatórios
    int tamanho = 30;
    int v1[tamanho], v2[tamanho], v3[tamanho];
    for(int i = 0; i < tamanho; i++){
        v1[i] = rand() % 30;
        v2[i] = v1[i];
        v3[i] = v1[i];
    }
    //mostrando o vetor antes de ordenar
    printf("vetor antes de ordenar:\n");
    for(int i = 0; i < tamanho; i++)
        printf("%d ",v1[i]);
    printf("\n\n");
    //realizando as ordenações e contando o tempo de execução
    start = clock();
    insertionSort(v1, tamanho);
    end = clock();
    insertTime = (long double)(end - start) / CLOCKS_PER_SEC;

    start = clock();
    selectionSort(v2, tamanho);
    end = clock();
    selectTime =(long double) (end - start) / CLOCKS_PER_SEC;

    start = clock();
    bubbleSort(v3, tamanho);
    end = clock();
    bubbleTime =(long double) (end - start) / CLOCKS_PER_SEC;

    printf("vetor depois do insertionSort:\n");
    for(int i = 0; i < tamanho; i++)
        printf("%d ",v1[i]);
    printf("\n");

    printf("vetor depois do selectionSort:\n");
    for(int i = 0; i < tamanho; i++)
        printf("%d ",v2[i]);
    printf("\n");

    printf("vetor depois do bubbleSort:\n");
    for(int i = 0; i < tamanho; i++)
        printf("%d ",v3[i]);
    printf("\n\n");

    //printando os resultados
    printf("Para um mesmo vetor desordenado:\n\n");
    printf("Tempo de insertionSort : %Lf\n", insertTime);
    printf("Tempo de selectionSort : %Lf\n", selectTime);
    printf("Tempo de bubbleSort : %Lf\n", bubbleTime);

    return 0;
}