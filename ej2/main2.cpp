#include "ej2.hpp"
#include <iostream>
#include <memory>
#include <map>
using namespace std;

int main() {
    // Se crea un curso y un estudiante para probar los metodos
    cout << "Creamos curso: math" << endl;
    shared_ptr<Course> myCourse1 = make_shared<Course>("math");
    if (myCourse1 == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }

    shared_ptr<Course> myCourseCopy = make_shared<Course>("science", *myCourse1);

    map<string, shared_ptr<Course>> courses;
    courses["math"] = myCourse1;
    courses["science"] = myCourseCopy;

    cout << "Creamos estudiante: Bianca, 47222098" << endl;
    shared_ptr<Student> student1 = make_shared<Student>("Bianca", 47222098);
    if (student1 == nullptr) {
        cout << "No fue posible asignar memoria." << endl;
        return 1;
    }
    
    // Menu general
    int choice;
    do {
        cout << "MENU GENERAL" << endl;
        cout << "0. Testear Curso" << endl;
        cout << "1. Testear Estudiante" << endl;
        cout << "2. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();
        cout << "----------" << endl;

        switch (choice) {
            case 0: {
                courseMenu(myCourse1);
                break;
            }
            case 1: {
                studentMenu(student1, courses);
                break;
            }
            case 2: {
                break;
            }
            default: {
                cout << "Opcion incorrecta." << endl;
                break;
            }   
        }
        cout << endl;
    }
    while(choice != 2);
    
    return 0;
}