#include <iostream>

#include "rg.h"
#include "fila.h"

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char *argv[]){
  //seed
  srand(time(0));
  //nomes de pessoas sempre com tamanho 10
  string nomesMasc[5];
  string nomesFem[5];
  //nomes de naturalidade com tamanho 25
  string natBr[5];
  string natG[5];
  //fotos
  string fotosMasc[5];
  string fotosFem[5];
  atribuiStrings(nomesMasc, nomesFem, natBr, natG, fotosMasc, fotosFem);
  //início do jogo
  int ligado = 1;
    //imprime o título do jogo uma vez
    printTitulo();
    printInstrucoes();
    do{
    //enquanto estiver dentro do game loop, sempre pergunta se o jogador que jogar de novo ou fechar o jogo
    printJogarNov();
    int acao = 0;
    while(acao != 1 && acao != 2){
      cin>>acao;
      if(acao == 2)
        exit(0);
      else if(acao != 1)
        cout<<"tecla inválida, pressione 1 para jogar ou 2 para fechar o jogo"<<endl;
    }
    //cria um número de pessoas aleatório
    int nrPessoas = 5;
    Fila fila;
    //insere pessoas na fila
    for(int i = 0; i < nrPessoas; i++){
      Pessoa x(nomesMasc, nomesFem, natBr, natG, fotosMasc, fotosFem);
      fila.insere(x);
    }
    //contador de indagacoes erradas
    int jogEr = 0;
    //contador de pessoas erradas permitidas
    int passouEr = 0;
    while(!fila.vazia()){
      //variáveis
      int acao;
      int prosseguir = 0;
      int inconsistencia = 0;
      //quantas pessoas restam na fila?
      cout<<"\nResta(m) "<<fila.tamanho<<" pessoa(s) na fila\n"<<endl;
      //imprimindo a foto da pessoa
      fila.primeiroElemento().printFoto(fotosMasc, fotosFem);
      cout<<endl;
      //imprimindo o rg da pessoa
      fila.primeiroElemento().printRg();
      cout<<endl;
      while(prosseguir == 0){
        cout<<"Indagar sobre o nome: 1\n"
        <<"Indagar sobre o nome do pai: 2\n"
        <<"Indagar sobre o nome da mãe: 3\n"
        <<"Indagar sobre a naturalidade 4\n"
        <<"Indagar sobre a data de nascimento: 5\n"
        <<"Permitir que a pessoa passe: 6\n";
        if(inconsistencia > 0)
          cout<<"Rejeitar a entrada: 7\n";
        cout<<endl;
        cin>>acao;
        switch(acao){
          case 1:
            if(fila.primeiroElemento().nomeEr){
              cout<<"Esse nome não me parece ser o seu\n\n";
              inconsistencia++;
            }
            else{
              cout<<"hm... parece tudo certo\n\n";
              jogEr++;
            }
            break;
          case 2:
            if(fila.primeiroElemento().paiEr){
              cout<<"Esse nome não me parece ser o nome de um pai\n\n";
              inconsistencia++;
            }
            else{
              cout<<"hm... parece tudo certo\n\n";
              jogEr++;
            }
            break;
          case 3:
            if(fila.primeiroElemento().maeEr){
              cout<<"Esse nome não me parece ser o nome de uma mãe\n\n";
              inconsistencia++;
            }
            else{
              cout<<"hm... parece tudo certo\n\n";
              jogEr++;
            }
            break;
          case 4:
            if(fila.primeiroElemento().natEr){
              cout<<"Esse local nem é no Brasil!\n\n";
              inconsistencia++;
            }
            else{
              cout<<"hm... parece tudo certo\n\n";
              jogEr++;
            }
            break;
          case 5:
            if(fila.primeiroElemento().dataEr){
              cout<<"Essa data nem existe!\n\n";
              inconsistencia++;
            }
            else{
              if(fila.primeiroElemento().nascEr){
                cout<<"Impossível você ter nascido nesta data!\n\n";
                inconsistencia++;
              }
              else{
                cout<<"hm... parece tudo certo\n\n";
                jogEr++;
              }
            }
            break;
          case 6:
            if(fila.primeiroElemento().nomeEr || fila.primeiroElemento().paiEr || fila.primeiroElemento().maeEr|| fila.primeiroElemento().natEr || fila.primeiroElemento().dataEr || fila.primeiroElemento().nascEr){
              passouEr++;
            }
            prosseguir++;
            fila.remove();
            cout<<"Pode passar\n";
            break;
          case 7:
            if(inconsistencia > 0){
              cout<<"Você não pode entrar\n\n";
              prosseguir++;
              fila.remove();
            }
            else
              cout<<"Tecla inválida\n\n";
            break;
          default:
            cout<<"Tecla inválida\n\n";
        }   
      }
    }
    if(passouEr > nrPessoas / 4){
      cout<<"Você deixou passar muitas pessoas indevidas, por isso foi demitido\n";
    }
    else if(jogEr > nrPessoas / 2)
      cout<<"Você até que não permitiu a entrada de várias pessoas indevidas, mas cometeu muitas indagações desnecessárias e errôneas, não precisamos de um profissional incompetente como você\n";
    else
      cout<<"Bom trabalho, ganhastes o título de funcionário do mês\n";
    }while(ligado);
  return 0;
}