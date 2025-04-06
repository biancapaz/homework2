#include "ej3.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

/* Implementacion de Integer */

/* Contenedor */
Integer::Integer(int value) : value(value) {};

/* Metodos */
Number* Integer::sum(Number* number) {
    Integer* otherInteger = dynamic_cast<Integer*>(number);

    int newValue = this->value + otherInteger->value;
    return new Integer(newValue);
};

Number* Integer::substraction(Number* number) {
    Integer* otherInteger = dynamic_cast<Integer*>(number);

    int newValue = this->value - otherInteger->value;
    return new Integer(newValue);
};

Number* Integer::product(Number* number) {
    Integer* otherInteger = dynamic_cast<Integer*>(number);

    int newValue = this->value * otherInteger->value;
    return new Integer(newValue);
};

Number* Integer::division(Number* number) {
    Integer* otherInteger = dynamic_cast<Integer*>(number);
    if (otherInteger->value == 0) {
        throw invalid_argument("No se puede dividir por cero.");
    }
    int newValue = this->value / otherInteger->value; // El resultado descarta la parte decimal ya que el resultado debe mantenerse como entero.
    return new Integer(newValue);
};

string Integer::toString(){
    return to_string(value);
};


/* Implementacion de Real */

/* Contenedor */
Real::Real(float value) : value(value) {};

/* Metodos */
Number* Real::sum(Number* number) {
    Real* otherReal = dynamic_cast<Real*>(number);

    float newValue = this->value + otherReal->value;
    return new Real(newValue);
};

Number* Real::substraction(Number* number) {
    Real* otherReal = dynamic_cast<Real*>(number);

    float newValue = this->value - otherReal->value;
    return new Real(newValue);
};

Number* Real::product(Number* number) {
    Real* otherReal = dynamic_cast<Real*>(number);

    float newValue = this->value * otherReal->value;
    return new Real(newValue);
};

Number* Real::division(Number* number) {
    Real* otherReal = dynamic_cast<Real*>(number);
    
    if (otherReal->value == 0) { // Se que comparar directamente un float/double con 0 puede fallar por errores de redondeo.
        throw invalid_argument("No se puede dividir por cero.");
    }

    float newValue = this->value / otherReal->value;
    return new Real(newValue);
};

string Real::toString() {
    stringstream roundedValue;
    roundedValue << fixed << setprecision(2) << value;
    return roundedValue.str();
};


/* Implementacion de Complex */

/* Contenedor */
Complex::Complex(double real, double imaginary) : real(real), imaginary(imaginary) {};

/* Metodos */
Number* Complex::sum(Number* number) {
    Complex* otherComplex = dynamic_cast<Complex*>(number);

    double newReal = this->real + otherComplex->real;
    double newImaginary = this->imaginary + otherComplex->imaginary;
    return new Complex(newReal, newImaginary);
};

Number* Complex::substraction(Number* number) {
    Complex* otherComplex = dynamic_cast<Complex*>(number);

    double newReal = this->real - otherComplex->real;
    double newImaginary = this->imaginary - otherComplex->imaginary;
    return new Complex(newReal, newImaginary);
};

Number* Complex::product(Number* number) {
    Complex* otherComplex = dynamic_cast<Complex*>(number);

    double newReal = (this->real * otherComplex->real) + (this->imaginary * otherComplex->imaginary);
    double newImaginary = (this->real * otherComplex->imaginary) + (this->imaginary * otherComplex->real);
    return new Complex(newReal, newImaginary);
};

Number* Complex::division(Number* number) {
    Complex* otherComplex = dynamic_cast<Complex*>(number);

    double divisor = (otherComplex->imaginary*otherComplex->imaginary + otherComplex->imaginary*otherComplex->imaginary);
    if (divisor == 0) { // Se que comparar directamente un float/double con 0 puede fallar por errores de redondeo.
        throw invalid_argument("No se puede dividir por cero.");
    }

    double newReal = ((this->real * otherComplex->real) + (this->imaginary * otherComplex->imaginary))/divisor;
    double newImaginary = (-(this->real * otherComplex->imaginary) + (this->imaginary * otherComplex->real))/divisor;
    return new Complex(newReal, newImaginary);
};

string Complex::toString() {
    stringstream roundedReal;
    stringstream roundedImaginary;
    roundedReal << fixed << setprecision(2) << real;
    roundedImaginary << fixed << setprecision(2) << imaginary;
    if (imaginary < 0) {
        return roundedReal.str() + roundedImaginary.str() + 'i';
    }
    return roundedReal.str() + '+' + roundedImaginary.str() + 'i';
};