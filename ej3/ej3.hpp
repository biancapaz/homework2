#pragma once
#include <string>
using namespace std;

class Number {
    public:

        // Metodos virtuales puros
        virtual Number* sum(Number* number) = 0;
        /* Ejecuta la suma entre el objeto actual y el recibido por parámetro. Devuelve un nuevo objeto Number con el resultado de la operación.*/
        virtual Number* substraction(Number* number) = 0;
        /* Ejecuta la resta entre el objeto actual y el recibido por parámetro. Devuelve un nuevo objeto Number con el resultado de la operación.*/
        virtual Number* product(Number* number) = 0;
        /* Ejecuta el producto entre el objeto actual y el recibido por parámetro. Devuelve un nuevo objeto Number con el resultado de la operación.*/
        virtual Number* division(Number* number) = 0;
        /* Ejecuta la division entre el objeto actual y el recibido por parámetro. Devuelve un nuevo objeto Number con el resultado de la operación.*/
        virtual string toString() = 0;
        /* Devuelve una representación en formato string del valor numérico del objeto. */

};

class Integer : public Number {
    public:

        // Constructor
        Integer(int value);

        // Metodos
        Number* sum(Number* number) override;
        Number* substraction(Number* number) override;
        Number* product(Number* number) override;
        Number* division(Number* number) override;
        string toString() override;
    private:
        int value;
};

class Real : public Number {
    public:

        // Constructor
        Real(float value);

        // Metodos
        Number* sum(Number* number) override;
        Number* substraction(Number* number) override;
        Number* product(Number* number) override;
        Number* division(Number* number) override;
        string toString() override;
    
    private:

        // Atributos
        float value;
};

class Complex : public Number {
    public:

        // Constructor
        Complex(double real, double imaginary);

        // Metodos
        Number* sum(Number* number) override; 
        Number* substraction(Number* number) override;
        Number* product(Number* number) override;
        /* Calcula el producto entre dos números complejos usando la fórmula: (a + bi) * (c + di) = (ac - bd) + (ad + bc)i */
        Number* division(Number* number) override;
        /* Calcula la división entre dos números complejos usando la fórmula: (a + bi) / (c + di) = [(ac + bd) + (bc - ad)i] / (c² + d²)*/
        string toString() override;

    private:

        // Atributos
        double real;
        double imaginary;
};
