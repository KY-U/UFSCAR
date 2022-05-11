#include "ObraDeArte.h"

using namespace catalogo;

// Funções get e set
string ObraDeArte::getTitulo() const {return titulo;}
void ObraDeArte::setTitulo(string tit){titulo = tit;}

string ObraDeArte::getArtista() const {return artista;}
void ObraDeArte::setArtista(string art){artista = art;}

string ObraDeArte::getMaterial() const {return material;}
void ObraDeArte::setMaterial(string mat){material = mat;}

int ObraDeArte::getAno() const {return ano;}
void ObraDeArte::setAno(int an){ano = an;}