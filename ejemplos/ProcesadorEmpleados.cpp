/**
 * EJEMPLO 12: POLIMORFISMO CON REFERENCIAS
 * Concepto: Las referencias también permiten polimorfismo.
 * Aprendizaje: Pasar objetos por referencia para usar polimorfismo
 * sin necesidad de punteros.
 */

#include <iostream>
#include <string>
using namespace std;

class Empleado {
protected:
    string nombre;
    double salarioBase;
public:
    Empleado(string n, double s) : nombre(n), salarioBase(s) {}
    
    virtual double calcularPago() const {
        return salarioBase;
    }
    
    virtual void mostrarInfo() const {
        cout << "Empleado: " << nombre << " | Pago: $" << calcularPago() << endl;
    }
    
    virtual ~Empleado() {}
};

class Vendedor : public Empleado {
private:
    double comision;
    double ventas;
public:
    Vendedor(string n, double sBase, double com) 
        : Empleado(n, sBase), comision(com), ventas(0) {}
    
    void registrarVentas(double monto) {
        ventas += monto;
    }
    
    double calcularPago() const override {
        return salarioBase + (ventas * comision / 100);
    }
    
    void mostrarInfo() const override {
        cout << "Vendedor: " << nombre << " | Ventas: $" << ventas 
             << " | Comisión: " << comision << "% | Pago: $" << calcularPago() << endl;
    }
};

class Gerente : public Empleado {
private:
    double bono;
public:
    Gerente(string n, double sBase, double b) : Empleado(n, sBase), bono(b) {}
    
    double calcularPago() const override {
        return salarioBase + bono;
    }
    
    void mostrarInfo() const override {
        cout << "Gerente: " << nombre << " | Bono: $" << bono 
             << " | Pago: $" << calcularPago() << endl;
    }
};

// Función que usa polimorfismo por REFERENCIA
void procesarNomina(const Empleado& emp) {
    // Acepta cualquier objeto derivado de Empleado
    cout << "📄 Procesando nómina: ";
    emp.mostrarInfo();
}

int main() {
    Vendedor vendedor("Ana López", 1200.0, 5.0);
    vendedor.registrarVentas(15000.0);
    
    Gerente gerente("Carlos Ruiz", 2500.0, 800.0);
    
    cout << "=== POLIMORFISMO CON REFERENCIAS ===" << endl;
    procesarNomina(vendedor);   // Se comporta como Vendedor
    procesarNomina(gerente);     // Se comporta como Gerente
    
    return 0;
}
