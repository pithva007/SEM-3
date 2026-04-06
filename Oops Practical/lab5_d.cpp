#include <iostream>
using namespace std;

class bankacc {
private:
    string accountHolder;
    double balance;

public:
    bankacc(string name, double initialBalance) {
        accountHolder = name;
        balance = initialBalance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposited: $" << amount << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawn: $" << amount << endl;
        } else {
            cout << "Insufficient balance or invalid amount." << endl;
        }
    }

    void display() const {
        cout << "\n--- Account Details ---" << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << balance << endl;
    }
};

int main() {
    string name;
    double initialBalance, depositAmount, withdrawAmount;

    cout << "Enter account holder name: ";
    getline(cin, name);

    cout << "Enter initial balance: $";
    cin >> initialBalance;

    bankacc userAccount(name, initialBalance);

    cout << "\nEnter amount to deposit: $";
    cin >> depositAmount;
    userAccount.deposit(depositAmount);

    cout << "Enter amount to withdraw: $";
    cin >> withdrawAmount;
    userAccount.withdraw(withdrawAmount);

    userAccount.display();

    return 0;
}
