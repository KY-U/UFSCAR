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
#include <sys/wait.h>
#include <syscall.h>

//tarefa que nao faz nada pra servir de parametro pra create_thread()
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
            break;
        }
        //proceso foi criado
        //processo pai
        if(resultado != 0){
            quant++;
            printf("Criado processo %d de pid %d\n", quant, resultado);
        }
        //processo filho
        else{
            //interrompendo o loop no processo dos filhos 
            sleep(10);    
            exit(0);
        }
    }
    fim = clock();
    quant_proc = quant;
    tempo_proc = ((double) (fim - ini) / CLOCKS_PER_SEC);

    //esperando todos os processos encerrarem
     for(int i = 0; i < quant; i++){
        wait(NULL);
    }

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
            if(quant == quant_proc) fim = clock();
            printf("Criado thread %d PID %ld\n", quant, pthread_self());       //Tentei printar tanto o LWP ID syscall(SYS_gettid)
        }                                                                      //quanto o POSIX ID pthread_self() ambos mostram o mesmo ID toda vez
    }
    tempo_thread = ((double) (fim - ini) / CLOCKS_PER_SEC);

    //mostrando os resultados finais
    printf("Foi criado um total de %d processos\n", quant_proc);
    printf("Foi criado um total de %d threads\n", quant);
    printf("Os primeiros %d processos e threads, demoraram, respectivamente:\n%f e %f segundos\n",quant_proc, tempo_proc, tempo_thread);

    return 0;
}