//Injeção por método
//
//Adidicionei um objeto transaction como argumento dos métodos
public class Account {
    public void deposit(double amount, Transaction transaction) {
        transaction.deposit(amount);
    }

    public void withdraw(double amount, Transaction transaction) {
        transaction.withdraw(amount);
    }
}
//Injeção por construtor
public class Transaction {
    public void deposit(double amount) {
        // Lógica para depositar dinheiro na conta
    }

    public void withdraw(double amount) {
        // Lógica para sacar dinheiro da conta
    }
}

