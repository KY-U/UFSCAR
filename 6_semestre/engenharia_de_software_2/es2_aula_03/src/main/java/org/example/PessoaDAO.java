package org.example;

import java.util.ArrayList;

public class PessoaDAO {
    RHService rhservice;
    public PessoaDAO(RHService rhservice) {
        this.rhservice = rhservice;
    }
    public boolean existePessoa(String nome) {
        ArrayList<Pessoa> pessoas = rhservice.getAllPessoas();
        for(Pessoa p : pessoas) {
            if(p.nome().equalsIgnoreCase(nome))
                return true;
        }
        return false;
    }
}
