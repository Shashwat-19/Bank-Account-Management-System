#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolderName;
    string password;
    double balance;
    vector<string> transactionHistory;

public:
    BankAccount() : accountNumber(""), accountHolderName(""), password(""), balance(0.0) {}

    BankAccount(const string& accNumber, const string& accHolderName, const string& accPassword)
        : accountNumber(accNumber), accountHolderName(accHolderName), password(accPassword), balance(0.0) {}

    bool authenticate(const string& enteredPassword) const {
        return password == enteredPassword;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            transactionHistory.push_back("Deposited $" + to_string(amount));
            cout << "Deposited $" << amount << " into account " << accountNumber << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            transactionHistory.push_back("Withdrew $" + to_string(amount));
            cout << "Withdrawn $" << amount << " from account " << accountNumber << endl;
        } else {
            cout << "Insufficient balance or invalid withdrawal amount." << endl;
        }
    }

    void checkBalance() const {
        cout << "Account " << accountNumber << " has a balance of $" << balance << endl;
    }

    void displayTransactionHistory() const {
        cout << "Transaction History for Account " << accountNumber << ":" << endl;
        if (transactionHistory.empty()) {
            cout << "No transactions available." << endl;
        } else {
            for (size_t i = 0; i < transactionHistory.size(); ++i) {
                cout << "- " << transactionHistory[i] << endl;
            }
        }
    }

    string getAccountNumber() const { return accountNumber; }
};

class Bank {
private:
    map<string, BankAccount> accounts;

    BankAccount* findAccount(const string& accountNumber) {
        map<string, BankAccount>::iterator it = accounts.find(accountNumber);
        if (it != accounts.end()) {
            return &(it->second);
        }
        return NULL;
    }

public:
    void createAccount(const string& accountNumber, const string& accountHolderName, const string& password) {
        if (accounts.find(accountNumber) != accounts.end()) {
            cout << "Account number already exists. Please use a unique account number." << endl;
        } else {
            accounts[accountNumber] = BankAccount(accountNumber, accountHolderName, password);
            cout << "Account created successfully." << endl;
        }
    }

    void deposit(const string& accountNumber, double amount) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->deposit(amount);
        } else {
            cout << "Account number not found." << endl;
        }
    }

    void withdraw(const string& accountNumber, double amount) {
        BankAccount* account = findAccount(accountNumber);
        if (account) {
            account->withdraw(amount);
        } else {
            cout << "Account number not found." << endl;
        }
    }

    void checkBalance(const string& accountNumber, const string& password) {
        BankAccount* account = findAccount(accountNumber);
        if (account && account->authenticate(password)) {
            account->checkBalance();
        } else {
            cout << "Account not found or authentication failed." << endl;
        }
    }

    void displayTransactionHistory(const string& accountNumber, const string& password) {
        BankAccount* account = findAccount(accountNumber);
        if (account && account->authenticate(password)) {
            account->displayTransactionHistory();
        } else {
            cout << "Account not found or authentication failed." << endl;
        }
    }
};

int main() {
    Bank bank;

    while (true) {
        cout << "\nBank Management System" << endl;
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. Check Balance\n5. Display Transaction History\n6. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        string accountNumber, accountHolderName, password;
        double amount;

        switch (choice) {
            case 1:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter account holder name: ";
                cin.ignore();
                getline(cin, accountHolderName);
                cout << "Set a password: ";
                cin >> password;
                bank.createAccount(accountNumber, accountHolderName, password);
                break;

            case 2:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter deposit amount: $";
                cin >> amount;
                bank.deposit(accountNumber, amount);
                break;

            case 3:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter withdrawal amount: $";
                cin >> amount;
                bank.withdraw(accountNumber, amount);
                break;

            case 4:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter password: ";
                cin >> password;
                bank.checkBalance(accountNumber, password);
                break;

            case 5:
                cout << "Enter account number: ";
                cin >> accountNumber;
                cout << "Enter password: ";
                cin >> password;
                bank.displayTransactionHistory(accountNumber, password);
                break;

            case 6:
                cout << "Exiting Program... Goodbye!" << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}
