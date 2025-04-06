#include "ej3.hpp"
#include <iostream>

using namespace std;

int main() {
    // INTEGER //
    Number* i1 = new Integer(1);
    Number* i2 = new Integer(2);
    if (i1 == nullptr || i2 == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }

    Number* sum_i = i1->sum(i2);
    Number* subs_i = i1->substraction(i2);
    Number* product_i = i1->product(i2);
    Number* division_i;
    try {
        division_i = i1->division(i2);
    }
    catch(const invalid_argument& e) {
        cerr << e.what() << '\n';
    }
        
    if (sum_i == nullptr || subs_i == nullptr || product_i == nullptr || division_i == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }

    cout << "Integer Operations" << endl;
    cout << "Integer 1: " << i1->toString() << endl;
    cout << "Integer 2: " << i2->toString() << endl;
    cout << "Sum: " << sum_i->toString() << endl;
    cout << "Substraction: " << subs_i->toString() << endl;
    cout << "Product: " << product_i->toString() << endl;
    cout << "Division: " << division_i->toString() << endl;

    delete i1;
    delete i2;
    delete sum_i;
    delete subs_i;
    delete product_i;
    delete division_i;

    // REAL //
    Number* r1 = new Real(7.6);
    Number* r2 = new Real(7.6);
    if (r1 == nullptr || r2 == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }

    Number* sum_r = r1->sum(r2);
    Number* subs_r = r1->substraction(r2);
    Number* product_r = r1->product(r2);
    Number* division_r;
    try { 
        division_r = r1->division(r2);
    }
    catch(const invalid_argument& e) {
        cerr << e.what() << '\n';
    }

    if (sum_r == nullptr || subs_r == nullptr || product_r == nullptr || division_r == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }

    cout << "\nReal Operations" << endl;
    cout << "Real 1: " << r1->toString() << endl;
    cout << "Real 2: " << r2->toString() << endl;
    cout << "Sum: " << sum_r->toString() << endl;
    cout << "Substraction: " << subs_r->toString() << endl;
    cout << "Product: " << product_r->toString() << endl;
    cout << "Division: " << division_r->toString() << endl;

    delete r1;
    delete r2;
    delete sum_r;
    delete subs_r;
    delete product_r;
    delete division_r;

    // COMPLEX //
    Number* c1 = new Complex(2,10);
    Number* c2 = new Complex(5.5,1);
    if (c1 == nullptr || c2 == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }

    Number* sum_c = c1->sum(c2);
    Number* subs_c = c1->substraction(c2);
    Number* product_c = c1->product(c2);
    Number* division_c;
    try {
        division_c = c1->division(c2);
    }
    catch(const invalid_argument& e) {
        cerr << e.what() << '\n';
    }

    if (sum_c == nullptr || subs_c == nullptr || product_c == nullptr || division_c == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }

    cout << "\nComplex Operations" << endl;
    cout << "Complex 1: " << c1->toString() << endl;
    cout << "Complex 2: " << c2->toString() << endl;
    cout << "Sum: " << sum_c->toString() << endl;
    cout << "Substraction: " << subs_c->toString() << endl;
    cout << "Product: " << product_c->toString() << endl;
    cout << "Division: " << division_c->toString() << endl;

    delete c1;
    delete c2;
    delete sum_c;
    delete subs_c;
    delete product_c;
    delete division_c;
}