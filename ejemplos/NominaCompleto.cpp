/**
 * EJEMPLO 20: SISTEMA DE NÓMINA (Proyecto Integrador Final)
 * Conceptos: Todas las POO: Clases, Herencia, Polimorfismo, Encapsulamiento,
 *            Abstracción, Composición, Manejo dinámico.
 */

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Clase abstracta (Abstracción)
class EmpleadoBase {
protected:
    string nombre;
    int id;
    static int contadorId;
    
public:
    EmpleadoBase(string n) : nombre(n), id(++contadorId) {}
    
    virtual double calcularPago() const = 0;  // Puro → abstracto
    virtual string getTipo() const = 0;
    virtual void mostrar() const {
        cout << "ID: " << id << " | Nombre: " << nombre << " | Tipo: " << getTipo();
    }
    
    virtual ~EmpleadoBase() {}
    
    int getId() const { return id; }
    string getNombre() const { return nombre; }
};

int EmpleadoBase::contadorId = 0;

// Empleado por hora
class EmpleadoPorHora : public EmpleadoBase {
    double horasTrabajadas;
    double tarifaPorHora;
    
public:
    EmpleadoPorHora(string n, double tarifa) 
        : EmpleadoBase(n), horasTrabajadas(0), tarifaPorHora(tarifa) {}
    
    void registrarHoras(double horas) {
        if (horas > 0) horasTrabajadas += horas;
    }
    
    double calcularPago() const override {
        double pago = horasTrabajadas * tarifaPorHora;
        if (horasTrabajadas > 40) {
            pago += (horasTrabajadas - 40) * tarifaPorHora * 0.5;  // horas extra
        }
        return pago;
    }
    
    string getTipo() const override { return "Por Hora"; }
    
    void mostrar() const override {
        EmpleadoBase::mostrar();
        cout << " | Horas: " << horasTrabajadas << " | Tarifa: $" << tarifaPorHora << "/h" << endl;
    }
};

// Empleado asalariado
class EmpleadoAsalariado : public EmpleadoBase {
    double salarioMensual;
    double bono;
    
public:
    EmpleadoAsalariado(string n, double salario, double b = 0) 
        : EmpleadoBase(n), salarioMensual(salario), bono(b) {}
    
    double calcularPago() const override {
        return salarioMensual + bono;
    }
    
    string getTipo() const override { return "Asalariado"; }
    
    void mostrar() const override {
        EmpleadoBase::mostrar();
        cout << " | Salario: $" << salarioMensual << " | Bono: $" << bono << endl;
    }
};

// Gerente (hereda de asalariado)
class Gerente : public EmpleadoAsalariado {
    int empleadosACargo;
    
public:
    Gerente(string n, double salario, double bono, int empleados)
        : EmpleadoAsalariado(n, salario, bono), empleadosACargo(empleados) {}
    
    string getTipo() const override { return "Gerente"; }
    
    double calcularPago() const override {
        // Los gerentes tienen bono adicional por equipo
        return EmpleadoAsalariado::calcularPago() + (empleadosACargo * 50);
    }
    
    void mostrar() const override {
        EmpleadoAsalariado::mostrar();
        cout << " | Empleados a cargo: " << empleadosACargo << endl;
    }
};

// Sistema de nómina
class Nomina {
    vector<EmpleadoBase*> empleados;
    
public:
    ~Nomina() {
        for (auto emp : empleados) {
            delete emp;
        }
    }
    
    void contratar(EmpleadoBase* emp) {
        empleados.push_back(emp);
        cout << "📝 Contratado: " << emp->getNombre() << " (" << emp->getTipo() << ")" << endl;
    }
    
    void procesarNomina() const {
        cout << "\n" << string(50, '=') << endl;
        cout << "📊 REPORTE DE NÓMINA" << endl;
        cout << string(50, '=') << endl;
        
        double total = 0;
        for (const auto& emp : empleados) {
            emp->mostrar();
            double pago = emp->calcularPago();
            cout << "   💰 Pago a recibir: $" << pago << endl;
            total += pago;
        }
        
        cout << string(50, '-') << endl;
        cout << "💰 TOTAL NÓMINA: $" << total << endl;
    }
    
    void registrarHorasExtras(int id, double horas) {
        for (auto emp : empleados) {
            if (emp->getId() == id) {
                EmpleadoPorHora* porHora = dynamic_cast<EmpleadoPorHora*>(emp);
                if (porHora) {
                    porHora->registrarHoras(horas);
                    cout << "⏱️ Registradas " << horas << " horas para " << emp->getNombre() << endl;
                } else {
                    cout << "❌ El empleado no es por hora" << endl;
                }
                return;
            }
        }
        cout << "❌ Empleado no encontrado" << endl;
    }
};

int main() {
    Nomina nomina;
    
    cout << "=== SISTEMA DE NÓMINA POO ===" << endl;
    
    // Contratar empleados
    nomina.contratar(new EmpleadoPorHora("Ana Pérez", 15.50));
    nomina.contratar(new EmpleadoAsalariado("Luis Gómez", 2200.0, 300.0));
    nomina.contratar(new Gerente("María López", 3500.0, 800.0, 8));
    nomina.contratar(new EmpleadoPorHora("Carlos Ruiz", 12.75));
    
    // Registrar horas
    nomina.registrarHorasExtras(1, 45);  // Ana trabajó 45 horas
    nomina.registrarHorasExtras(4, 38);  // Carlos trabajó 38 horas
    
    // Procesar nómina completa (polimorfismo en acción)
    nomina.procesarNomina();
    
    return 0;
}
