#ifndef ESTUDANTE_H
#define ESTUDANTE_H

// Bibliotecas
#include <iostream>
#include <string>
#include "Pessoa.h" // A classe herda da classe Pessoa

using namespace std;

// Classe Estudante
class Estudante: public Pessoa{
  
  // Protótipo de sobrecarga de operação de fluxo de saída
  friend ostream &operator<<(ostream&, Estudante&);

  private:
    int RA;
    double n1, n2, t1, t2;

  public:
    // Construtor
    Estudante(string Nome, string cpf, int ra, double n1, double n2, double t1, double t2):Pessoa(Nome, cpf), RA(ra), n1(n1), n2(n2), t1(t1), t2(t2){
    }

     // Destrutor
    ~Estudante(){
    }

    // Protótipos 
    int getRA() const;
    double media();
    bool aprovado();
    bool sac();
    double notaSAC();
};
  
// Função get
int Estudante :: getRA()const {return RA;}

// Calcula a média final do estudante
double Estudante :: media(){
  double mp, mt, mf;
  mp = (n1 + n2)/2;
  mt = (t1 + t2)/2;
  mf = (8*mp + 2*mt)/10;

  return mf;
}

// Retorna true se o estudante foi aprovado
bool Estudante :: aprovado(){
  if (media() >= 6) return true;
  else return false;
}

// Retorna true se o estudante estiver apto
// para fazer a avaliação complementar
bool Estudante :: sac(){
  if(media()>=5 && media()<6) return true;
  else return false;
}

// Calcula a nota necessária no exame complementar
// para a aprovação
double Estudante :: notaSAC(){
  if(sac()) return 12-media();
  else return 0;
}; 

// Sobrecarga do operador de fluxo de saída
ostream &operator<<(ostream &cout, Estudante &E){
  cout << "Nome: " << E.getNome() 
  << "\nCPF: " << E.getCPF() 
  << "\nMédia: " << E.media() << endl;
  return cout;
}

#endif
