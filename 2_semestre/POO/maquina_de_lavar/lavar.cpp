#include <iostream>
//#include <string>

using std::cout;
using std::endl;
using std::string;

#include "lavar.h"

MaquinaDeLavar::MaquinaDeLavar(){
    modelo = "generico";
    volume = 0.03;
    massa = 30;
    estado = false;
    etapa = "inerte";
}
MaquinaDeLavar::MaquinaDeLavar(string mod, double vol, double mas){
    setModelo(mod);
    setVolume(vol);
    setMassa(mas);
    estado = false;
    etapa = "inerte";
}
void MaquinaDeLavar::IniciarCiclo(){
    setEtapa("lavando");
    Molho();
    Lavar();
    Centrifugar();
    setEtapa("inerte");
}
string MaquinaDeLavar::getModelo()const{
    return modelo;
}
double MaquinaDeLavar::getVolume()const{
    return volume;
}
double MaquinaDeLavar::getMassa()const{
    return massa;
}
string MaquinaDeLavar::getEtapa()const{
    return etapa;
}
bool MaquinaDeLavar::getEstado()const{
    return estado;
}
void MaquinaDeLavar::setEstado(bool estad){
    estado = estad;
}
void MaquinaDeLavar::setEtapa(string etap){
    if(etap == "lavando" || etap == "molho" || etap == "centrifugando"){
        etapa = etap;
    }
    else etapa = "inerte";
}
void MaquinaDeLavar::setModelo(string mod){
    if(mod.length() <=30){
        modelo = mod;
    }
    else{
        modelo = mod.substr(0,30);
        cout <<"nome excessivamente grande"<<endl;
    }
}
void MaquinaDeLavar::setVolume(double vol){
    if(vol > 0){
    volume = vol;
    }
    else volume = 0.03;
}
void MaquinaDeLavar::setMassa(double mas){
    if(mas > 0){
    massa = mas;
    }
    else massa = 30;
}
void MaquinaDeLavar::Lavar(){
    if(getEstado()){
        for(int i=0; i<5;i++){
            cout<<"...lavando..."<<endl;
        }
    }
}
void MaquinaDeLavar::Molho(){
    if(getEstado()){
        for(int i=0; i<5;i++){
            cout<<"...deixando de molho..."<<endl;
        }
    }
}
void MaquinaDeLavar::Centrifugar(){
    if(getEstado()){
        for(int i=0; i<5;i++){
            cout<<"...centrifugando..."<<endl;
        }
        Alarme();
    }
}
void MaquinaDeLavar::Alarme(){
    cout<<"Acabou!\n"<<endl;
}