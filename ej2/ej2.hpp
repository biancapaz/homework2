#pragma once
#include <memory>
#include <vector>
#include <map>
#include <string>
using namespace std;

class Student;
class Course;
void courseMenu(shared_ptr<Course> course);
/* Menu para ejecutar acciones de un objeto Course. */
void studentMenu(shared_ptr<Student> student, map<string, shared_ptr<Course>> courses);
/* Menu para ejecutar acciones de un objeto Student. */
string toUpperCase(const string& name);
/* Recibe un string y devuelve una nueva versión del mismo con todos sus caracteres convertidos a mayúsculas */

class Course {
    public:
        
        // Constructores
        Course(string name);
        Course(string name, const Course& otherCourse); 
        /* Constructor que permite hacer un shallow copy de un objeto Course. */ 
        
        // Metodos
        void enrollStudent(shared_ptr<Student> student);
        /* Inscribe un estudiante a un curso. */
        void unenrollStudent(int studentID);
        /* Desinscribe un estudiante de un curso. */
        bool hasStudent(int studentID) const;
        /* Verifica si un estudiante esta inscripto en un curso a prtir de su numero de legajo. Devuelve true si esta en el curso, de lo contrario devuelve false. */
        bool isFull() const;
        /* Verifica si el curso esta completo segun su maxCapacity. Decuelve true si esta lleno, de lo contrario devuelve false. */
        void showStudentsSortedByName() const;
        /* Muestra un listado de estudiantes ordenados alfabeticamente. */
        string getName() const;
        /* Devuelve el nombre del curso. */
    
    private:
        
        // Atributos
        string name; 
        vector<shared_ptr<Student>> students;
        const int maxCapacity = 20;
};

class Student {
    public:
        
        // Constructor
        Student(string fullName, int ID);
        
        // Metodos
        void insertScore(shared_ptr<Course> course, float score);
        /* Inserta un curso con su nota dentro de un map y si ya existe, actualiza el score. */
        string getName() const;
        /* Devuelve el nombre del estudiante. */
        int getID() const;
        /* Devuelve el numero de legajo del estudiante. */
        float getAverage() const;
        /* Devuelve el promedio del estudiante. */

        // Sobrecarga de operadores
        bool operator==(const Student& other) const;
        bool operator<(const Student& other) const;
        friend ostream& operator<<(ostream& os, const Student& other);

    private:
        
        // Atributos
        string fullName;
        int ID;
        map<shared_ptr<Course>, float> scores;
};
