#pragma once
#include <string>
#include <memory>
using namespace std;

class BankAccount {
    public:

        // Constructor
        BankAccount(double balance, string accountHolder);        

        // Metodos
        virtual void deposit(double amount);
        /* Deposita dinero en la cuenta. */
        virtual void withdrawal(double amount) = 0;
        virtual void showInfo() = 0;
    
    protected:

        // Atributos
        double balance;
        string accountHolder;
        
};

class SavingsAccount : public BankAccount {
    public: 

        // Constructor
        SavingsAccount(double balance, string accountHolder);

        // Metodos
        void withdrawal(double amount) override; 
        /* Retira una cantidad determinada de dinero del balance si es que los fondos son suficientes. */
        void showInfo() override;
        /*  Muestra el balance, el tipo de cuenta y el nombre del titular. Si se muestra la informacion mas de 2 veces, se descuentan $20 del balance. */

        // Friend class para acceder a balance
        friend class CheckingAccount;

    private:

        // Atributos
        int timesShowed; // contador de veces que se mostro la infromacion
        const double fee = 20; // comision por mostrar la informacion
};

class CheckingAccount : public BankAccount {
    public: 

        // Constructor
        CheckingAccount(double balance, string accountHolder, shared_ptr<SavingsAccount> linkedSavings);

        // Metodos
        void withdrawal(double amount) override;
        /* Retira una cantidad determinada de dinero del balance. Si la cuenta no tiene fondos suficientes, intenta usar el saldo de linkedSavings que es la cuenta SavingsAccount asociada.*/ 
        void showInfo() override;
        /*  Muestra el balance, el tipo de cuenta y el nombre del titular. */
    
    private:

        // Atributos
        shared_ptr<SavingsAccount> linkedSavings; // cuenta SavingsAccount asociada
};