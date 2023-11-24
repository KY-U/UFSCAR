package cx_preta_pce_avl_08;

import org.junit.jupiter.api.Test;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import java.util.Arrays;
import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class VerificadorDeSenhasTest {
    @ParameterizedTest
    @CsvSource({
            "BomDi",
            "Olalalala",
            "ben10ben10",
            "milcaracter"
    })
    @Test
    void testSenhaValida(String mySenhaValida) {
        var senhasInvalidas = Arrays.asList("senha", "admin");
        Dicionario dicMock = mock(Dicionario.class);
        when(dicMock.getListaDeSenhasInvalidas())
                .thenReturn(senhasInvalidas);
        var ver = new VerificadorDeSenhas(dicMock);
        assertTrue(ver.validarNovaSenha(mySenhaValida));
    }
    @ParameterizedTest
    @CsvSource({
            "1234",
            "12345678912345",
            "#omDia",
            "admin"
    })
    @Test
    void testSenhaInvalida(String mySenhaInvalida) {
        var senhasInvalidas = Arrays.asList("senha", "admin");
        Dicionario dicMock = mock(Dicionario.class);
        when(dicMock.getListaDeSenhasInvalidas())
                .thenReturn(senhasInvalidas);
        var ver = new VerificadorDeSenhas(dicMock);
        assertFalse(ver.validarNovaSenha(mySenhaInvalida));
    }
}