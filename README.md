# HOMEWORK 2

EJERCICIO 2.
b. ¿Se usa shallow copy o deep copy para copiar un objeto Course?
    Para la copia de un objeto Course implementamos un constructor: Course(string name, const Course& otherCourse); que permite hacer un shallow copy de una clase ya exisente.
    Esta copia solo es del vector de estudiantes dado que comparten la mayor parte de los estudiantes. El nombre es otro, por lo que se le asigna el ingresado al inicializar 
    el objeto. 
    Se usa shallow copy porque no es necesario hacer una copia independiente de cada uno de los objetos Student del vector de estudiantes. Esto es, queremos que el nuevo curso
    comparta los mismos objetos Student que el original. Ademas, de esta forma, si se modifica los dtos de algun estudiante, se va a ver reflejado en las listas de ambos cursos.
    Usar deep copy implicaria un mayor uso de memoria y desvinculacion entre las listas de los cursos.

c. ¿Qué tipo de relación existe entre los objetos curso y estudiante?
    El tipo de relacion que existe entre los objetos Course y Student es de agregacion. Esta relacion es del tipo has-a donde el curso se interpreta como un todo y los estudiantes
    como parte de este, sin embargo, el ciclo de vida de uno no depende del otro. Esto se debe a que un estudiante puede estar inscripto en mas de un curso y un curso puede tener 
    mas de un estudiante que haga que permanezca activo.

EJERCICIO 4.
a. Especificadores de acceso
    Public:
        Los metodos deposit, withdrawal y showInfo, y los constructores estan declarados como pubic porque garantiza que las clases derivadas puedan sobrescribir (override) y utilizar
        estos métodos.
    Protected:
        Los atributos balance y accountHolder en BankAccount están definidos como protected porque son sensibles y no deben ser accesibles directamente desde fuera del objeto por
        seguridad. Sin embargo, las clases derivadas necesitan manipularlos para aplicar lógicas específicas (por ejemplo, cargos por retiro o transferencias). Entonces, al ser
        protected las clases derivadas accedan de manera segura y controlada, respetando el principio de encapsulamiento con flexibilidad para la extensión.
    Private:
        Los atributos específicos como timesShowed y fee en SavingsAccount, y linkedSavings en CheckingAccount, están declarados como private porque son detalles internos del
        funcionamiento de cada cuenta y no deben ser manipulados desde fuera de la clase.

Lineas de compilacion

1. 
    g++ -g main1.cpp ej1.cpp -o program
    ./program

2. 
    g++ -g main2.cpp ej2.cpp -o program
    ./program

3.
    g++ -g main3.cpp ej3.cpp -o program
    ./program

4.
    g++ -g main4.cpp ej4.cpp -o program
    ./program

Valgrind:
    valgrind --leak-check=full --track-origins=yes ./program