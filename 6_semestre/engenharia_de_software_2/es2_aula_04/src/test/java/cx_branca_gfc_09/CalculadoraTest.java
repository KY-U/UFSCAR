package cx_branca_gfc_09;

import static org.junit.jupiter.api.Assertions.*;

class CalculadoraTest {

    /*@Test*/
    //1, 2, 4, 5, 6, 7, 9
    @org.junit.jupiter.api.Test
    void testZero() throws Exception{
        var calc = new Calculadora();
        var res = calc.somatoriaLimitada(0, 500);
        assertEquals(0, res);
    }
    @org.junit.jupiter.api.Test
    void testException() {
        var calc = new Calculadora();
        assertThrows(Exception.class, () -> {
            var res = calc.somatoriaLimitada(10, 10);
        });
    }
    @org.junit.jupiter.api.Test
    void testNegativeNumber() {
        var calc = new Calculadora();
        assertThrows(Exception.class, () -> {
            var res = calc.somatoriaLimitada(-10, 5);
        });
    }
}