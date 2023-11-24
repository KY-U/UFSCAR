package cx_preta_pce_avl_12;

import org.junit.jupiter.api.BeforeAll;
import org.junit.jupiter.api.Test;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

class MontanhaRussaControladorTest {

    MontanhaRussaControlador controlador;
    ClienteDao cliente;

    @BeforeAll
    void setup() {
        cliente = mock(ClienteDao.class);
        controlador = new MontanhaRussaControlador(cliente);
    }

    @Test
    void testCaracterInvalido() {
        assertThrows(Exception.class,()-> controlador.autorizar("huyga_neji", 18));
    }
    @Test
    void testUmaPalavra() {
        assertThrows(Exception.class,()-> controlador.autorizar("hyuga", 18));
    }
    @Test
    void testIdadeMenor() {
        assertThrows(Exception.class,()-> controlador.autorizar("hyuga neji", 1));
    }
    @Test
    void testIdadeMaior() {
        assertThrows(Exception.class,()-> controlador.autorizar("hyuga neji", 121));
    }
    @Test
    void testEhCliente() {
        when(cliente.ehCliente("Hatake Kakashi"))
                .thenReturn(false);
        assertThrows(Exception.class,()-> controlador.autorizar("Hatake Kakashi", 121));
    }
    @Test
    void testAutorizado() throws Exception {
        assertEquals("autorizado", controlador.autorizar("Hatake Kakashi", 120));
    }
    @Test
    void testAcompanhadoPais() throws Exception{
        assertEquals("acompanhado dos pais", controlador.autorizar("Hatake Kakashi", 1));
    }
    @Test
    void testAcompanhadoLegal() throws Exception{
        assertEquals("acompanhado dos responsável legal", controlador.autorizar("Hatake Kakashi", 120));
    }
}