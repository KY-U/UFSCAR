public class Account {
    public void deposit(double amount) {
        Transaction transaction = new Transaction();
        transaction.deposit(amount);
    }

    public void withdraw(double amount) {
        Transaction transaction = new Transaction();
        transaction.withdraw(amount);
    }
}

public class Transaction {
    public void deposit(double amount) {
        // Lógica para depositar dinheiro na conta
    }

    public void withdraw(double amount) {
        // Lógica para sacar dinheiro da conta
    }
}
