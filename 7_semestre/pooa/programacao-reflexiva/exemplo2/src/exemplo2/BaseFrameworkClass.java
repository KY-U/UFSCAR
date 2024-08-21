package exemplo2;

import java.lang.reflect.Method;

public abstract class BaseFrameworkClass {

    // Método que será usado para inspecionar a classe filha
    public void inspectClass() {
        Class<?> clazz = this.getClass();

        System.out.println("Inspecting class: " + clazz.getName());

        // Listar todos os métodos da classe filha
        Method[] methods = clazz.getDeclaredMethods();
        for (Method method : methods) {
            System.out.println("Method: " + method.getName());
        }
    }
}

