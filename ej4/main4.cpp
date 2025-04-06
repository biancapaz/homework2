#include "ej4.hpp"
#include <iostream>
using namespace std;

int main() {
    // Se crea una cuenta de ahorros y una cuenta corriente
    shared_ptr<SavingsAccount> mySA = make_shared<SavingsAccount>(50,"Bianca");
    if (mySA == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }
    CheckingAccount myCA(100, "Bianca", mySA);
    
    // Test showInfo de ambas cuentas:
    cout << "Mostrando la informacion de ambas cuentas:" << endl;
    mySA->showInfo();
    myCA.showInfo();
    cout << endl;

    // Test deposit en SavingsAccount:
    cout << "Depositando en SavingsAccount:" << endl;
    mySA->deposit(20);
    mySA->showInfo();
    cout << endl;

    // Test withdrawal de SavingsAccount:
    cout << "Retirando de SavingsAccount:" << endl;
    mySA->withdrawal(20); // quedan $20
    cout << endl;

    // Test showInfo de SavingsAccount descontando el fee:
    cout << "Mostrando la informacion de SavingsAccount:" << endl;
    mySA->showInfo(); // se muestra la informacion por 3ra vez y se descuentan $20 --> la cuenta queda en $30
    cout << endl;

    // Test withdrawal de CheckingAccount:
    cout << "Retirando de CheckingAccount:" << endl;
    myCA.withdrawal(95); // quedan $5
    cout << endl;

    // Test withdrawal de SavingsAccount por fondos insuficientes en CheckingAccount:
    cout << "Retirando de CheckingAccount:" << endl;
    myCA.withdrawal(15); // se retira de SavingsAccount
    cout << endl;

    // Test showInfo de ambas cuentas:
    cout << "Mostrando la informacion de ambas cuentas:" << endl;
    mySA->showInfo();
    myCA.showInfo();
    cout << endl;

    return 0;    
}