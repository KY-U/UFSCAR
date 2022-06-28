//Caio Ueda Sampaio 802215
//Programa que conta quantos processos e threads a máquina é capaz de criar

//bibliotecas
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <pthread.h>
#include <time.h>

//tarefa q nao faz nada pra servir de parametro pra create_thread()
void * tarefa(void *p){
    sleep(10);
    pthread_exit(0);
}
int main(int argc, char **argv){

    //contando os processos
    clock_t ini, fim;
    double tempo_proc, tempo_thread;
    int quant = 0, erro = 0, quant_proc;
    pid_t resultado;

    ini = clock();
    while(!erro){
        //processo nao foi criado
        if((resultado = fork()) == -1){
            printf("Criacao falhou no processo %d: %s\n", quant, strerror(errno));
            erro = 1;
            exit(0);
        }
        //proceso foi criado
        else{
            quant++;
            if(quant == 1000) fim = clock();
            printf("Criado processo %d de pid %d\n", quant, getpid());
            //interrompendo o loop no processo dos filhos
            if(resultado == 0){ 
                //sleep(10);    //da ruim
                break;
            }
        }
    }
    quant_proc = quant;
    tempo_proc = ((double) (fim - ini) / CLOCKS_PER_SEC);

    //contando as threads
    quant = erro = 0;
    ini = clock();
    pthread_t th;
    while(!erro){
        //thread nao foi criada
        if((pthread_create(&th, NULL, tarefa, NULL)) != 0){
            printf("Criacao falhou na thread %d: %s\n", quant, strerror(errno));
            erro = 1;
            //exit(0);  //da ruim
        }
        //thread foi criada
        else{
            quant++;
            if(quant == 1000) fim = clock();
            printf("Criado thread %d PID %d\n", quant, getpid());
        }
    }
    tempo_thread = ((double) (fim - ini) / CLOCKS_PER_SEC);

    //mostrando os resultados finais
    printf("Foi criado um total de %d processos\n", quant_proc);
    printf("Foi criado um total de %d threads\n", quant);
    printf("Os primeiros 1000 processos e threads, demoraram, respectivamente:\n%f e %f segundos\n", tempo_proc, tempo_thread);

    return 0;
}