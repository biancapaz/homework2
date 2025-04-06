#include "ej1.hpp"
#include <iostream>
using namespace std;

int main() {
    Time* t = initializeMenu();
    if (t == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }
    generalMenu(t);
    delete t;
    
    return 0;
}