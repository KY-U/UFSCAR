#ifndef PINTURA_H
#define PINTURA_H 

// Bibliotecas
#include <iostream>
#include "ObraDeArte.h"

// A classe está organizada dentro de catálogo
using namespace catalogo;
using std::string;
using std::cout;
using std::endl;

class Pintura : public ObraDeArte{
  private:
    string tipo;
  public:
    //construtor
    Pintura(string tit, string art, string mat, int an, string tip):ObraDeArte(tit, art, mat, an),tipo(tip){}

    //Prototipação das funções
    string getTipo() const;
    void setTipo(string tip);
    int getCategoria() const;

    void imprimeFicha() const;
};
#endif