package cx_branca_mut_01;

import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;

class OriginalTest {4
    @Test
    void verificaMutante1(){
        // Mutante1 altera se for diferente,
        // então basta o maior não ser o último elemento
        Original original = new Original();
        Mutante1 mutante = new Mutante1();
        int[] vetor = {3, 2, 1};
        int resOriginal = original.getMaior(vetor);
        int resMutante = mutante.getMaior(vetor);
        assertEquals(3, resOriginal);
        assertEquals(3, resMutante);
    }

    @Test
    void verificaMutante2(){
        // Mutante1 começa a iteração em i = 2
        // então basta o maior estar em 0 ou 1
        Original original = new Original();
        Mutante2 mutante = new Mutante2();
        int[] vetor = {2, 5, 1, 3, 4};
        int resOriginal = original.getMaior(vetor);
        int resMutante = mutante.getMaior(vetor);
        assertEquals(5, resOriginal);
        assertEquals(5, resMutante);
    }

    @Test
    void verificaMutante3(){
        // Mutante3 começa a iteração em i = 0
        // mas isso significa que ele só verifica novamente
        // o primeiro elemento que já iniciava como o maior
        // na atribuição inicial, logo não há interferência
        // no resultado, portanto, o mutante é equivalente.
        Original original = new Original();
        Mutante3 mutante = new Mutante3();
        int[] vetor = {4, 2, 1, 3};
        int resOriginal = original.getMaior(vetor);
        int resMutante = mutante.getMaior(vetor);
        assertEquals(4, resOriginal);
        assertEquals(4, resMutante);
        // O teste passou, pois são equivalentes.
    }
}