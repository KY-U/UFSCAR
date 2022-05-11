#ifndef PROFESSOR_H
#define PROFESSOR_H

// Bibliotecas
#include <iostream>
#include <string>
#include "Pessoa.h"// A classe herda da classe pessoa

using namespace std;

class Professor: public Pessoa{
  private:
    string nome;
    string CPF;
    string universidade;

  public:
    // Construtor
    Professor(string Nome, string cpf, string uni):Pessoa(Nome, cpf){
      universidade = uni;
    }

    // Destrutor
    ~Professor(){
    }

    // Protótipo função get
    string getUniversidade();

    // Protótipo de sobrecarga de operação de fluxo de saída
    friend ostream &operator<<(ostream&, Professor&);
};

// Função get
string Professor::getUniversidade() {return universidade;}

// Sobrecarga do operador de fluxo de saída
ostream &operator<<(ostream &cout, Professor &P){
  cout << "Nome: " << P.getNome() 
  << "\nCPF: " << P.getCPF() 
  << "\nUniversidade: " <<  P.getUniversidade() << endl;
  return cout;
}

#endif