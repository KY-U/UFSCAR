package cx_branca_gfc_12;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;
import org.mockito.internal.matchers.Null;

import static org.mockito.Mockito.*;
import static org.junit.jupiter.api.Assertions.*;

class VerificadorEleitoralTest {

    @Test
    void testeIdadeNegativa() {
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        assertThrows(Exception.class, () -> {
            var res = verificador.consultarSituacao(-1, "12345678910");
        });
    }
    @Test
    void testeIdadeExcedente() {
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        assertThrows(Exception.class, () -> {
            var res = verificador.consultarSituacao(201, "12345678910");
        });
    }
    @Test
    void testeCPFNull() {
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        assertThrows(Exception.class, () -> {
            var res = verificador.consultarSituacao(10, null);
        });
    }
    @Test
    void testeCPFTamanhoInvalido() {
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        assertThrows(Exception.class, () -> {
            var res = verificador.consultarSituacao(10, "123");
        });
    }
    @Test
    void testeMenorDe16() throws Exception {
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        String res = verificador.consultarSituacao(10, "12345678910");
        assertEquals("nao pode votar", res);
    }
    @Test
    void testeCPFInexistente() throws Exception{
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        when(cartorio_mock.verificar("12345678910")).thenReturn("nao existe");
        String res = verificador.consultarSituacao(18, "12345678910");
        assertEquals("faca um titulo", res);
    }

    @Test
    void testeCPFPendente() throws Exception{
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        when(cartorio_mock.verificar("12345678910")).thenReturn("pendencia");
        String res = verificador.consultarSituacao(18, "12345678910");
        assertEquals("regularize seu titulo", res);
    }

    @Test
    void testeCPFOkVotoObrigatorio() throws Exception{
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        when(cartorio_mock.verificar("12345678910")).thenReturn("OK");
        String res = verificador.consultarSituacao(18, "12345678910");
        assertEquals("voto obrigatorio", res);
    }

    //NAO TA FEITO, falta o if idade maior engual 16 menor 18
    @Test
    void testeCPFOkVotoFacultativoMenor70() throws Exception{
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        when(cartorio_mock.verificar("12345678910")).thenReturn("OK");
        String res = verificador.consultarSituacao(16, "12345678910");
        assertEquals("voto facultativo", res);
    }

    @Test
    void testeCPFOkVotoFacultativoMaior70() throws Exception{
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        when(cartorio_mock.verificar("12345678910")).thenReturn("OK");
        String res = verificador.consultarSituacao(71, "12345678910");
        assertEquals("voto facultativo", res);
    }

    @Test
    void testeErroDesconhecido() throws Exception{
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        when(cartorio_mock.verificar("12345678910")).thenReturn("banana");
        String res = verificador.consultarSituacao(16, "12345678910");
        assertEquals("erro desconhecido", res);
    }
}