#ifndef DATAHORARIO_H
#define DATAHORARIO_H
// Bibliotecas
#include <iostream>
#include <string>
#include <cstring>
  
using namespace std;
  
// Protótipo função bissexto
bool bissexto(int);

// A classe faz parte do namespace poo
namespace poo{
  // Classe DataHorario
  class DataHorario{
  private:
  	int dia, mes, ano;
  	int segundo, minuto, hora;
  
  public:
  	// Construtor único
  	DataHorario(int Dia, int Mes, int Ano, int H, int Min, int Seg) {
  		if (H >= 0 && H <= 24) hora = H; // 0<=hora<24
  		else hora = 0;
  
  		if (Min >= 0 && Min <= 60) minuto = Min; // 0<=minuto<60
  		else minuto = 0;
  
  		if (Seg >= 0 && Seg <= 60) segundo = Seg; // 0<=segundo<60
  		else segundo = 0;
  
  		if (Ano > 0) ano = Ano; // Ano é um valor positivo
  		else ano = 1;
  
  		if (Mes > 0 && Mes <= 12) mes = Mes; // 1<=mes<=12
  		else mes = 1;
  
  		if (Dia > 0) {
  			switch (Mes){
  			case 2:
  				if (bissexto(Ano) && Dia <= 29) dia = Dia; // Bissextos tem 29 dias
  				else if (!bissexto(Ano) && Dia <= 28) dia = Dia;
  				else dia = 1; 
  				break;
  			case 4:
        case 6:
        case 9:
        case 11:
  				if (Dia <= 30) dia = Dia;
  				else dia = 1;
  				break;
  			case 1:
        case 3: 
        case 5: 
        case 7:
        case 8:
        case 10: 
        case 12:
  				if (Dia <= 31) dia = Dia;
  				else dia = 1;
  				break;
  		  }
      }
  		else dia = 1;
    }
  
  		// Destrutor
  		~DataHorario(){
  		}
  
  		// Protótipos funções Get
  		int getDia() const;
  		int getMes() const;
  		int getAno() const;
  		int getHora() const;
  		int getMinuto() const;
  		int getSegundo() const;
  
  		// Protótipos funções de sobrecarga
  		bool operator<(DataHorario&) const;
  		bool operator==(DataHorario&) const;
  		bool operator<=(DataHorario&) const;
  		bool operator!=(DataHorario&) const;
  		bool operator>(DataHorario&) const;
  	  bool operator>=(DataHorario&) const;
      friend ostream &operator<<(ostream &, DataHorario &);
  	  friend class Sessao &Sessao();
    };

  // Sobrecarga do operador de fluxo de saída
  ostream &operator<<(ostream &output, DataHorario &horario) {
    string nomeMes[12] = {"Janeiro", "Fevereiro", "Março", "Abril", "Maio", "Junho", "Julho", "Agosto", "Setembro", "Outubro", "Novembro", "Dezembro"};
  		
  	output << horario.dia << " de " << nomeMes[horario.getMes()-1] << " de " << horario.getAno() 
  	<< " - " << horario.getHora() << " hora(s), " << horario.getMinuto()
  	<< " minuto(s), " << horario.getSegundo() << " segundo(s), " << endl;
  	return output;
  }
}

using namespace poo;

// Funções get
int DataHorario::getDia() const {return dia;}
int DataHorario::getMes() const {return mes;}
int DataHorario::getAno() const {return ano;}
int DataHorario::getHora() const {return hora;}
int DataHorario::getMinuto() const {return minuto;}
int DataHorario::getSegundo() const {return segundo;}

// Funções de sobrecarga
// Horario < Horario
bool DataHorario::operator<(DataHorario &horario) const{
  if (this->ano < horario.getAno()) return true;
  else if (this->ano == horario.getAno()) {
  	if (this->mes < horario.getMes()) return true;
  	else if (this->mes == horario.getMes()) {
  	  if (this->dia < horario.getDia()) return true;
  		else if (this->dia == horario.getDia()) {
  			if (this->hora < horario.getHora()) return true;
  		  else if(this->hora == horario.getHora()){
          if (this->minuto < horario.getMinuto()) return true;
  				else if (this->minuto == horario.getMinuto()){
  					if (this->segundo < horario.getSegundo()) return true;
            else return false;
          }
          else return false;
  			}
        else return false;
  		}
      else return false;
  	}
    else return false;
  }
  else return false;
}

// Horario == Horario
bool DataHorario::operator==(DataHorario &horario) const{
  if (this->ano != horario.ano) return false;
  else if (this->mes != horario.mes) return false;
  else if (this->dia != horario.dia) return false;
  else if (this->hora != horario.hora) return false;
  else if (this->minuto != horario.minuto) return false;
  else if (this->segundo != horario.segundo) return false;
  else return true;
}

// Horario <= Horario 
bool DataHorario::operator<=(DataHorario &horario) const{
  return (*this < (horario) || *this == (horario));
}	

// Horario != Horario
bool DataHorario::operator!=(DataHorario &horario) const{
  return !(*this == (horario));
}

// Horario > Horario
bool DataHorario::operator>(DataHorario &horario) const{
  return !(*this <= (horario));
}

// Horario >= Horario
bool DataHorario::operator>=(DataHorario &horario) const{
  return (*this > (horario) || *this == (horario));
}
  
// Função bissexto para permitir a verificação
// e certificação de dia
bool bissexto(int a) {
  if (a % 4 == 0 && a % 100 != 0)
  	return true;
  else if (a % 4 == 0 && a % 100 == 0 && a % 400 == 0)
  	return true;
  else return false;
}
  
#endif
