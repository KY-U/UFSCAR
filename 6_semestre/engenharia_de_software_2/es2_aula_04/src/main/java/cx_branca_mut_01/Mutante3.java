package cx_branca_mut_01;

public class Mutante3 {
    //método retorna o maior elemento do vetor
    public int getMaior(int vetor[]) {
        int maior = vetor[0];
        for (int i = 0; i < vetor.length; i++) {
            if (vetor[i] > maior)
                maior = vetor[i];
        }
        return maior;
    }
}