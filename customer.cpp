#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Transaction Class
class Transaction {
public:
    string type;   // Deposit, Withdraw, Transfer
    double amount;
    string details;

    Transaction(string t, double a, string d) {
        type = t;
        amount = a;
        details = d;
    }

    void displayTransaction() {
        cout << "Type: " << type << ", Amount: " << amount << ", Details: " << details << endl;
    }
};

// Account Class
class Account {
private:
    int accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(int accNo, double bal = 0.0) {
        accountNumber = accNo;
        balance = bal;
    }

    int getAccountNumber() { return accountNumber; }
    double getBalance() { return balance; }

    void deposit(double amount) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount, "Money deposited"));
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
        } else {
            balance -= amount;
            transactions.push_back(Transaction("Withdraw", amount, "Money withdrawn"));
        }
    }

    void transfer(Account &toAccount, double amount) {
        if (amount > balance) {
            cout << "Insufficient balance for transfer!" << endl;
        } else {
            balance -= amount;
            toAccount.balance += amount;
            transactions.push_back(Transaction("Transfer", amount, "Transferred to Acc " + to_string(toAccount.getAccountNumber())));
            toAccount.transactions.push_back(Transaction("Transfer", amount, "Received from Acc " + to_string(accountNumber)));
        }
    }

    void showTransactions() {
        cout << "Transaction History for Account " << accountNumber << ":\n";
        for (auto &t : transactions) {
            t.displayTransaction();
        }
    }

    void displayAccountInfo() {
        cout << "Account Number: " << accountNumber << ", Balance: " << balance << endl;
    }
};

// Customer Class
class Customer {
private:
    string name;
    int customerId;
    vector<Account> accounts;

public:
    Customer(string n, int id) {
        name = n;
        customerId = id;
    }

    void createAccount(int accNo, double initialBalance = 0.0) {
        accounts.push_back(Account(accNo, initialBalance));
        cout << "Account created successfully for " << name << " with Account No: " << accNo << endl;
    }

    Account* getAccount(int accNo) {
        for (auto &acc : accounts) {
            if (acc.getAccountNumber() == accNo) {
                return &acc;
            }
        }
        cout << "Account not found!" << endl;
        return nullptr;
    }

    void displayCustomerInfo() {
        cout << "Customer ID: " << customerId << ", Name: " << name << endl;
        for (auto &acc : accounts) {
            acc.displayAccountInfo();
        }
    }
};

// Main function
int main() {
    // Create Customers
    Customer c1("Vishal", 101);
    Customer c2("Rohan", 102);

    // Create Accounts
    c1.createAccount(1001, 5000);
    c2.createAccount(2001, 3000);

    // Deposit
    Account* acc1 = c1.getAccount(1001);
    if (acc1) acc1->deposit(2000);

    // Withdraw
    if (acc1) acc1->withdraw(1000);

    // Transfer money
    Account* acc2 = c2.getAccount(2001);
    if (acc1 && acc2) acc1->transfer(*acc2, 1500);

    // Display info
    c1.displayCustomerInfo();
    c2.displayCustomerInfo();

    // Show Transactions
    if (acc1) acc1->showTransactions();
    if (acc2) acc2->showTransactions();

    return 0;
}
