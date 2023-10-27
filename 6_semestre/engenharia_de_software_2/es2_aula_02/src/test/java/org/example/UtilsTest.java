package org.example;

import static org.junit.jupiter.api.Assertions.assertEquals;
import static org.junit.jupiter.api.Assertions.assertTrue;

class UtilsTest {

    @org.junit.jupiter.api.BeforeEach
    void setUp() {
    }

    @org.junit.jupiter.api.AfterEach
    void tearDown() {
    }

    @org.junit.jupiter.api.Test
    void testeGerarNumeroAleatorio() {
        Utils utils = new Utils();
        int res = utils.gerarNumeroAleatorio(1, 10);
        assertTrue(res >= 1 && res <= 10);
    }

    @org.junit.jupiter.api.Test
    void testeGerarNumeroAleatorioIntInferiorNegativo() {
        Utils utils = new Utils();
        int res = utils.gerarNumeroAleatorio(-10, 10);
        assertEquals(-1, res);
    }

    @org.junit.jupiter.api.Test
    void testeGerarNumeroAleatorioIntSuperiorNegativo() {
        Utils utils = new Utils();
        int res = utils.gerarNumeroAleatorio(10, -10);
        assertEquals(-1, res);
    }
    @org.junit.jupiter.api.Test
    void testeAcharCaracter() {
        char array[] = {'b','a','n','a','n','a'};
        Utils utils = new Utils();
        var res = utils.acharCaracter(6, array, 'a');
        assertEquals("1", res);
    }
    @org.junit.jupiter.api.Test
    void acharCaracterNaoExistente() {
        char array[] = {'b','a','n','a','n','a'};
        Utils utils = new Utils();
        var res = utils.acharCaracter(6, array, 'z');
        assertEquals("caracter não encontrado", res);
    }

    @org.junit.jupiter.api.Test
    void testeTamanhoIntInferior(){
        char array[] = {};
        Utils utils = new Utils();
        var res = utils.acharCaracter(0, array, 'a');
        assertEquals("comprimento invalido", res);
    }
    @org.junit.jupiter.api.Test
    void testeTamanhoIntSuperior(){
        char array[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','t','u','v'};
        Utils utils = new Utils();
        var res = utils.acharCaracter(21, array, 'a');
        assertEquals("comprimento invalido", res);
    }

    @org.junit.jupiter.api.Test
    void testeTamanhoIncompativel(){
        char array[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','t','u'};
        Utils utils = new Utils();
        var res = utils.acharCaracter(15, array, 'a');
        assertEquals("comprimento fornecido diferente do comprimento real", res);
    }
}