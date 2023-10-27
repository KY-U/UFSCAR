package org.example;

import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.params.ParameterizedTest;
import org.junit.jupiter.params.provider.CsvSource;

import java.util.ArrayList;
import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.*;

class PessoaDAOTest {
    RHService rhServiceMock;
    @BeforeEach
    void setupMock() {
        //objeto que mocka o comportamento da interface/classe
        rhServiceMock = mock(RHService.class);
        var fakeList = new ArrayList<Pessoa>();
        fakeList.add(new Pessoa(1, 45, "Pucca"));
        fakeList.add(new Pessoa(2, 70, "Juninho"));
        fakeList.add(new Pessoa(3, 36, "Hailey"));

        //simula o comportamento do mock
        when(rhServiceMock.getAllPessoas())
                .thenReturn(fakeList);
    }

    @ParameterizedTest
    @CsvSource({
            "Pucca, true",
            "Juninho, true",
            "Hailey, true",
            "Narizinho, false"
    })
    void existePessoa(String nomeDaPessoaProcurada,
                      boolean saidaEsperada) {
        PessoaDAO pessoaDAO = new PessoaDAO(rhServiceMock);
        assertEquals(saidaEsperada,
                pessoaDAO.existePessoa(nomeDaPessoaProcurada));
    }

    @org.junit.jupiter.api.Test
    void naoExistePessoaProcurada() {
        PessoaDAO pessoaDAO = new PessoaDAO(rhServiceMock);
        assertFalse(pessoaDAO.existePessoa( "Narizinho"));
    }
}