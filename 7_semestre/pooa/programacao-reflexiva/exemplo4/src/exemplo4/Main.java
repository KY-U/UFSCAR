package exemplo4;

public class Main {

    public static void main(String[] args) {
        // Instanciar a classe do usuário
        UserClass userInstance = new UserClass();

        // Chamar o método do framework para rastrear e executar métodos anotados
        userInstance.trackAndExecuteMethods();
    }
}
