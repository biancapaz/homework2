#pragma once
#include <string>
#include <array>
using namespace std;

class Time;
array<int, 3> checkTimeRange(int hour, int minutes, int seconds);
/* Verifica que los valores ingresados esten dentro de los rangos. 
    Hora: 0 - 11
    Minutos: 0 - 59
    Segundos: 0 - 59 
    
    En el caso de que sea un valor invalido, pide reingresar el dato hasta que sea correcto. Devuelve un array con los datos verificados.
    Returns:
    array<int, 3> {hour, minutes, seconds}
*/
Time* initializeMenu();
/* Menu para incializar el tiempo. Aqui se usan los constructores. */
void readMenu(Time* time);
/* Menu para leer el tiempo. */
void modifyMenu(Time* time);
/* Menu para modificar el tiempo. */
void generalMenu(Time* time);
/* Menu general para elegir la accion de leer o de modificar el tiempo. */

class Time {
    public:

        // Constructores
        Time(); 
        /* Inicializa el tiempo sin parametros. Tiempo: 00h, 00m, 00s a.m.*/
        Time(int hour);
        /* Inicializa el tiempo con la hora. Tiempo: HHh, 00m, 00s a.m.*/
        Time(int hour, int minutes);
        /* Inicializa el tiempo con la hora y los minutos. Tiempo: HHh, MMm, 00s a.m.*/
        Time(int hour, int minutes, int seconds);
        /* Inicializa el tiempo con la hora, los minutos y los segundos. Tiempo: HHh, MMm, SSs a.m.*/
        Time(int hour, int minutes, int seconds, string period);
        /* Inicializa el tiempo con la hora, los minutos, los segundos y el periodo. Tiempo: HHh, MMm, SSs a.m. / p.m.*/

        // Metodos
        void showHour();
        /* Muestra la hora. Tiempo: HHh.*/
        void showMinutes();
        /* Muestra los minutos. Tiempo: MMm.*/
        void showSeconds();
        /* Muestra los segundos. Tiempo: SSs.*/
        void showPeriod();
        /* Muestra el periodo. Tiempo: a.m. / p.m.*/
        void showTime();
        /* Muestra el tiempo completo. Tiempo: HHh, MMm, SSs a.m. / p.m.*/
        void showTime24();
        /* Muestra el tiempo completo en formato 24hs. Tiempo: HHh, MMm, SSs.*/
        void setHour(int newHour);
        /* Modifica la hora.*/
        void setMinutes(int newMinutes);
        /* Modifica los minutos.*/
        void setSeconds(int newSeconds);
        /* Modifica los segundos.*/
        void setPeriod(string newPeriod);
        /* Modifica el periodo.*/

    private:
    
        // Atributos
        int hour;
        string minutes;
        string seconds;
        string period;   
};
