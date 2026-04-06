#include <iostream>
using namespace std;

class BankAccount {
private:
    int accountNumber;
    double balance;
    static double interestRate;   // shared by all accounts
    static int nextAccNumber;     // to generate account numbers

public:
    // Constructor
    BankAccount(double initialBalance) {
        accountNumber = ++nextAccNumber;
        balance = initialBalance;
    }

    // Deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Withdraw money
    void withdraw(double amount) {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient balance!\n";
    }

    // Show account details
    void displayAccount() const {
        cout << "Account No: " << accountNumber
             << " | Balance: " << balance
             << " | Interest Rate: " << interestRate << "%\n";
    }

    // Static function to update interest rate
    static void updateInterestRate(double newRate) {
        interestRate = newRate;
    }

    // Static function to display interest rate
    static void displayInterestRate() {
        cout << "Current Interest Rate: " << interestRate << "%\n";
    }
};

// Initialize static members
double BankAccount::interestRate = 5.0;
int BankAccount::nextAccNumber = 1000; // start account numbers from 1001

int main() {
    // Create accounts
    BankAccount acc1(5000);
    BankAccount acc2(8000);

    acc1.displayAccount();
    acc2.displayAccount();

    cout << "\nUpdating interest rate to 6.5%...\n";
    BankAccount::updateInterestRate(6.5);

    BankAccount::displayInterestRate();

    acc1.displayAccount();
    acc2.displayAccount();

    return 0;
}