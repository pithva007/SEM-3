#include <bits/stdc++.h>
#include <unistd.h>
#include <termios.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

// ----------------------
// Color Macros (ANSI)
// ----------------------
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[1;31m"
#define GREEN   "\033[1;32m"
#define YELLOW  "\033[1;33m"
#define BLUE    "\033[1;34m"
#define MAGENTA "\033[1;35m"
#define CYAN    "\033[1;36m"
#define WHITE   "\033[1;37m"

// ----------------------
// Hidden PIN input
// ----------------------
string getHiddenPIN() {
    struct termios oldt, newt;
    tcgetattr(STDIN_FILENO, &oldt);
    newt = oldt;
    newt.c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    string pinStr;
    char c;
    cout << CYAN << BOLD;
    cout.flush();

    while (true) {
        ssize_t n = read(STDIN_FILENO, &c, 1);
        if (n <= 0) break;
        if (c == '\n' || c == '\r') {
            cout << RESET << endl;
            break;
        }
        if (c == 127 || c == 8) {
            if (!pinStr.empty()) {
                pinStr.pop_back();
                cout << "\b \b";
                cout.flush();
            }
            continue;
        }
        if (isdigit(c)) {
            pinStr.push_back(c);
            cout << '*';
            cout.flush();
        }
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);
    return pinStr;
}

// ----------------------
// Base Class (Inheritance + Polymorphism)
// ----------------------
class BankAccount {
public:
    long long accountNumber;
    string pin;
    double balance;

    BankAccount(long long accNo, string p, double bal)
        : accountNumber(accNo), pin(p), balance(bal) {}

    virtual void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << GREEN << "✅ ₹" << amount << " deposited successfully!\n" << RESET;
        } else {
            cout << RED << "❌ Invalid amount.\n" << RESET;
        }
    }

    virtual void withdraw(double amount) {
        if (amount <= 0)
            cout << RED << "❌ Invalid withdrawal amount.\n" << RESET;
        else if (amount > balance)
            cout << RED << "❌ Insufficient balance!\n" << RESET;
        else {
            balance -= amount;
            cout << GREEN << "✅ ₹" << amount << " withdrawn successfully!\n" << RESET;
        }
    }

    virtual void displayAccountType() {
        cout << YELLOW << "🏦 Generic Bank Account\n" << RESET;
    }

    virtual ~BankAccount() {}
};

// ----------------------
// Derived Class (Inheritance + Polymorphism)
// ----------------------
class SavingsAccount : public BankAccount {
public:
    SavingsAccount(long long accNo, string p, double bal)
        : BankAccount(accNo, p, bal) {}

    void displayAccountType() override {
        cout << CYAN << "💰 Savings Account\n" << RESET;
    }

    void deposit(double amount) override {
        if (amount > 0) {
            double bonus = amount * 0.002;
            balance += amount + bonus;
            cout << GREEN << "✅ ₹" << amount << " deposited + ₹" << bonus << " bonus!\n" << RESET;
        } else {
            cout << RED << "❌ Invalid amount.\n" << RESET;
        }
    }
};

// ----------------------
// ATM Management Class
// ----------------------
class ATM {
private:
    vector<BankAccount*> accounts;
    BankAccount* currentUser = nullptr;
    const string filename = "accounts.txt";

    BankAccount* findAccount(long long accNo, string pin = "") {
        for (auto acc : accounts) {
            if (acc->accountNumber == accNo) {
                if (pin.empty() || acc->pin == pin) {
                    return acc;
                }
            }
        }
        return nullptr;
    }

public:
    ATM() { loadAccounts(); }
    ~ATM() {
        saveAccounts();
        for (auto acc : accounts) delete acc;
    }

    void loadAccounts() {
        ifstream fin(filename);
        if (!fin) return;
        accounts.clear();
        long long accNo;
        string pin;
        double bal;
        while (fin >> accNo >> pin >> bal) {
            accounts.push_back(new SavingsAccount(accNo, pin, bal));
        }
        fin.close();
    }

    void saveAccounts() {
        ofstream fout(filename);
        for (auto acc : accounts) {
            fout << acc->accountNumber << " " << acc->pin << " " << acc->balance << "\n";
        }
        fout.close();
    }

