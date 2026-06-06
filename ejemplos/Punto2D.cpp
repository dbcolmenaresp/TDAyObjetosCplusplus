/**
 * EJEMPLO 1: CLASE Y OBJETO BÁSICO
 * Concepto: Una clase es un molde, un objeto es una instancia.
 * Aprendizaje: Definir clase, atributos públicos, crear objetos.
 */

#include <iostream>
using namespace std;

// Definición de la clase Punto
class Punto {
public:
    // Atributos (variables miembro)
    double x;
    double y;
    
    // Método (función miembro) para mostrar coordenadas
    void mostrar() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};

int main() {
    // Crear un objeto (instancia) de la clase Punto
    Punto p1;
    
    // Asignar valores a los atributos
    p1.x = 3.5;
    p1.y = 2.8;
    
    // Llamar al método
    cout << "Coordenadas del punto: ";
    p1.mostrar();
    
    // Crear otro objeto independiente
    Punto p2;
    p2.x = -1.0;
    p2.y = 4.2;
    cout << "Segundo punto: ";
    p2.mostrar();
    
    return 0;
}
