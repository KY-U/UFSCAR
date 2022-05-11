#ifndef RG_H
#define RG_H

using std::string;

class Pessoa{
  private:
    //dado que eh assumido como verdade, para comparar com os outros
    //int sexo; //0 Homem, 1 Mulher
    
    //dados presentes no RG
    string nomeRg;
    string paiRg;
    string maeRg;
    //string nascRg;
    string natRg;
    int dia;
    int mes;
    int ano;

  public:
    int sexo; //0 Homem, 1 Mulher
    //indicadores de erro
    bool nomeEr;
    bool paiEr;
    bool maeEr;
    bool dataEr;
    bool nascEr;
    bool natEr;
    //métodos
    Pessoa(string[], string[], string[], string[], string[], string[]);
    Pessoa();
    Pessoa(const Pessoa &);
    const Pessoa &operator=(const Pessoa &);
    void printFoto(string[], string[]);
    void printRg();
    bool dataVal(int, int, int);
    void nascVal(int, int, int);
};

void printTitulo();
void printInstrucoes();
void printJogarNov();
void atribuiStrings(string[], string[], string[], string[], string[], string[]);

#endif