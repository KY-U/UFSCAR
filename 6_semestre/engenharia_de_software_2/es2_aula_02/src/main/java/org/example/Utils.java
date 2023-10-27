package org.example;

import java.util.Random;

public class Utils {
    /**
     O metodo deve receber dois inteiros que representam o inicio e o fim de um intervalo e retornar um numero aleatorio que se encontra dentro do intervalo estabelecido, ou seja, [inicio, fim].
     Caso o inicio do intervalo ou o fim do intervalo sejam menor que zero, o metodo deve retornar -1. O metodo tambem retorna -1 quando o inteiro representando o inicio do intervalo for maior ou igual ao inteiro representando o fim do intervalo.
     **/
    public int gerarNumeroAleatorio(int inicio, int fim)
    {
        if (inicio < 0 || fim < 0) {
            return -1;
        }

        if (inicio >= fim) {
            return -1;
        }
        int diff = fim - inicio + 1;
        Random random = new Random();

        int tInt = random.nextInt(diff); //esse método retorna um número aleatorio
        //entre 0 e diff [ 0, diff [

        return inicio + tInt;
    }

    /**
     O metodo recebe como entrada um inteiro positivo no intervalo entre 1 e 20, uma cadeia de caracteres desse comprimento, e um caracter.
     Caso o comprimento seja invalido ou o tamanho da cadeia não seja igual ao tamanho passado como parametro, retornar uma mensagem de erro.
     Se todos os dados forem válidos, o metodo deve retornar a posição na cadeia em que o caracter é encontrado pela primeira vez ou uma mensagem indicando que o caracter não está presente na cadeia.
     **/
    public String acharCaracter(int tamanho, char cadeia[], char caracterProcurado)
    {
        if(tamanho < 1 || tamanho > 20)
            return "comprimento invalido";

        if(cadeia.length != tamanho)
            return "comprimento fornecido diferente do comprimento real";

        for (int i = 0; i < cadeia.length; i++) {
            if(caracterProcurado == cadeia[i])
                return String.valueOf(i);
        }

        return "caracter não encontrado";
    }
}


