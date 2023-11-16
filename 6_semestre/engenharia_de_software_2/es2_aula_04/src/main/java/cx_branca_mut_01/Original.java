package cx_branca_mut_01;

public class Original {
    //método retorna o maior elemento do vetor
    public int getMaior(int vetor[]) {
        int maior = vetor[0];
        for (int i = 1; i < vetor.length; i++) {
            if(vetor[i] > maior)
                maior = vetor[i];
        }
        return maior;
    }
}
