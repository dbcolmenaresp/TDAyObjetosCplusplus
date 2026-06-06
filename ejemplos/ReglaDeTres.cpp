/**
 * EJEMPLO 16: COPIA PROFUNDA | REGLA DE LOS TRES
 * Concepto: Si una clase maneja memoria dinámica, debe implementar:
 * - Constructor de copia
 * - Operador de asignación
 * - Destructor
 * Aprendizaje: Evitar memory leaks y doble liberación.
 */

#include <iostream>
#include <cstring>
using namespace std;

class Cadena {
private:
    char* datos;
    int longitud;
    
public:
    // Constructor
    Cadena(const char* str = "") {
        longitud = strlen(str);
        datos = new char[longitud + 1];
        strcpy(datos, str);
        cout << "Constructor: \"" << datos << "\"" << endl;
    }
    
    // Constructor de copia (COPIA PROFUNDA)
    Cadena(const Cadena& otra) {
        longitud = otra.longitud;
        datos = new char[longitud + 1];
        strcpy(datos, otra.datos);
        cout << "Copia profunda: \"" << datos << "\"" << endl;
    }
    
    // Operador de asignación (COPIA PROFUNDA)
    Cadena& operator=(const Cadena& otra) {
        if (this != &otra) {  // Evitar auto-asignación
            delete[] datos;    // Liberar memoria existente
            longitud = otra.longitud;
            datos = new char[longitud + 1];
            strcpy(datos, otra.datos);
            cout << "Asignación profunda: \"" << datos << "\"" << endl;
        }
        return *this;
    }
    
    // Destructor
    ~Cadena() {
        cout << "Destructor: \"" << datos << "\" (liberando memoria)" << endl;
        delete[] datos;
    }
    
    void mostrar() const {
        cout << "Cadena: \"" << datos << "\" (longitud: " << longitud << ")" << endl;
    }
    
    void cambiar(const char* nuevo) {
        delete[] datos;
        longitud = strlen(nuevo);
        datos = new char[longitud + 1];
        strcpy(datos, nuevo);
    }
};

int main() {
    cout << "=== DEMOSTRACIÓN COPIA PROFUNDA ===" << endl;
    
    Cadena c1("Hola Mundo");
    Cadena c2 = c1;  // Constructor de copia (copia profunda)
    
    cout << "\n--- Modificando c1 ---" << endl;
    c1.cambiar("Adiós");
    
    cout << "\nc1: ";
    c1.mostrar();
    cout << "c2: ";
    c2.mostrar();  // c2 no se ve afectado (copia independiente)
    
    cout << "\n--- Asignación ---" << endl;
    Cadena c3("Temporal");
    c3 = c1;  // Operador de asignación
    
    c3.mostrar();
    
    return 0;
}
