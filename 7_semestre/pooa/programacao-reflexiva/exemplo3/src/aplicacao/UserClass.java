package aplicacao;
import framework.FrameworkClass;

public class UserClass extends FrameworkClass {
   @Override
   protected String getMethodName() {
       return "customMethod"; // Nome do método que será chamado pelo framework
   }
   // Define o método que será invocado pelo framework
   public void customMethod() {
       System.out.println("Método da aplicação que está sendo executado - o framework conseguiu !!!");
   }
}
