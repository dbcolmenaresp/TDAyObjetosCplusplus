/**
 * EJEMPLO 4: MÉTODOS CONST Y PUNTERO THIS
 * Concepto: Métodos const no modifican el objeto. 'this' apunta al objeto actual.
 * Aprendizaje: Buenas prácticas para métodos de solo lectura.
 */

#include <iostream>
#include <iomanip>
using namespace std;

class Reloj {
private:
    int horas;
    int minutos;
    int segundos;
    
public:
    // Constructor con valores por defecto
    Reloj(int h = 0, int m = 0, int s = 0) {
        establecerHora(h, m, s);
    }
    
    // Método que modifica el objeto (no const)
    void establecerHora(int h, int m, int s) {
        horas = (h >= 0 && h < 24) ? h : 0;
        minutos = (m >= 0 && m < 60) ? m : 0;
        segundos = (s >= 0 && s < 60) ? s : 0;
    }
    
    // Método const: NO modifica el objeto (solo lectura)
    void mostrarHora() const {
        cout << setfill('0');
        cout << setw(2) << horas << ":"
             << setw(2) << minutos << ":"
             << setw(2) << segundos << endl;
    }
    
    // Demostración del puntero 'this'
    Reloj& incrementarSegundo() {
        segundos++;
        if (segundos >= 60) {
            segundos = 0;
            minutos++;
            if (minutos >= 60) {
                minutos = 0;
                horas++;
                if (horas >= 24) {
                    horas = 0;
                }
            }
        }
        return *this;  // Retorna referencia al objeto actual (para encadenar)
    }
    
    // Getter const (no modifica)
    int getHoras() const { return horas; }
    int getMinutos() const { return minutos; }
    int getSegundos() const { return segundos; }
};

int main() {
    Reloj r(23, 59, 55);
    
    cout << "Hora inicial: ";
    r.mostrarHora();
    
    // Encadenamiento gracias a return *this
    r.incrementarSegundo().incrementarSegundo().incrementarSegundo().incrementarSegundo();
    
    cout << "Después de 5 segundos: ";
    r.mostrarHora();
    
    // Uso de getters const
    cout << "Hora actual (solo lectura): " 
         << r.getHoras() << "h " << r.getMinutos() << "m" << endl;
    
    return 0;
}
