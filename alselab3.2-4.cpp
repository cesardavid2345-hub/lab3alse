#include <iostream>
#include <stdexcept>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount() : balance(0) {}

    void deposit(double amount) {
        if (amount < 0) throw invalid_argument("Deposito invalido");
        balance += amount;
    }

    void withdraw(double amount) {
        if (amount > balance) throw runtime_error("Fondos insuficientes");
        balance -= amount;
    }

    double getBalance() {
        return balance;
    }
};

int main() {
    BankAccount acc;

    try {
        acc.deposit(100);
        acc.withdraw(30);

        cout << "Saldo: " << acc.getBalance() << endl;

    } catch (exception &e) {
        cout << "Error: " << e.what() << endl;
    }

    return 0;
}