#ifndef  PESSOA_H
#define  PESSOA_H

// Bibliotecas
#include <iostream>
#include <string>

// A classe está no namespace poo
namespace poo{
  // Classe Pessoa
  class Pessoa{
  private:
    string nome;
    string CPF;
  public:
    // Construtor
    Pessoa(string Nome, string cpf): nome(Nome), CPF(cpf){
    }

    // Destrutor
    ~Pessoa(){}

    // Protótipos funções get
    string getNome() const;
    string getCPF() const;

    // Protótipo de sobrecaraga de operação de fluxo de saída
    friend ostream &operator<<(ostream&, Pessoa&);
  };

  // sobrecarga do operador de fluxo de saída
  ostream &operator<<(ostream &cout, Pessoa &P){
    cout <<  "Nome: " << P.getNome() 
    << "\nCPF: " << P.getCPF() << endl; 
    return cout;
  }
}

using namespace poo;

// Funções get
string Pessoa :: getNome()const {return nome;}
string Pessoa :: getCPF()const  {return CPF;}

#endif