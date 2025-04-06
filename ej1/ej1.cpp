#include "ej1.hpp"
#include <iostream>
#include <iomanip>
#include <array>
using namespace std;

/* Implementacion de Time */

array<int, 3> checkTimeRange(int hour, int minutes = 0, int seconds = 0) {
    while (!(hour >= 0 && hour <= 11)) {
        cout << "Se ha ingresado una hora fuera del rango esperado [0, 11]." << endl;
        cout << "Ingrese nuevamente la hora: " << endl;
        cin >> hour;
    }
    while (!(minutes >= 0 && minutes <= 59)) {
        cout << "Se ha ingresado minutos fuera del rango esperado [0, 59]." << endl;
        cout << "Ingrese nuevamente los minutos: " << endl;
        cin >> minutes;
    }
    while (!(seconds >= 0 && seconds <= 59)) {
        cout << "Se ha ingresado segundos fuera del rango esperado [0, 59]." << endl;
        cout << "Ingrese nuevamente los segundos: " << endl;
        cin >> seconds;
    }
    return {hour, minutes, seconds};
};

/* Contenedores */

Time::Time() {
    hour = 0;
    minutes = "00m";
    seconds = "00s";
    period = "a.m.";
};

Time::Time(int hour) {
    array<int, 3> time = checkTimeRange(hour);
    
    this->hour = time[0];
    minutes = "00m";
    seconds = "00s";
    period = "a.m.";    
};

Time::Time(int hour, int minutes) {
    array<int, 3> time = checkTimeRange(hour, minutes);

    this->hour = time[0];
    this->minutes = (time[1] < 10) ? ('0' + to_string(time[1]) + 'm') : to_string(time[1]) + 'm';
    seconds = "00s";
    period = "a.m.";    
};

Time::Time(int hour, int minutes, int seconds) {
    array<int, 3> time = checkTimeRange(hour, minutes, seconds);
    
    this->hour = time[0];
    this->minutes = (time[1] < 10) ? ('0' + to_string(time[1]) + 'm') : to_string(time[1]) + 'm';
    this->seconds = (time[2] < 10) ? ('0' + to_string(time[2]) + 's') : to_string(time[2]) + 's';
    period = "a.m.";
};

Time::Time(int hour, int minutes, int seconds, string period) {
    array<int, 3> time = checkTimeRange(hour, minutes, seconds);

    this->hour = time[0];
    this->minutes = (time[1] < 10) ? ('0' + to_string(time[1]) + 'm') : to_string(time[1]) + 'm';
    this->seconds = (time[2] < 10) ? ('0' + to_string(time[2]) + 's') : to_string(time[2]) + 's';
    this->period = period;
};

/* Metodos */
/* Lectura */
void Time::showHour() {
    if (hour < 10) {
        cout << setfill('0') << setw(2) << hour << 'h' << endl;
    }
    else {
        cout << hour << 'h' << endl;
    }
};
void Time::showMinutes() {
    cout << minutes << endl;
};

void Time::showSeconds() {
    cout << seconds << endl;
};

void Time::showPeriod() {
    cout << period << endl;
};

void Time::showTime() {
    if (hour < 10) {
        cout << setfill('0') << setw(2) << hour << "h, " << minutes << ", " << seconds << ' ' << period << endl;
    }
    else {
        cout << hour << "h, " << minutes << ", " << seconds << ' ' << period << endl;
    }
};

void Time::showTime24() {
    if (period == "p.m.") {
        hour = hour + 12;
    }

    if (hour < 10) {
        cout << setfill('0') << setw(2) << hour << "h, " << minutes << ", " << seconds << endl;
    }
    else {
        cout << hour << "h, " << minutes << ", " << seconds << endl;
    }
};

/* Modificacion */
void Time::setHour(int newHour) {
    array<int, 3> time = checkTimeRange(newHour);
    
    this->hour = time[0];
};

void Time::setMinutes(int newMinutes) {
    array<int, 3> time = checkTimeRange(0, newMinutes);

    this->minutes = (time[1] < 10) ? ('0' + to_string(time[1]) + 'm') : to_string(time[1]) + 'm';
};

void Time::setSeconds(int newSeconds) {
    array<int, 3> time = checkTimeRange(0, 0, newSeconds);
    
    this->seconds = (time[2] < 10) ? ('0' + to_string(time[2]) + 's') : to_string(time[2]) + 's';
};

void Time::setPeriod(string newPeriod) {
    this->period = newPeriod;
};


