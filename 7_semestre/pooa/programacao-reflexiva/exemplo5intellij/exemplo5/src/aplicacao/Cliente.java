package aplicacao;

import framework.Column;
import framework.Entity;

@Entity(tableName = "Cliente")

public class Cliente {

   @Column(name = "id")
   private int id;

   @Column(name = "name")
   private String name;

   @Column(name = "email")
   private String email;

   // Construtor, getters e setters
   public Cliente(int id, String name, String email) {
	   this.id = id;
	   this.name = name;
	   this.email = email;
   }
   
// Getter para id
   public int getId() {
       return id;
   }

   // Setter para id
   public void setId(int id) {
       this.id = id;
   }

   // Getter para name
   public String getName() {
       return name;
   }

   // Setter para name
   public void setName(String name) {
       this.name = name;
   }

   // Getter para email
   public String getEmail() {
       return email;
   }

   // Setter para email
   public void setEmail(String email) {
       this.email = email;
   }
   
}
