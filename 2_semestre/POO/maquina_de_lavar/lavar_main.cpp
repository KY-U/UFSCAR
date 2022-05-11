#include <iostream>

#include "lavar.h"

using std::cout;
using std::endl;
using std::string;

int main(){
    
    MaquinaDeLavar maq2("brasteeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeemp",0,-7);

    //mostrando os atributos da maquina 2
    cout<<"maquina criada com o construtor especificando parametros invalidos:"<<endl;
    cout<<"o modelo da maquina eh "<<maq2.getModelo()<<endl;
    cout<<"o volume da maquina eh "<<maq2.getVolume()<<endl;
    cout<<"a massa da maquina eh "<<maq2.getMassa()<<endl;
    cout<<endl;

    MaquinaDeLavar maq1;

    //mostrando os atributos da maquina 1
    cout<<"maquina criada com o construtor generico:"<<endl;
    cout<<"o modelo da maquina eh "<<maq1.getModelo()<<endl;
    cout<<"o volume da maquina eh "<<maq1.getVolume()<<endl;
    cout<<"a massa da maquina eh "<<maq1.getMassa()<<endl;
    cout<<endl;

    

    MaquinaDeLavar maq3("brastemp",1,34);
    
    //mostrando os atributos da maquina 3
    cout<<"maquina criada com o construtor especificando parametros validos"<<endl;
    cout<<"o modelo da maquina eh "<<maq3.getModelo()<<endl;
    cout<<"o volume da maquina eh "<<maq3.getVolume()<<endl;
    cout<<"a massa da maquina eh "<<maq3.getMassa()<<endl;
    cout<<endl;

    cout<<"iniciando o ciclo de lavagem da maquina 1\n";
    maq1.setEstado(true);
    maq1.IniciarCiclo();
    
    cout<<"iniciando o ciclo de lavagem da maquina 2\n";
    maq2.setEstado(true);
    maq2.IniciarCiclo();

    cout<<"iniciando o ciclo de lavagem da maquina 3\n";
    maq3.setEstado(true);
    maq3.IniciarCiclo();
    
    cout<<"Percebe-se que, apesar de a segunda maquina ter sido iniciada com os parametros do construtor contendo valores invalidos i.e. nome do modelo excedendo 20 caracteres, volume 0 e massa negativa, seus atributos ainda foram inicializados com valores validos, alem disso, os ciclos de lavagem de todas as 3 maquinas funcionaram corretamente indicando que o programa exerce a protecao de dados com excelencia"<<endl;
    
    return 0;
}
