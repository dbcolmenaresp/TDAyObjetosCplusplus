/**
 * EJEMPLO 6: HERENCIA BÁSICA
 * Concepto: Una clase derivada hereda miembros de la clase base.
 * Relación "es-un": Coche es un Vehículo.
 * Aprendizaje: Sintaxis de herencia, miembros protected.
 */

#include <iostream>
#include <string>
using namespace std;

// CLASE BASE (PADRE)
class Vehiculo {
protected:
    // protected: accesible para clases derivadas, pero privado para el exterior
    string marca;
    int velocidadMaxima;
    
public:
    Vehiculo(string m, int vMax) : marca(m), velocidadMaxima(vMax) {
        cout << "🚗 Constructor de Vehiculo: " << marca << endl;
    }
    
    void acelerar() {
        cout << marca << " está acelerando." << endl;
    }
    
    void mostrarInfo() {
        cout << "Marca: " << marca << " | Vel. Máx: " << velocidadMaxima << " km/h" << endl;
    }
    
    virtual ~Vehiculo() {
        cout << "Destructor de Vehiculo" << endl;
    }
};

// CLASE DERIVADA (HIJA) - Herencia pública
class Coche : public Vehiculo {
private:
    int numeroPuertas;
    
public:
    // Constructor de Coche llama al constructor de Vehiculo
    Coche(string m, int vMax, int puertas) : Vehiculo(m, vMax), numeroPuertas(puertas) {
        cout << "🚘 Constructor de Coche: " << puertas << " puertas" << endl;
    }
    
    void abrirPuertas() {
        cout << marca << " tiene " << numeroPuertas << " puertas abiertas." << endl;
    }
    
    void mostrarInfoCompleta() {
        mostrarInfo();  // Llama al método de la clase base
        cout << "Puertas: " << numeroPuertas << endl;
    }
    
    ~Coche() {
        cout << "Destructor de Coche" << endl;
    }
};

int main() {
    cout << "=== Creando Coche ===" << endl;
    Coche miCoche("Toyota", 220, 4);
    
    cout << "\n=== Usando métodos ===" << endl;
    miCoche.acelerar();           // Heredado de Vehiculo
    miCoche.abrirPuertas();       // Propio de Coche
    miCoche.mostrarInfoCompleta(); // Combinado
    
    return 0;
}
