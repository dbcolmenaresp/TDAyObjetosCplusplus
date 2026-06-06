/**
 * EJEMPLO 9: ORDEN DE CONSTRUCTORES/DESTRUCTORES EN HERENCIA
 * Concepto: Primero se construye la base, luego la derivada.
 * Destrucción: orden inverso.
 * Aprendizaje: Control del flujo de inicialización.
 */

#include <iostream>
using namespace std;

class Base {
public:
    Base() {
        cout << "🟦 Constructor de Base" << endl;
    }
    ~Base() {
        cout << "🔹 Destructor de Base" << endl;
    }
};

class Derivada : public Base {
public:
    Derivada() {
        cout << "🟩 Constructor de Derivada" << endl;
    }
    ~Derivada() {
        cout << "🟢 Destructor de Derivada" << endl;
    }
};

class MuyDerivada : public Derivada {
public:
    MuyDerivada() {
        cout << "🟨 Constructor de MuyDerivada" << endl;
    }
    ~MuyDerivada() {
        cout << "🟡 Destructor de MuyDerivada" << endl;
    }
};

int main() {
    cout << "=== Creando objeto MuyDerivada ===" << endl;
    MuyDerivada obj;
    cout << "=== Objeto en uso ===" << endl;
    cout << "=== Saliendo del ámbito... ===" << endl;
    // Al salir, se llaman los destructores en orden inverso
    return 0;
}
