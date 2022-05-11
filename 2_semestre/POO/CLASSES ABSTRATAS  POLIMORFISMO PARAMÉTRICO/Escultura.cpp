#include "Escultura.h"

// métodos get e set
    double Escultura::getAltura() const{return altura;}
    void Escultura::setAltura(double alt){altura = alt;}
    int Escultura::getCategoria() const{return 2;}

    // função para imprimir os dados de um objeto escultura
    void Escultura::imprimeFicha() const{
      cout << "Categoria: Escultura" << endl;
      catalogo::ObraDeArte::imprimeFicha();
      cout <<"Altura: " << getAltura() << endl << endl;
    } 