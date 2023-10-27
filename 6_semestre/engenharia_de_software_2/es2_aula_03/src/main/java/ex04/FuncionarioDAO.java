package ex04;
import java.util.ArrayList;
public interface FuncionarioDAO {
    public ArrayList<Funcionario> getFuncionariosBy(String categoria);
}