#include <stdio.h>
#include <stdlib.h>

//busca sequencial iterativa
int buscaSeq(int v[], int n, int x, int *t){
    int i = 0;
    while(i < n && v[i] < x){
        i++;
        *t += 1;
    }
    if( i < n && v[i] == x){    
        *t += 1;
        return i;
    }
    else{
        *t += 1;
        return -1;
    } 
}

//busca binária recursiva
int buscaBin(int v[], int e, int d, int x, int *t){
    //define o meio do metor
    int m = (e + d)/2;
    //caso o último termo do vetor seja menor que o primeiro, não encontramos o termo no vetor
    if(d < e){
        *t += 1;
        return -1;
    }
    //se encontrarmos o termo, retornar seu índice
    if(v[m] == x){
        *t += 1;
        return m;
    }
    //senao, se o meio for menor que termo procurado, procuramos no subvetor da direita
    else if(v[m] < x){
        *t += 1;
        return buscaBin(v, m + 1, d, x, t);
    }
    //se o meio for maior que o termo procurado, procuramos no subvetor da esquerda
    else{
        *t += 1;
        return buscaBin(v, e, m - 1, x, t);
    }
}
int main(int argc, char *argv[]){
    
    //contadores de etapas
    int seq_temp = 0, bin_temp = 0;

    //criando o vetor sequencial e preenchendo-o até 99
    int vetor[100];
    for(int i = 0; i < 100; i++)
        vetor[i] = i;
    
    //realizando as buscas por 4:
    buscaSeq(vetor, 100, 4, &seq_temp);
    buscaBin(vetor, 0, 99, 4, &bin_temp);
    //print dos resultados
    printf("Para achar o termo 4:\nBusca sequencial precisou de %d etapas\nBusca binária precisou de %d etapas\n\n", seq_temp, bin_temp);
    //resetando os contadores de etapas:
    seq_temp = 0;
    bin_temp = 0;

    //realizando as buscas por 5:
    buscaSeq(vetor, 100, 5, &seq_temp);
    buscaBin(vetor, 0, 99, 5, &bin_temp);
    //print dos resultados
    printf("Para achar o termo 5:\nBusca sequencial precisou de %d etapas\nBusca binária precisou de %d etapas\n\n", seq_temp, bin_temp);
    //resetando os contadores de etapas:
    seq_temp = 0;
    bin_temp = 0;

    //realizando as buscas por 49:
    buscaSeq(vetor, 100, 49, &seq_temp);
    buscaBin(vetor, 0, 99, 49, &bin_temp);
    //print dos resultados
    printf("Para achar o termo 49:\nBusca sequencial precisou de %d etapas\nBusca binária precisou de %d etapas\n\n", seq_temp, bin_temp);
    //resetando os contadores de etapas:
    seq_temp = 0;
    bin_temp = 0;

    //realizando as buscas por 99:
    buscaSeq(vetor, 100, 99, &seq_temp);
    buscaBin(vetor, 0, 99, 99, &bin_temp);
    //print dos resultados
    printf("Para achar o termo 99:\nBusca sequencial precisou de %d etapas\nBusca binária precisou de %d etapas\n\n", seq_temp, bin_temp);

    return 0;
}