    long long getValidAccountNumber() {
        string accStr;
        while (true) {
            cout << "Enter 9-digit Account Number: ";
            cin >> accStr;

            if (accStr.length() != 9) {
                cout << "❌ Account number must be exactly 9 digits!\n";
                continue;
            }

            bool valid = true;
            for (char c : accStr) {
                if (!isdigit(c)) valid = false;
            }
            if (!valid) {
                cout << "❌ Account number must only contain digits!\n";
                continue;
            }
            return stoll(accStr);
        }
    }

    void createAccount(long long accNo, string pin, double initialBalance) {
        if (findAccount(accNo)) {
            cout << "❌ Account already exists!\n";
            return;
        }

        accounts.push_back(new SavingsAccount(accNo, pin, initialBalance));
        saveAccounts();
        cout << GREEN << "✅ Account created successfully!\n" << RESET;
    }

    bool login(long long accNo, string pin) {
        BankAccount* acc = findAccount(accNo, pin);
        if (acc) {
            currentUser = acc;
            cout << GREEN << "\n✅ Login successful! Welcome, Account " << accNo << "!\n" << RESET;
            acc->displayAccountType();  // Polymorphic call
            return true;
        }
        cout << RED << "❌ Invalid account number or PIN!\n" << RESET;
        return false;
    }

    void logout() {
        if (currentUser) {
            cout << YELLOW << "🔒 Logged out from Account " << currentUser->accountNumber << RESET << endl;
            currentUser = nullptr;
        }
    }

    void checkBalance() {
        if (currentUser)
            cout << "💰 Current Balance: ₹" << currentUser->balance << endl;
    }

    void deposit(double amount) {
        if (currentUser)
            currentUser->deposit(amount); // Polymorphism in action
    }

    void withdraw(double amount) {
        if (currentUser)
            currentUser->withdraw(amount); // Polymorphism in action
    }

    void resetPin(string oldPin, string newPin) {
        if (currentUser) {
            if (currentUser->pin == oldPin) {
                currentUser->pin = newPin;
                saveAccounts();
                cout << GREEN << "✅ PIN updated successfully!\n" << RESET;
            } else cout << RED << "❌ Old PIN incorrect!\n" << RESET;
        }
    }

    bool isLoggedIn() { return currentUser != nullptr; }
};

// ----------------------
// Main Program
// ----------------------
int main() {
    ATM atm;
    int choice;
    double amount;
    long long accNo;

    do {
        cout << BLUE << "\n==== ATM Management System ====\n" << RESET;
        cout << "1. Create New Account\n";
        cout << "2. Login to Account\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            long long accNo = atm.getValidAccountNumber();
            cout << "Set 4-digit PIN: ";
            string pin = getHiddenPIN();
            double bal;
            cout << "Enter Initial Balance: ";
            cin >> bal;
            atm.createAccount(accNo, pin, bal);
            break;
        }

        case 2: {
            cout << "Enter Account Number: ";
            cin >> accNo;
            cout << "Enter PIN: ";
            string pin = getHiddenPIN();
            if (atm.login(accNo, pin)) {
                int userChoice;
                do {
                    cout << CYAN << "\n==== Account Menu ====\n" << RESET;
                    cout << "1. Check Balance\n";
                    cout << "2. Deposit Money\n";
                    cout << "3. Withdraw Money\n";
                    cout << "4. Reset PIN\n";
                    cout << "5. Logout\n";
                    cout << "Enter choice: ";
                    cin >> userChoice;

                    switch (userChoice) {
                    case 1: atm.checkBalance(); break;
                    case 2:
                        cout << "Enter deposit amount: ";
                        cin >> amount;
                        atm.deposit(amount);
                        break;
                    case 3:
                        cout << "Enter withdraw amount: ";
                        cin >> amount;
                        atm.withdraw(amount);
                        break;
                    case 4: {
                        cout << "Enter old PIN: ";
                        string oldPin = getHiddenPIN();
                        cout << "Enter new PIN: ";
                        string newPin = getHiddenPIN();
                        atm.resetPin(oldPin, newPin);
                        break;
                    }
                    case 5: atm.logout(); break;
                    default: cout << RED << "❌ Invalid choice!\n" << RESET;
                    }
                } while (atm.isLoggedIn());
            }
            break;
        }

        case 3:
            cout << MAGENTA << "👋 Exiting... Thank you!\n" << RESET;
            break;

        default:
            cout << RED << "❌ Invalid choice!\n" << RESET;
        }
    } while (choice != 3);

    return 0;
}
