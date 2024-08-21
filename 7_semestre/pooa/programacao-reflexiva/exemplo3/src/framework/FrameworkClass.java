package framework;
import java.lang.reflect.Method;
public abstract class FrameworkClass {

   // Método abstrato que deve ser implementado pelo usuário
   protected abstract String getMethodName();

   // Método concreto que usa reflexão para invocar o método especificado na instância atual
   public void execute() {
       try {
          // Obtém o nome do método a ser invocado
           String methodName = getMethodName();
           // Obtém a classe atual (classe filha)
           Class<?> userClass = this.getClass();
           // Obtém o método da classe filha baseado no nome
           Method method = userClass.getMethod(methodName);
           // Invoca o método na instância atual
           method.invoke(this);


       } catch (Exception e) {
           System.out.println("Error executing method: " + e.getMessage());
       }
   }
}
