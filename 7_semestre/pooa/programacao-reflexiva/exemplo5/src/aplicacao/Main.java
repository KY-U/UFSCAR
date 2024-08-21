package aplicacao;

import java.sql.SQLException;
import framework.PersistenceFramework;

public class Main {
   public static void main(String[] args) {
 	
       PersistenceFramework framework = new PersistenceFramework();
      
       //corrigir path absoluto
       framework.setDBAbsolutePath("/home/caio/github/UFSCAR/7_semestre/pooa/programacao-reflexiva/novoBanco.db");
      
       Cliente cliente = new Cliente(7, "John Doe", "john.doe@example.com");
       try {

           framework.insert(cliente);

       } catch (SQLException | IllegalAccessException e) {
           e.printStackTrace();
       }
   }
}

