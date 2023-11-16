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
        when(cartorio_mock.verificar("12345678910")).thenReturn("nao existe")
        String res = verificador.consultarSituacao(10, "12345678910");
        assertEquals("faca um titulo", res);
    }

    void testeCPFInexistente() throws Exception{
        CartorioEleitoral cartorio_mock = mock(CartorioEleitoral.class);
        VerificadorEleitoral verificador = new VerificadorEleitoral(cartorio_mock);
        when(cartorio_mock.verificar("12345678910")).thenReturn("nao existe")
        String res = verificador.consultarSituacao(10, "12345678910");
        assertEquals("faca um titulo", res);
    }
}