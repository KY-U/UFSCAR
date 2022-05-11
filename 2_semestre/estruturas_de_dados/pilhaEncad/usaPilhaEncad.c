#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "pilhaEncad.h"

void popTudo(Pilha_t *s, int c){
    do{
        c = pop(s);
        printf("o termo que acabou de ser desempilhado foi o %c\n",c);
    }while(!empty(s));
}
void imprimeTopo(Pilha_t *s)
{
printf("%c", peek(s));
}
int main(){

    Pilha_t *s;
    int tam, c,cont=0,contadorExtra=0,conseguiu=0;
    char tecla;
    printf("Qual sera o tamanho da pilha?\n");
    scanf("%d",&tam);

    s = criaPilha();
    //preenchendo e printando uma pilha de tamanho definido
    do{
        push(s, rand());
        //printando toda a pilha
        printf("o elemento de indice %d da pilha eh ",tamanho(s)-1);
        imprimeTopo(s);
        printf("\n");
    }while(tamanho(s)!=tam);
    printf("\n");
    printf("Hora de destruir a pilha!\n\n");
    //dando "pop" em toda a pilha
    popTudo(s, c);
    free(s);
    printf("\n");
    printf("A pilha foi destruida!\n\n");
    printf("Digite uma tecla aleatoria no teclado! Sera que este programa consegue gerar, aleatoriamente, a tecla que voce digitou antes de atingir 100 caracteres?\n");
    scanf(" %c",&tecla);
    s = criaPilha();
    //preenchendo a pilha ate encontrar u certo char
    printf("\n");
    do{
        push(s, rand());
        imprimeTopo(s);
        printf(" ");
        if(peek(s) == tecla){
            conseguiu = 1;
            cont = 1;
        }
        contadorExtra++;
        if(contadorExtra==100){
            cont = 1;
        }
    }while(!cont);
    if(conseguiu){
        printf("O programa acertou na %dº tentativa!\n",tamanho(s));
    }
    else printf("Que pena! Chegamos ate o limite de 100 caracteres na pilha!");
    free(s);
    return 0;
}
