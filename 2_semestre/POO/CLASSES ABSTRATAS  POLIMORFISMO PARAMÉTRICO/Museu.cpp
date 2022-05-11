#include "Museu.h"

using std::string;
using std::cout;
using std::endl;
using std::vector;

//métodos get e set
string Museu::getNome() const{return nome;}
void Museu::setNome(string nom){nome = nom;}

//retorna quantidade de obras
int Museu::qtdeObras() const{return catalogo.size();}

//adiciona uma nova obra de arte ao catálogo e retorna um bool indicando sucesso ou falha
bool Museu::adicionaObra(ObraDeArte* obra){
  for(int i=0; i < qtdeObras(); i++){
    if(obra->getTitulo() == catalogo[i]->getTitulo()) return false;
  }
  catalogo.push_back(obra);
  return true;
}

//remove uma obra de arte ao catálogo e retorna um bool indicando sucesso ou falha
bool Museu::removeObra(string Titulo){
  for(int i=0; i<qtdeObras(); i++){
    if(catalogo[i]->getTitulo() == Titulo){
      catalogo.erase(catalogo.begin()+i);
      return true;
    }
  }
  return false;
}

//retorna um ponteiro para uma obra de arte específica
ObraDeArte* Museu::obtemObra(string titulo) const{
  for(int i=0; i<qtdeObras(); i++){
    if(catalogo[i]->getTitulo() == titulo) return catalogo[i];
  }
  return NULL;
} 

//retorna a quantidade de pinturas
int Museu::qtdePinturas() const{
  int nPinturas = 0;
  for(int i=0; i < qtdeObras(); i++){
    if(catalogo[i]->getCategoria() == 1)
      nPinturas++;
  }
  return nPinturas;
}  

//retorna a quantidade de esculturas
  int Museu::qtdeEsculturas() const{
  int nEsculturas = 0;
  for(int i=0; i < qtdeObras(); i++){
    if(catalogo[i]->getCategoria() == 2)
      nEsculturas++;
  }
  return nEsculturas;
}

//imprime todas as obras, ou todas as pinturas ou todas as esculturas dependendo do parâmetro
void Museu::imprime(int categoria) const{
  for(int i=0; i < qtdeObras(); i++){
    if(catalogo[i]->getCategoria() == categoria || categoria == 0){
      catalogo[i]->imprimeFicha();
    }
  }
}