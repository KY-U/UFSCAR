#ifndef MUSEU_H
#define MUSEU_H

#include <iostream>
#include <vector>
#include "Pintura.h"
#include "Escultura.h"

using std::vector;

namespace catalogo{
  class Museu{
    private: 
      string nome;
      vector<ObraDeArte*> catalogo;
    public:
      //construtor
      Museu(string nom):nome(nom){}

      // Protootipação das funções
      string getNome() const;
      void setNome(string nom);

      int qtdeObras() const;
      int qtdePinturas() const;
      int qtdeEsculturas() const;

      bool adicionaObra(ObraDeArte* obra);
      bool removeObra(string Titulo);
      ObraDeArte* obtemObra(string titulo) const;

      void imprime(int categoria) const;
  };
}
#endif