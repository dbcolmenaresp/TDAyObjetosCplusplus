/**
 * EJEMPLO 3: ENCAPSULAMIENTO
 * Concepto: Ocultar datos internos (private) y exponer interfaz controlada (public)
 * Aprendizaje: Uso de private, getters y setters con validación.
 */

#include <iostream>
#include <string>
using namespace std;

class CuentaBancaria {
private:
    // Atributos privados: no accesibles desde fuera
    string numeroCuenta;
    double saldo;
    bool activa;
    
public:
    // Constructor
    CuentaBancaria(string num, double saldoInicial) {
        numeroCuenta = num;
        if (saldoInicial >= 0) {
            saldo = saldoInicial;
        } else {
            saldo = 0;
            cout << "⚠️ Saldo inicial inválido, se establece a 0" << endl;
        }
        activa = true;
    }
    
    // Getter (lectura controlada)
    double obtenerSaldo() const {
        return saldo;
    }
    
    string obtenerNumeroCuenta() const {
        return numeroCuenta;
    }
    
    // Setter con validación (escritura controlada)
    void depositar(double cantidad) {
        if (!activa) {
            cout << "❌ Cuenta inactiva. No se puede depositar." << endl;
            return;
        }
        if (cantidad > 0) {
            saldo += cantidad;
            cout << "✅ Depósito exitoso: +$" << cantidad << endl;
        } else {
            cout << "❌ Cantidad inválida para depósito." << endl;
        }
    }
    
    bool retirar(double cantidad) {
        if (!activa) {
            cout << "❌ Cuenta inactiva." << endl;
            return false;
        }
        if (cantidad > 0 && cantidad <= saldo) {
            saldo -= cantidad;
            cout << "💰 Retiro exitoso: -$" << cantidad << endl;
            return true;
        } else {
            cout << "❌ Fondos insuficientes o cantidad inválida." << endl;
            return false;
        }
    }
    
    void mostrarInfo() const {
        cout << "Cuenta: " << numeroCuenta 
             << " | Saldo: $" << saldo 
             << " | Estado: " << (activa ? "Activa" : "Inactiva") << endl;
    }
};

int main() {
    CuentaBancaria miCuenta("ES-1234-5678", 1000.50);
    miCuenta.mostrarInfo();
    
    // Intento de acceso directo a atributo privado (ERROR de compilación)
    // miCuenta.saldo = 5000;  // Descomentar causaría error
    
    // Uso correcto a través de métodos públicos
    miCuenta.depositar(250.75);
    miCuenta.retirar(100.00);
    miCuenta.retirar(2000.00);  // Intento fallido
    
    cout << "Saldo final: $" << miCuenta.obtenerSaldo() << endl;
    
    return 0;
}
