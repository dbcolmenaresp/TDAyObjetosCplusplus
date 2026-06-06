/**
 * EJEMPLO 19: COMPOSICIÓN (OBJETOS DENTRO DE OBJETOS)
 * Concepto: Una clase contiene objetos de otras clases.
 * Aprendizaje: Relación "tiene un". Fecha, Producto, Inventario.
 */

#include <iostream>
#include <string>
using namespace std;

class Fecha {
    int dia, mes, anio;
public:
    Fecha(int d=1, int m=1, int a=2000) : dia(d), mes(m), anio(a) {}
    
    void mostrar() const {
        cout << dia << "/" << mes << "/" << anio;
    }
    
    bool operator==(const Fecha& otra) const {
        return dia == otra.dia && mes == otra.mes && anio == otra.anio;
    }
};

class Producto {
    string nombre;
    double precio;
    Fecha fechaCaducidad;
    
public:
    Producto(string n, double p, Fecha f) : nombre(n), precio(p), fechaCaducidad(f) {}
    
    void mostrar() const {
        cout << nombre << " - $" << precio << " (caduca: ";
        fechaCaducidad.mostrar();
        cout << ")" << endl;
    }
    
    string getNombre() const { return nombre; }
    double getPrecio() const { return precio; }
};

class Inventario {
    static const int MAX = 10;
    Producto* productos[MAX];
    int cantidad;
    
public:
    Inventario() : cantidad(0) {
        for (int i = 0; i < MAX; i++) productos[i] = nullptr;
    }
    
    ~Inventario() {
        for (int i = 0; i < cantidad; i++) {
            delete productos[i];
        }
    }
    
    bool agregarProducto(Producto* p) {
        if (cantidad < MAX) {
            productos[cantidad++] = p;
            cout << "✅ Producto agregado: " << p->getNombre() << endl;
            return true;
        }
        cout << "❌ Inventario lleno" << endl;
        return false;
    }
    
    void listar() const {
        cout << "\n=== INVENTARIO (" << cantidad << " productos) ===" << endl;
        for (int i = 0; i < cantidad; i++) {
            cout << i+1 << ". ";
            productos[i]->mostrar();
        }
    }
    
    double valorTotal() const {
        double total = 0;
        for (int i = 0; i < cantidad; i++) {
            total += productos[i]->getPrecio();
        }
        return total;
    }
};

int main() {
    Inventario miInventario;
    
    miInventario.agregarProducto(new Producto("Manzana", 0.50, Fecha(15, 10, 2024)));
    miInventario.agregarProducto(new Producto("Leche", 1.20, Fecha(20, 9, 2024)));
    miInventario.agregarProducto(new Producto("Pan", 0.80, Fecha(5, 9, 2024)));
    
    miInventario.listar();
    cout << "\n💰 Valor total del inventario: $" << miInventario.valorTotal() << endl;
    
    return 0;
}
