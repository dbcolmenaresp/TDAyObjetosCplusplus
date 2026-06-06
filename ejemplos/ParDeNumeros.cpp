/**
 * EJEMPLO 15: CLASES Y FUNCIONES AMIGAS (FRIEND)
 * Concepto: Una función o clase amiga puede acceder a miembros privados.
 * Aprendizaje: Uso controlado de 'friend' para ciertas operaciones.
 */

#include <iostream>
using namespace std;

class ParNumeros {
private:
    int a;
    int b;
    
public:
    ParNumeros(int x, int y) : a(x), b(y) {}
    
    // Declarar una función externa como amiga
    friend int suma(const ParNumeros& p);
    
    // Declarar una clase como amiga
    friend class Operaciones;
    
    void mostrar() const {
        cout << "(" << a << ", " << b << ")" << endl;
    }
};

// Función amiga (no es miembro de la clase)
int suma(const ParNumeros& p) {
    // Puede acceder a a y b aunque sean privados
    return p.a + p.b;
}

// Clase amiga
class Operaciones {
public:
    static int producto(const ParNumeros& p) {
        return p.a * p.b;
    }
    
    static int diferencia(const ParNumeros& p) {
        return p.a - p.b;
    }
};

int main() {
    ParNumeros p(10, 5);
    
    cout << "Par: ";
    p.mostrar();
    
    cout << "Suma (función amiga): " << suma(p) << endl;
    cout << "Producto (clase amiga): " << Operaciones::producto(p) << endl;
    cout << "Diferencia (clase amiga): " << Operaciones::diferencia(p) << endl;
    
    return 0;
}
