package ex04;

import org.junit.jupiter.api.AfterEach;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;

import java.util.ArrayList;

import static org.junit.jupiter.api.Assertions.*;
import static org.mockito.Mockito.mock;
import static org.mockito.Mockito.when;

class RelatorioDeFuncionariosTest {

    @Test
    void testSemFuncionarioNoBanco(){
        FuncionarioDAO funcDaoMock = mock(FuncionarioDAO.class);
        ReceitaFederal rfMock = mock(ReceitaFederal.class);
        RelatorioDeFuncionarios rel =
                new RelatorioDeFuncionarios(funcDaoMock);
        rel.setRf(rfMock);

        ArrayList<Funcionario> fakeList = new ArrayList<>();
        when(funcDaoMock.getFuncionariosBy("Dev"))
                .thenReturn(fakeList);
        int resposta = rel.getFuncComCPFBloqueado("Dev");
        assertEquals(0, resposta);
    }

    @Test
    void testDoisFuncionariosTecnicosSemCPFBloqueado() {
        FuncionarioDAO funcDaoMock = mock(FuncionarioDAO.class);
        ReceitaFederal rfMock = mock(ReceitaFederal.class);
        RelatorioDeFuncionarios rel =
                new RelatorioDeFuncionarios(funcDaoMock);
        rel.setRf(rfMock);

        ArrayList<Funcionario> fakeList = new ArrayList<>();
        fakeList.add(new Funcionario(
                11,
                "Jojo",
                "12345678910"
        ));
        fakeList.add(new Funcionario(
                40,
                "Linus",
                "10987654321"
        ));
        when(funcDaoMock.getFuncionariosBy("Tecnico"))
                .thenReturn(fakeList);
        when(rfMock.isCPFBloqueado("12345678910")).thenReturn(false);
        when(rfMock.isCPFBloqueado("10987654321")).thenReturn(false);

        int resposta = rel.getFuncComCPFBloqueado("Tecnico");
        assertEquals(2, resposta);
    }

    @Test
    void testFuncionarioAnalistaComCPFBloqueado() {
        FuncionarioDAO funcDaoMock = mock(FuncionarioDAO.class);
        ReceitaFederal rfMock = mock(ReceitaFederal.class);
        RelatorioDeFuncionarios rel =
                new RelatorioDeFuncionarios(funcDaoMock);
        rel.setRf(rfMock);

        ArrayList<Funcionario> fakeList = new ArrayList<>();
        fakeList.add(new Funcionario(
                30,
                "Giovanni",
                "12345678910"
        ));
        when(funcDaoMock.getFuncionariosBy("Analista"))
                .thenReturn(fakeList);
        when(rfMock.isCPFBloqueado("12345678910")).thenReturn(true);

        int resposta = rel.getFuncComCPFBloqueado("Analista");
        assertEquals(1, resposta);
    }

    @Test
    void testQuatroFuncionariosGerentesComCPFBloqueado() {
        FuncionarioDAO funcDaoMock = mock(FuncionarioDAO.class);
        ReceitaFederal rfMock = mock(ReceitaFederal.class);
        RelatorioDeFuncionarios rel =
                new RelatorioDeFuncionarios(funcDaoMock);
        rel.setRf(rfMock);

        ArrayList<Funcionario> fakeList = new ArrayList<>();
        fakeList.add(new Funcionario(
                29,
                "Gato de Botas",
                "12345678900"
        ));
        fakeList.add(new Funcionario(
                30,
                "Shrek",
                "11122233344"
        ));
        fakeList.add(new Funcionario(
                50,
                "Sportacus",
                "65432198723"
        ));
        fakeList.add(new Funcionario(
                70,
                "Lola",
                "09887665499"
        ));
        when(funcDaoMock.getFuncionariosBy("Gerente"))
                .thenReturn(fakeList);
        when(rfMock.isCPFBloqueado("12345678900")).thenReturn(false);
        when(rfMock.isCPFBloqueado("11122233344")).thenReturn(true);
        when(rfMock.isCPFBloqueado("65432198723")).thenReturn(false);
        when(rfMock.isCPFBloqueado("09887665499")).thenReturn(true);

        int resposta = rel.getFuncComCPFBloqueado("Gerente");
        assertEquals(4, resposta);
    }
}