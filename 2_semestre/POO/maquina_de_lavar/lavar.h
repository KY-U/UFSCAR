#ifndef LAVAR_H
#define LAVAR_H

//#include <string>

class MaquinaDeLavar{
    private:

        string modelo, etapa;
        double volume;              //em m^3
        double massa;               //em kgS
        bool estado;
        void Alarme();
        void setEtapa(string);

    public:

        MaquinaDeLavar();
        MaquinaDeLavar(string,double,double);
        void IniciarCiclo();

        //metodos get
        string getModelo() const;
        string getEtapa() const;
        double getVolume() const;
        double getMassa() const;
        bool getEstado() const;

        //metodos set

        void setEstado(bool);
        void setModelo(string);
        void setVolume(double);
        void setMassa(double);
        void Lavar();
        void Molho();
        void Centrifugar();

};

#endif