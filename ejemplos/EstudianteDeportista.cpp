/**
 * EJEMPLO 7: HERENCIA MÚLTIPLE
 * Concepto: Una clase puede heredar de múltiples clases base.
 * Aprendizaje: Sintaxis con comas, ambigüedad y resolución.
 */

#include <iostream>
#include <string>
using namespace std;

// Clase base 1
class Estudiante {
protected:
    string nombre;
    string carrera;
public:
    Estudiante(string n, string c) : nombre(n), carrera(c) {}
    void estudiar() {
        cout << nombre << " está estudiando " << carrera << endl;
    }
    void mostrarIdentidad() {
        cout << "Estudiante: " << nombre << " (" << carrera << ")" << endl;
    }
};

// Clase base 2
class Deportista {
protected:
    string nombre;  // Atención: mismo nombre de atributo que en Estudiante
    string deporte;
public:
    Deportista(string n, string d) : nombre(n), deporte(d) {}
    void entrenar() {
        cout << nombre << " está entrenando " << deporte << endl;
    }
    void mostrarIdentidad() {
        cout << "Deportista: " << nombre << " - " << deporte << endl;
    }
};

// Herencia múltiple: EstudianteDeportista hereda de ambas
class EstudianteDeportista : public Estudiante, public Deportista {
private:
    int becaPorcentaje;
    
public:
    // Constructor debe inicializar ambas clases base
    EstudianteDeportista(string nomEst, string carr, string nomDep, string dep, int beca)
        : Estudiante(nomEst, carr), Deportista(nomDep, dep), becaPorcentaje(beca) {}
    
    void mostrarTodo() {
        // Resolver ambigüedad usando el operador de resolución de ámbito
        Estudiante::mostrarIdentidad();
        Deportista::mostrarIdentidad();
        cout << "Beca: " << becaPorcentaje << "%" << endl;
    }
    
    void rutinaDiaria() {
        estudiar();   // De Estudiante
        entrenar();   // De Deportista
        cout << "Y duerme 8 horas." << endl;
    }
};

int main() {
    EstudianteDeportista ed("Ana", "Ingeniería", "Ana", "Natación", 75);
    
    cout << "=== Herencia Múltiple en acción ===" << endl;
    ed.rutinaDiaria();
    cout << endl;
    ed.mostrarTodo();
    
    return 0;
}
