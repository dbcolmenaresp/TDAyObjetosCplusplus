/**
 * EJEMPLO 17: OBJETOS CONST Y MIEMBROS CONST
 * Concepto: Objetos constantes solo pueden llamar a métodos const.
 * Aprendizaje: Uso de 'const' en métodos, atributos const.
 */

#include <iostream>
#include <cmath>
using namespace std;

class Punto {
private:
    double x, y;
    
public:
    Punto(double xVal, double yVal) : x(xVal), y(yVal) {}
    
    // Métodos modificadores (no const)
    void mover(double dx, double dy) {
        x += dx;
        y += dy;
    }
    
    // Métodos de solo lectura (const)
    double getX() const { return x; }
    double getY() const { return y; }
    
    double distanciaOrigen() const {
        return sqrt(x*x + y*y);
    }
    
    void mostrar() const {
        cout << "(" << x << ", " << y << ")" << endl;
    }
    
    // Método que retorna const (protege el objeto)
    const Punto& obtenerReferenciaConst() const {
        return *this;
    }
};

int main() {
    // Objeto normal (modificable)
    Punto p1(3, 4);
    p1.mover(1, 0);
    cout << "p1 modificable: ";
    p1.mostrar();
    
    // Objeto CONSTANTE
    const Punto p2(5, 12);
    // p2.mover(1, 0);  // ERROR: no se puede llamar a método no const
    
    cout << "p2 constante: ";
    p2.mostrar();  // OK: mostrar() es const
    
    cout << "Distancia al origen de p2: " << p2.distanciaOrigen() << endl;
    
    return 0;
}
