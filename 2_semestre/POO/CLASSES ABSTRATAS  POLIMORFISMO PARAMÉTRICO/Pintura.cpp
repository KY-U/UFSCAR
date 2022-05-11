#include "Pintura.h"

//métodos get e set
string Pintura::getTipo() const{return tipo;}
void Pintura::setTipo(string tip){tipo = tip;}
int Pintura::getCategoria() const{return 1;}

// Impressão dos atributos
void Pintura::imprimeFicha() const{
  cout << "Categoria: Pintura" << endl;
  catalogo::ObraDeArte::imprimeFicha();
  cout <<"Tipo: " << getTipo() << endl << endl;
} 