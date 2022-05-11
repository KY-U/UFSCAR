#include "fila.h"

//Construtor da fila, iniciando-a vazia (início e fim apontam para null).
Fila::Fila(){
  inicio = nullptr;
  fim = nullptr;
}
//Devolve 1 se a fila estiver vazia e 0 se não.
int Fila::vazia(){
  if(fim == nullptr || inicio == nullptr)
    return 1;
  return 0;
}
//Insere elemento na fila.
void Fila::insere(Pessoa objeto){
  //Alocando memória.
  node *novo = new node;
  //Inserindo objeto passado como parâmetro.
  novo->pessoa = objeto;
  //Caso fila estaja vazia.
  if(vazia()){
    inicio = novo;
    fim = novo;
  }
  fim->next = novo;
  inicio->prev = novo;
  novo->prev = fim;
  novo->next = inicio;
  fim = novo;
  tamanho++;
}
//Remove o primeiro elemento da fila.
void Fila::remove(){
  if(vazia()){
    return;
  }
  else if(inicio == fim){
    free(inicio);
    inicio = fim = nullptr;
    return;
  }
  //Movendo início para o próximo elemento.
  node *temp = inicio;
  inicio = inicio->next;
  //Reconectando a Fila circular.
  inicio->prev = fim;
  fim->next = inicio;
  //Liberando a memória do primeiro elemento da fila.
  free(temp);
  tamanho--;
}
//Retorna o conteúdo do primerio elemento da fila.
Pessoa Fila::primeiroElemento(){
  return inicio->pessoa;
}
//Desaloca a memória de todos os elementos restantes na fila.
Fila::~Fila(){
  node *temp = fim;
  while(fim != inicio){
    temp = fim->prev;
    free(fim);
    fim = temp;
  }
  free(inicio);
}