/**
 * EJEMPLO 8: HERENCIA EN CADENA (MULTINIVEL)
 * Concepto: Una clase derivada puede ser base para otra.
 * Aprendizaje: Jerarquías de varios niveles.
 */

#include <iostream>
#include <string>
using namespace std;

// Nivel 1: Persona
class Persona {
protected:
    string nombre;
    int edad;
public:
    Persona(string n, int e) : nombre(n), edad(e) {}
    void presentarse() {
        cout << "Me llamo " << nombre << " y tengo " << edad << " años." << endl;
    }
};

// Nivel 2: Empleado hereda de Persona
class Empleado : public Persona {
protected:
    double salario;
    string puesto;
public:
    Empleado(string n, int e, double s, string p) : Persona(n, e), salario(s), puesto(p) {}
    
    void trabajar() {
        cout << nombre << " trabaja como " << puesto << endl;
    }
    
    void mostrarSalario() {
        cout << "Salario: $" << salario << endl;
    }
};

// Nivel 3: Gerente hereda de Empleado
class Gerente : public Empleado {
private:
    int numeroEmpleadosACargo;
    
public:
    Gerente(string n, int e, double s, string p, int numEmps)
        : Empleado(n, e, s, p), numeroEmpleadosACargo(numEmps) {}
    
    void reunirEquipo() {
        cout << nombre << " está liderando a " << numeroEmpleadosACargo << " empleados." << endl;
    }
    
    void mostrarInfoCompleta() {
        presentarse();        // De Persona
        trabajar();           // De Empleado
        reunirEquipo();       // Propio
        mostrarSalario();     // De Empleado
    }
};

int main() {
    Gerente jefe("Carlos Ruiz", 45, 85000.00, "Gerente de TI", 12);
    
    cout << "=== Jerarquía de clases ===" << endl;
    jefe.mostrarInfoCompleta();
    
    return 0;
}
