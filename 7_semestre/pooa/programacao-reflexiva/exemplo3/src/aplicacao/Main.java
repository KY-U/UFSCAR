package aplicacao;
import framework.FrameworkClass;

public class Main {
   public static void main(String[] args) {
       // Cria uma instância da classe do framework (classe concreta do usuário)
       FrameworkClass user = new UserClass();
       // Executa o método especificado
       user.execute();
   }
}
