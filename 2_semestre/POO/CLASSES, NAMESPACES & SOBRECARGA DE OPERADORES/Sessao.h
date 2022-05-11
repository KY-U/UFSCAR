#ifndef SESSAO_H
#define SESSAO_H

#include <iostream>
#include <string>
#include "Pessoa.h"
#include "DataHorario.h"

using namespace std;

void convertePoltrona(string, int&, int&);
namespace poo{
  class Sessao{
    friend ostream &operator<<(ostream&, Sessao&);
  
    private:
      string nomeSessao;
      DataHorario horarioSessao;
      Pessoa *espectador[15][14];
      
    public:
      // Construtor
      Sessao(string peca, DataHorario& data): nomeSessao(peca), horarioSessao(data){
        //atribuindo todos os valores da matriz para NULL
        for(int i = 0;i < 15;i++){
          for(int j = 0;j < 14;j++)
            espectador[i][j] = NULL;
        }
      }
      // Destrutor 
      ~Sessao(){
      } 

      // Protótipos das funções
      string proximoLivre();
      bool verifica(string);
      bool ocupa(string, Pessoa&);
      bool desocupa(string);
      int vagas();
  };
  // Sobrecarga do operador do fluxo de saída
  ostream &operator<<(ostream &cout, Sessao &S){
  string lista;
  // Nome da peça, data, lista de espectadores
  cout<<S.nomeSessao<<endl
  <<S.horarioSessao<<endl;
  
  string poltrona;
  for(int i = 0;i<15;i++){
    for(int j = 1; j <= 14;j++){
      if(S.espectador[i][j-1] != NULL){
        poltrona = char(i+65);
        poltrona += to_string(j);
        cout << "Poltrona: "<<poltrona << endl << *S.espectador[i][j-1] << endl;
      } 
    }
  }
  
  return cout;
}
}

using namespace poo;

// Retorna a primeira poltrona vazia
// Caso não haja nenhuma, retorna a string "cheio"
string Sessao::proximoLivre(){
  string poltrona;
  for(int i=0; i<15; i++){
    for(int j=1; j<=14; j++){
      if(espectador[i][j-1] == NULL){
        poltrona = char(i+65);
        poltrona += to_string(j);
        return poltrona;
      }
    }
  }
  return "cheio";
}

// Retorna true se uma poltrona estiver ocupada
// e false caso contrário
bool Sessao::verifica(string poltrona){
  int lin, col;
  convertePoltrona(poltrona, lin, col);
  if(espectador[lin][col] == NULL) return false;
  return true;
}
//ocupa uma poltrona vazia, retorna true caso a poltrona não esteja ocupada
// e false caso contrário
bool Sessao::ocupa(string poltrona, Pessoa &pessoa){
  int lin, col;
  convertePoltrona(poltrona, lin, col);
  
  if(!verifica(poltrona)){
    espectador[lin][col] = new Pessoa(pessoa.getNome(),pessoa.getCPF());
    return true;
  }
  else return false; 
}
//desocupa uma poltrona previamente ocupada, retorna true se a operação foi 
// bem-sucedida e false caso contrário
bool Sessao::desocupa(string poltrona){
  int lin, col;
  convertePoltrona(poltrona, lin, col);

  if(verifica(poltrona)){
    espectador[lin][col] = NULL;
    return true;
  }
  else return false;
}
//retorna a quantidade de vagas disponíveis
int Sessao::vagas(){
  int cont=0;
  for(int i=0; i<15; i++){
    for(int j=0; j<14; j++){
      if(espectador[i][j] == NULL) cont++;
    }
  }
  return cont;
}

//converte a string poltrona para dois int relativos à linha e coluna da poltrona na matriz
void convertePoltrona(string poltrona, int &linha, int &coluna){ 
  linha  = poltrona[0] - 'A';
  coluna = stoi(poltrona.substr(1)) - 1;
}

#endif
