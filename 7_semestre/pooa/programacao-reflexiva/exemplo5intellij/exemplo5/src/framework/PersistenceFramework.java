package framework;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.List;
import java.util.ArrayList;
import java.lang.reflect.Field;
public class PersistenceFramework {
	private Connection conn;
	
	public PersistenceFramework() {
			this.conn = null;
		}

	public void setDBAbsolutePath(String path){
		try {
			//private String dbPath;			
			conn = DriverManager.getConnection(path);
		}catch (SQLException e) {
            System.out.println("Connection failed.");
            e.printStackTrace();
        }
		
	}
	
	public void insert(Object o) throws SQLException, IllegalArgumentException, IllegalAccessException {
		Class<?> clazz = o.getClass();
		Entity entityAnotation = clazz.getAnnotation(Entity.class);
		
		if(entityAnotation.tableName() != null) {
			//coletando a tabela da query
			String table = entityAnotation.tableName();
			
			//coletando as colunas e valores da query
			Field[] fields = clazz.getDeclaredFields();
			List<String> validFields = new ArrayList<>();
			List<String> validValues = new ArrayList<>();
			for (Field field : fields) {
				if(field.isAnnotationPresent(Column.class)){
					validFields.add(field.getName());
					field.setAccessible(true);
					validValues.add((String) field.get(o));
				}
			}
			//criando a query sql:
			Statement stmt = conn.createStatement();
			//caso a tabela esteja vazia:
			/*
			 * String query = "CREATE TABLE IF NOT EXISTS" + table + "(";
			for(String field: validFields) {
				query = query + 
			}*/
			String query = "INSERT INTO" + table + "(";
			for (int i = 0; i < validValues.size(); i++) {
				if(i == 0) {
					query = query + validValues.get(i);
				}
				else {
					query = query + "," + validValues.get(i) ;
				}
			}
			query = query + ")";
			
			stmt.executeUpdate(query);
		}
		
		if (conn != null) {
            try {
                conn.close();
            } catch (SQLException e) {
                e.printStackTrace();
            }	
		}
	}
}
