#ifndef ESCULTURA_H
#define ESCULTURA_H

// Bibliotecas
#include <iostream>
#include "ObraDeArte.h"

// A classe Escultura esta organizado dentro do catalogo
using namespace catalogo;
using std::string;
using std::cout;
using std::endl;

class Escultura : public ObraDeArte{
  private:
    double altura;
  public:
    // construtor
    Escultura(string tit, string art, string mat, int an, double alt):ObraDeArte(tit, art, mat, an),altura(alt){}

    // Prototipação das funções
    double getAltura() const;
    void setAltura(double alt);
    int getCategoria() const;
    void imprimeFicha() const;
};
#endif