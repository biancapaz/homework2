#include "ej4.hpp"
#include <iostream>
using namespace std;

/* Implementacion de BankAccount*/

/* Contenedor */
BankAccount::BankAccount(double balance, string accountHolder) : balance(balance), accountHolder(accountHolder) {};

/* Metodos */
void BankAccount::deposit(double amount) {
    this->balance += amount;
    cout << "Se deposito un total de $" << amount << " en la cuenta." << endl;
};


/* Implementacion de SavingsAccount*/

/* Contenedor */
SavingsAccount::SavingsAccount(double balance, string accountHolder) : BankAccount(balance, accountHolder), timesShowed(0) {};

/* Metodos */
void SavingsAccount::withdrawal(double amount) {
    if (amount <= balance) {
        balance -= amount;
        cout << "Se retiro un total de $" << amount << " de SavingsAccount." << endl;
    }
    else {
        cout << "Fondos insufiecinetes en Savings Account. No se pudo efectuar el retiro del dinero." << endl;
    }
}; 

void SavingsAccount::showInfo() {
    if (timesShowed == 2) {
        cout << "Se mostro la informacion por tercera vez. Se descontaron $" << fee << " de SavingsAccount." << endl;
        balance -= 20;
        timesShowed = 0;
    }
    cout << "Savings Account - Account Holder: " << accountHolder << " - Balance: $" << balance << endl;
    ++timesShowed;
}


/* Implementacion de CheckingAccount*/

/* Contenedor */
CheckingAccount::CheckingAccount(double balance, string accountHolder, shared_ptr<SavingsAccount> linkedSavings) : BankAccount(balance, accountHolder), linkedSavings(linkedSavings) {};

/* Metodos */
void CheckingAccount::withdrawal(double amount) {
    if (amount <= balance) {
        balance -= amount;
        cout << "Se retiro un total de $" << amount << " de CheckingAccount." << endl;
    }
    else {
        cout << "Fondos insuficientes en CheckingAccount." << endl;
        cout << "Evaluando disponibilidad de fondos en SavingsAccount..." << endl;
        if (amount <= linkedSavings->balance) {
            linkedSavings->balance -= amount;
            cout << "Se retiro un total de $" << amount << " de SavingsAccount." << endl;
        }
        else {
            cout << "Fondos insufiecinetes en Checking Account y Savings Account. No se pudo efectuar el retiro del dinero." << endl;
        }
    }
}; 

void CheckingAccount::showInfo() {
    cout << "Checking Account - Account Holder: " << accountHolder << " - Balance: $" << balance << endl;
}