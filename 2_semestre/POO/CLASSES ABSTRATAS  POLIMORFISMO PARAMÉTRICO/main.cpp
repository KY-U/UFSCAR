#include "Categoria.h"
#include "Escultura.h"
#include "Museu.h"
#include "ObraDeArte.h"
#include "Pintura.h"
#include <iostream>

using namespace std;
using namespace catalogo;
    
void imprime(Museu &museu) {

    cout << "================== IMPRIMINDO AS OBRAS ================== " << endl;

    cout << "Qtde Obras: " << museu.qtdeObras() << endl;
    cout << endl;
    museu.imprime(TODOS);

    cout << "================== IMPRIMINDO AS PINTURAS =============== " << endl;

    cout << "Qtde Pinturas: " << museu.qtdePinturas() << endl;
    cout << endl;
    museu.imprime(PINTURA);

    cout << "================== IMPRIMINDO AS ESCULTURAS ============= " << endl;

    cout << "Qtde Esculturas: " << museu.qtdeEsculturas() << endl;
    cout << endl;
    museu.imprime(ESCULTURA);
}

int main() {

    ObraDeArte *o1 = new Pintura("Mona Lisa", "Leonardo da Vinci", "Madeira", 1503, "Óleo");
    ObraDeArte *o2 = new Escultura("David", "Michelangelo", "Mármore", 1501, 1.99);
    Museu museu("Louvre");

    cout << boolalpha;

    cout << "================== TESTANDO ADICIONA OBRA =============== " << endl;

    bool res = museu.adicionaObra(o1);
    cout << "Adiciona Obra (" << o1->getTitulo() << ") => " << res << endl;

    res = museu.adicionaObra(o2);
    cout << "Adiciona Obra (" << o2->getTitulo() << ") => " << res << endl;

    imprime(museu);

    cout << "================== TESTANDO REMOVE OBRA =============== " << endl;

    res = museu.removeObra("David");
    cout << "Remove Obra (David) => " << res << endl;

    imprime(museu);

    cout << endl;

    cout << "================== TESTANDO OBTEM OBRA =============== " << endl;
    
    ObraDeArte *o3 = museu.obtemObra("Mona Lisa");
    if (o3 != NULL) {
        o3->imprimeFicha();
    }

    return 0;
}