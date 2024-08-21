package aplicacao;

import java.sql.SQLException;
import framework.PersistenceFramework;

public class Main {
   public static void main(String[] args) {
 	
       PersistenceFramework framework = new PersistenceFramework();
      
       framework.setDBAbsolutePath("jdbc:sqlite:C:\\Users\\arcoc\\github\\UFSCAR\\7_semestre\\pooa\\programacao-reflexiva\\exemplo5intellij\\novoBanco.db");
      
       Cliente cliente = new Cliente(7, "John Doe", "john.doe@example.com");
       try {

           framework.insert(cliente);

       } catch (SQLException | IllegalAccessException e) {
           e.printStackTrace();
       }
   }
}

