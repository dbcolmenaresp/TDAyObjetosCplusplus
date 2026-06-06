/**
 * EJEMPLO 14: MIEMBROS ESTÁTICOS
 * Concepto: Los miembros estáticos pertenecen a la clase, no a los objetos.
 * Aprendizaje: Variables estáticas (contadores), métodos estáticos.
 */

#include <iostream>
#include <string>
using namespace std;

class Producto {
private:
    string nombre;
    double precio;
    
    // Atributo estático: compartido por TODOS los objetos
    static int totalProductosCreados;
    static int productosActivos;
    
public:
    Producto(string n, double p) : nombre(n), precio(p) {
        totalProductosCreados++;
        productosActivos++;
        cout << "📦 Producto creado: " << nombre << " (Total: " << totalProductosCreados 
             << ", Activos: " << productosActivos << ")" << endl;
    }
    
    ~Producto() {
        productosActivos--;
        cout << "🗑️ Producto destruido: " << nombre << " (Activos restantes: " << productosActivos << ")" << endl;
    }
    
    // Método estático: puede llamarse sin objeto
    static int getTotalCreados() {
        return totalProductosCreados;
    }
    
    static int getActivos() {
        return productosActivos;
    }
    
    void mostrar() const {
        cout << "Producto: " << nombre << " - $" << precio << endl;
    }
};

// Inicialización de variables estáticas (fuera de la clase)
int Producto::totalProductosCreados = 0;
int Producto::productosActivos = 0;

int main() {
    cout << "=== INICIO ===" << endl;
    cout << "Productos creados: " << Producto::getTotalCreados() << endl;
    
    Producto p1("Laptop", 899.99);
    Producto p2("Mouse", 25.50);
    
    {
        Producto p3("Teclado", 45.00);
        cout << "Dentro del bloque - Activos: " << Producto::getActivos() << endl;
    } // p3 se destruye aquí
    
    Producto p4("Monitor", 199.99);
    
    cout << "\n=== ESTADÍSTICAS FINALES ===" << endl;
    cout << "Total productos creados: " << Producto::getTotalCreados() << endl;
    cout << "Productos activos: " << Producto::getActivos() << endl;
    
    return 0;
}