/* Implementacion de menues */
Time* initializeMenu() {
    int choice;
    do {
        cout << "MENU TIEMPO" << endl;
        cout << "0. Inicializar en 0" << endl;
        cout << "1. Inicializar con hora" << endl;
        cout << "2. Inicializar con hora y minutos" << endl;
        cout << "3. Inicializar con hora, minutos y segundos" << endl;
        cout << "4. Inicializar con hora, minutos, segundos y periodo" << endl;
        cout << "5. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();
        cout << "----------" << endl;

        switch (choice) {
            case 0: {
                return new Time();
            }
            case 1: {
                int hour; 
                cout << "Ingrese la hora: ";
                cin >> hour;

                return new Time(hour);
            }
            case 2: {
                int hour; 
                int minutes;
                cout << "Ingrese la hora: ";
                cin >> hour;
                cout << "Ingrese los minutos: ";
                cin >> minutes;

                return new Time(hour, minutes);
            }              
            case 3: {
                int hour; 
                int minutes;
                int seconds;
                cout << "Ingrese la hora: ";
                cin >> hour;
                cout << "Ingrese los minutos: ";
                cin >> minutes;
                cout << "Ingrese los segundos: ";
                cin >> seconds;

                return new Time(hour, minutes, seconds);
            }
            case 4: {
                int hour; 
                int minutes;
                int seconds;
                int period;
                cout << "Ingrese la hora: ";
                cin >> hour;
                cout << "Ingrese los minutos: ";
                cin >> minutes;
                cout << "Ingrese los segundos: ";
                cin >> seconds;
                cout << "Ingrese el periodo: " << endl;
                cout << "0. a.m." << endl;
                cout << "1. p.m."<< endl;
                cout << "Elija una opcion: ";
                cin >> period;
                
                if (period) {
                    return new Time(hour, minutes, seconds, "p.m.");
                }
                return new Time(hour, minutes, seconds, "a.m.");
            }               
            case 5: {
                return nullptr;
            }                
            default: {
                cout << "Opcion ingresada incorrecta.";
                break;
            }
        }
    }
    while (choice != 5);
    return nullptr;
};

void readMenu(Time* time) {
    int choice;
    do {
        cout << "MENU DE LECTURA" << endl;
        cout << "0. Leer hora" << endl;
        cout << "1. Leer minutos" << endl;
        cout << "2. Leer segundos" << endl;
        cout << "3. Leer periodo" << endl;
        cout << "4. Leer tiempo" << endl;
        cout << "5. Leer tiempo en formato 24hs" << endl;
        cout << "6. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();
        cout << "----------" << endl;

        switch (choice) {
            case 0: {
                time->showHour();
                break;
            }
            case 1: {
                time->showMinutes();
                break;
            }
            case 2: {
                time->showSeconds();
                break;
            }              
            case 3: {
                time->showPeriod();
                break;
            }
            case 4: {
                time->showTime();
                break;
            }               
            case 5: {
                time->showTime24();
                break;
            }
            case 6: {
                break;
            }                
            default: {
                cout << "Opcion ingresada incorrecta.";
                break;
            }
        }
    }
    while (choice != 6);
};

void modifyMenu(Time* time) {
    int choice;
    do {
        cout << "MENU DE CAMBIOS" << endl;
        cout << "0. Cambiar hora" << endl;
        cout << "1. Cambiar minutos" << endl;
        cout << "2. Cambiar segundos" << endl;
        cout << "3. Cambiar periodo" << endl;
        cout << "4. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();
        cout << "----------" << endl;

        switch (choice) {
            case 0: {
                int hour;
                cout << "Ingrese la hora: ";
                cin >> hour;
                time->setHour(hour);
                break;
            }
            case 1: {
                int minutes;
                cout << "Ingrese los minutos: ";
                cin >> minutes;
                time->setMinutes(minutes);
                break;
            }
            case 2: {
                int seconds;
                cout << "Ingrese los segundos: ";
                cin >> seconds;
                time->setSeconds(seconds);
                break;
            }              
            case 3: {
                int period;
                cout << "Ingrese el periodo: "<< endl;
                cout << "0. a.m." << endl;
                cout << "1. p.m."<< endl;
                cout << "Elija una opcion: ";
                cin >> period;

                if (period) {
                    time->setPeriod("p.m.");
                }
                else {
                    time->setPeriod("a.m.");
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
    }
    while (choice != 4);
};

void generalMenu(Time* time) {
    int choice;

    do {
        cout << "MENU GENERAL" << endl;
        cout << "0. Lectura del tiempo" << endl;
        cout << "1. Modificar tiempo" << endl;
        cout << "2. Salir" << endl;
        cout << "Elija una opcion: ";
        cin >> choice;
        cin.ignore();
        cout << "----------" << endl;

        switch (choice)         {
            case 0: {
                readMenu(time);
                break;
            }
            case 1: {
                modifyMenu(time);
                break;
            }
            case 2: {
                break;
            }
            default: {
                cout << "Opcion ingresada incorrecta." << endl;
                break;
            }
        }
    }
    while (choice != 2);
};