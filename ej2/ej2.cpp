#include "ej2.hpp"
#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;

/* Implementacion de Course */

/* Contenedores */
Course::Course(string name) : name(name) {};
Course::Course(string name, const Course& otherCourse) : name(name), students(otherCourse.students) {}; // Se hace un shallow copy con un Copy Constructor

/* Metodos */
void Course::enrollStudent(shared_ptr<Student> student ) {
    if (hasStudent(student->getID())) { // Si el estudiante ya estaba en el curso
        cout << "El estudiante ya estaba inscripto en el curso." << endl;
        return;
    }

    if (isFull()) { // Si el curso esta completo
        cout << "El curso ya esta completo. No se pudo inscribir al estudiante." << endl;
        return;
    }

    students.push_back(student); // Se inscribe al estudiante
    cout << "El estudiante se inscribio exitosamente." << endl;
};

void Course::unenrollStudent(int studentID) {
    if (hasStudent(studentID)) { // Si el estudiante esta en el curso
        for (vector<shared_ptr<Student>>::iterator it = students.begin(); it != students.end(); ++it) { // Itera sobre el vetor de estudiantes
            
            if ((*it)->getID() == studentID) { // Si coincide con el legajo del estudiante a desinscribir
                students.erase(it);
                cout << "El estudiante fue desinscripto del curso." << endl;
                break;
            }
        }
    }
    else { // Si el estudiante no esta en el curso
        cout << "El estudiante no estaba inscripto en el curso." << endl;
    }
};

bool Course::hasStudent(int studentID) const {
    for (int i = 0; i < students.size(); i++) { // Recorre el vector de estudiantes
        
        if (students.at(i)->getID() == studentID) { // Si coincide el legajo
            return true;
        }
    }
    return false;
};

bool Course::isFull() const {
    return students.size() == maxCapacity;
};

void Course::showStudentsSortedByName() const {
    if (students.empty()) { // Si el curso esta vacio
        cout << "El curso esta vacio." << endl;
    }
    else {
        // Copia del vector de estudiantes para ordenarlos sin modificar al original
        vector<shared_ptr<Student>> sortedStudents = students;
        sort(sortedStudents.begin(), sortedStudents.end(), [](const shared_ptr<Student>& s1, const shared_ptr<Student>& s2) {
            return *s1 < *s2;
        });

        for (const auto& student : sortedStudents) { // Imprime los estudiantes del vector ordenado
            cout << *student;
        }
    }
};

string Course::getName() const {
    return name;
};

/* Implementacion de Student */

/* Contenedor */
Student::Student(string fullName, int ID) : fullName(fullName), ID(ID) {};

/* Metodos */
string Student::getName() const {
    return fullName;
};

int Student::getID() const {
    return ID;
};

float Student::getAverage() const {
    if (scores.empty()) return 0.0f;

    float sum = 0.0f;
    for (auto& pair : scores) { // Itera sobre (Course, score)
        sum += pair.second; // Suma los scores de cada curso
    }
    float average = sum/scores.size(); // Calcula el promedio

    return average;
};

void Student::insertScore(shared_ptr<Course> course, float score) {
    scores[course] = score;
    cout << "El curso y la nota se insertaron correctamente." << endl;
};



/* Implementacion de sobrecraga de operadores */

string toUpperCase(const string& name) {
    string uppered;
    for (char c : name) {
        uppered += toupper(c);
    }
    return uppered;
};

bool Student::operator==(const Student& other) const {
    return this->getID() == other.getID();
};

bool Student::operator<(const Student& other) const {
    return toUpperCase(this->getName()) < toUpperCase(other.getName()); // Se usa toUpperCase para que la comparación de los nombres no dependa de mayúsculas o minúsculas.
};

ostream& operator<<(ostream& os, const Student& other) {
    os << "- " << other.getName() << endl;
    return os;
};


/* Implementacion de menues */
void courseMenu(shared_ptr<Course> course) {
    int choice;

    do {
        cout << "MENU CURSO" << endl;
        cout << "0. Inscribir estudiante" << endl;
        cout << "1. Desinscribir estudiante" << endl;
        cout << "2. Verificar inscripcion por legajo" << endl;
        cout << "3. Verificar si el curso esta completo" << endl;
        cout << "4. Imprimir estudiantes ordenados por nombre" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();
        cout << "----------" << endl;

        switch (choice) {
            case 0: {
                string name;
                int ID;
                cout << "Ingrese el nombre completo del estudiante: ";
                getline(cin, name);
                cout << "Ingrese el numero de legajo: ";
                cin >> ID;

                shared_ptr<Student> newStudent = make_shared<Student>(name, ID);
                if (newStudent == nullptr) {
                    cout << "No fue posible asignar memoria." << endl;
                    return;
                }

                course->enrollStudent(newStudent);
                break;
            }
            case 1: {
                int ID;
                cout << "Ingrese el numero de legajo del estudiante a desinscribir: ";
                cin >> ID;

                course->unenrollStudent(ID);
                break;
            }
            case 2: {
                int ID;
                cout << "Ingrese el numero de legajo del estudiante a verificar: ";
                cin >> ID;

                if (course->hasStudent(ID)) {
                    cout << "El estudiante esta inscripto en el curso" << endl;
                }
                else {
                    cout << "El estudiante no esta inscripto en el curso" << endl;
                }

                break;
            }
            case 3: {
                if (course->isFull()) {
                    cout << "El curso esta completo." << endl;
                }
                else {
                    cout << "El curso no esta completo." << endl;
                }
                break;
            }
            case 4: {
                cout << "Lista de estudiantes de " << course->getName() << ':' << endl;
                course->showStudentsSortedByName();
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "Opcion ingresada incorrecta." << endl;
                break;
            }   
        }
        cout << endl;
    }
    while(choice != 5);
};

void studentMenu(shared_ptr<Student> student, map<string, shared_ptr<Course>> courses) {
    int choice;

    do {
        cout << "MENU ESTUDIANTE" << endl;
        cout << "0. Mostrar nombre" << endl;
        cout << "1. Mostrar legajo" << endl;
        cout << "2. Mostrar promedio" << endl;
        cout << "3. Ingresar curso y nota" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();
        cout << "----------" << endl;

        switch (choice) {
            case 0: {
                cout << "Nombre: " << student->getName();
                break;
            }
            case 1: {
                cout << "Legajo: " << student->getID();
                break;
            }
            case 2: {
                cout << "Promedio: " << student->getAverage();
                break;
            }
            case 3: {
                string course;
                float score;
                cout << "Ingrese el nombre del curso: ";
                getline(cin, course);
                cout << "Ingrese la nota: ";
                cin >> score;

                if (courses.count(course)) {
                    student->insertScore(courses[course], score);
                }
                else {
                    cout << "El curso no existe." << endl;
                }
                
                break;
            }
            case 4: {
                break;
            }
            default: {
                cout << "Opcion ingresada incorrecta." << endl;
                break;
            }   
        }
        cout << endl;
    }
    while(choice != 4);
};