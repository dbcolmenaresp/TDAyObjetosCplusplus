/**
 * EJEMPLO 2: CONSTRUCTOR Y DESTRUCTOR
 * Concepto: El constructor inicializa el objeto al crearlo.
 * El destructor libera recursos al destruirlo.
 * Aprendizaje: Sintaxis de constructor/destructor, orden de ejecución.
 */

#include <iostream>
#include <string>
using namespace std;

class Estudiante {
private:
    string nombre;
    int edad;
    
public:
    // Constructor: se ejecuta automáticamente al crear el objeto
    Estudiante(string nom, int ed) {
        nombre = nom;
        edad = ed;
        cout << "🔨 Constructor: Estudiante " << nombre << " creado." << endl;
    }
    
    // Destructor: se ejecuta automáticamente al destruir el objeto
    ~Estudiante() {
        cout << "💣 Destructor: Estudiante " << nombre << " eliminado." << endl;
    }
    
    void saludar() {
        cout << "Hola, soy " << nombre << " y tengo " << edad << " años." << endl;
    }
};

int main() {
    cout << "=== Inicio del programa ===" << endl;
    
    // Crear objeto: se llama al constructor
    Estudiante alu1("Ana García", 20);
    alu1.saludar();
    
    {
        // Bloque interno: el objeto se destruye al salir del bloque
        Estudiante alu2("Carlos López", 22);
        alu2.saludar();
        cout << "Dentro del bloque, aún existe alu2" << endl;
    } // <-- aquí se destruye alu2 (destructor llamado)
    
    cout << "Fuera del bloque, alu1 aún existe" << endl;
    // Al finalizar main, se destruye alu1 automáticamente
    cout << "=== Fin del programa ===" << endl;
    return 0;
}
