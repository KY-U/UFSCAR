package exemplo4;

import java.lang.reflect.Method;

public abstract class BaseFrameworkClass {

    // Método template para rastrear e executar métodos anotados
    public void trackAndExecuteMethods() {

        Class<?> clazz = this.getClass();

        System.out.println("Tracking and executing methods in class: " + clazz.getName());

	     // Listar e executar métodos anotados
	    Method[] methods = clazz.getDeclaredMethods();
        for (Method method : methods) {
            if (method.isAnnotationPresent(TrackExecution.class)) {
                System.out.println("Tracking method: " + method.getName());
                try {
                    // Antes da execução
                    System.out.println("Starting execution of method: " + method.getName());
                  method.invoke(this);
                    // Depois da execução
                    System.out.println("Finished execution of method: " + method.getName());

                } catch (Exception e) {
                    System.out.println("Failed to execute method: " + method.getName());
                    e.printStackTrace();
                }
            }
        }
    }
}
