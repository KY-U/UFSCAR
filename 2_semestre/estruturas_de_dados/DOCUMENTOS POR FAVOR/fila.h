#include <iostream>
#include "rg.h"
#ifndef FILA_H
#define FILA_H


class Fila {
  private:
    //Node para fila duplamente ligada contendo objetos de Pessoa como elemeto.
    struct node{
      Pessoa pessoa;
      struct node *next;
      struct node *prev;
    };
    node *inicio;
    node *fim;
  
  public:
    //tamanho da fila
    int tamanho = 0;

    Fila();
    ~Fila(); 
    int vazia();
    void insere(Pessoa);
    void remove();
    Pessoa primeiroElemento();
};

#endif
