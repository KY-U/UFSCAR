#include "DataHorario.h"
#include "Estudante.h"
#include "Pessoa.h"
#include "Professor.h"
#include "Sessao.h"
#include <iostream>
#include <string>

using namespace std;
using namespace poo;

void imprime(Estudante& estudante) {
    cout << estudante;
    cout << "[Final] ";
    if (estudante.aprovado()) {
        cout << "Estudante aprovado" << endl;
    } else if (estudante.sac()) {
        cout << "(SAC) Nota mínima: " << estudante.notaSAC() << endl;
    } else {
        cout << "Estudante reprovado." << endl;
    }
}

int main() {

    Pessoa p1("Pedro", "123.456.789-01");
    cout << p1 << endl;

    Estudante e1("Ana", "111.111.111-11", 800001, 3, 3, 7, 8);
    imprime(e1);
    cout << endl;

    Estudante e2("Beto", "222.222.222-22", 800002, 6, 5, 7, 8);
    imprime(e2);
    cout << endl;

    Estudante e3("Carlos", "333.333.333-33", 800003, 7, 8, 7, 8);
    imprime(e3);
    cout << endl;

    Professor p2("David", "444.444.444-44", "UFSCar");
    cout << p2 << endl;

    DataHorario dh1(10, 3, 2022, 15, 57, 10);
    cout << dh1;

    DataHorario dh2(10, 3, 2022, 15, 57, 10);
    cout << dh2;

    DataHorario dh3(10, 3, 2022, 21, 00, 00);
    cout << dh3;

    cout << boolalpha << endl;

    cout << "dh1 <  dh2 " << (dh1 < dh2) << endl;
    cout << "dh1 <= dh2 " << (dh1 <= dh2) << endl;
    cout << "dh1 == dh2 " << (dh1 == dh2) << endl;
    cout << "dh1 != dh2 " << (dh1 != dh2) << endl;
    cout << "dh1 >= dh2 " << (dh1 >= dh2) << endl;
    cout << "dh1 >  dh2 " << (dh1 > dh2) << endl;

    cout << endl;

    cout << "dh1 <  dh3 " << (dh1 < dh3) << endl;
    cout << "dh1 <= dh3 " << (dh1 <= dh3) << endl;
    cout << "dh1 == dh3 " << (dh1 == dh3) << endl;
    cout << "dh1 != dh3 " << (dh1 != dh3) << endl;
    cout << "dh1 >= dh3 " << (dh1 >= dh3) << endl;
    cout << "dh1 >  dh3 " << (dh1 > dh3) << endl;

    cout << endl;

    Sessao sessao("O Fantasma da Ópera", dh3);

    cout << sessao << endl;

    // Alocando as poltronas A1-14 e B1-14 para Pedro
    
    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, p1);
    }

    // Alocando as poltronas C1-14 e D1-14 para Ana

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, e1);
    }

    // Alocando as poltronas E1-14 e F1-14 para Beto

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, e2);
    }

    // Alocando as poltronas G1-14 e H1-14 para Pedro

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, p1);
    }

    // Alocando as poltronas I1-14 e J1-14 para Carlos

    for (int i = 0; i < 28; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, e3);
    }

    // Desocupando as 20 primeiras poltronas
    // A1-14 e B1-6

    cout << sessao << endl;

    for (int i = 1; i <= 14; i++) {
        string s = "A" + to_string(i);
        sessao.desocupa(s);
    }

    for (int i = 1; i <= 6; i++) {
        string s = "B" + to_string(i);
        sessao.desocupa(s);
    }

    cout << sessao << endl;

    // Ocupando as 90 restantes poltronas para Davi
    // A1-14, B1-6, K1-14, L1-14, M1-14, N1-14 e O1-14
    
    for (int i = 0; i < 90; i++) {
        string s = sessao.proximoLivre();
        sessao.ocupa(s, p2);
    }

    cout << sessao << endl;
}
