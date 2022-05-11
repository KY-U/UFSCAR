/*
  G4 - GRUPO 13
    Arthur Takahiro Virgolino Nishimura - 800707
    Caio Ueda Sampaio - 802215
    Guilherme Luis Santos de Carvalho - 801235
    Rafael Martins Cavalheiro Andrade - 800446
    Vitor Gabriel Orsin - 801575
*/

#ifndef OBRADEARTE_H
#define OBRADEARTE_H

// Bibliotecas
#include <iostream>

using std::string;
using std::cout;
using std::endl;

// A classe está organizada dentro de catálogo
namespace catalogo{
  class ObraDeArte{
    private:
      string titulo;
      string artista;
      string material;
      int ano;
    public:
      //construtor
      ObraDeArte(string &tit, string &art, string &mat, int an){
        titulo = tit;
        artista = art;
        material = mat;
        ano = an;
      }

      // Funções virtuais
      virtual int getCategoria() const = 0;
      virtual void imprimeFicha() const{
        cout << "Titulo: " << titulo << endl
        << "Artista: " << artista << endl
        << "Material " << material << endl
        << "Ano: " << ano << endl;
      };

      // Prototipação das funções
      string getTitulo() const;
      void setTitulo(string tit);

      string getArtista() const;
      void setArtista(string art);

      string getMaterial() const;
      void setMaterial(string mat);

      int getAno() const;
      void setAno(int an);
  };
}

#endif
