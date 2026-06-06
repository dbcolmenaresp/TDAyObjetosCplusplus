/**
 * EJEMPLO 13: DEMOSTRACIÓN DE LA TABLA VIRTUAL (vtable)
 * Concepto: Cada clase con funciones virtuales tiene una vtable.
 * Aprendizaje: Visualizar cómo C++ resuelve las llamadas virtuales.
 */

#include <iostream>
using namespace std;

class Base {
public:
    virtual void f1() { cout << "Base::f1()" << endl; }
    virtual void f2() { cout << "Base::f2()" << endl; }
    void f3() { cout << "Base::f3() (no virtual)" << endl; }
    virtual ~Base() {}
};

class Derivada : public Base {
public:
    void f1() override { cout << "Derivada::f1()" << endl; }
    virtual void f4() { cout << "Derivada::f4()" << endl; }
};

int main() {
    Base* ptr = new Derivada();
    
    cout << "=== Llamadas virtuales (vtable) ===" << endl;
    ptr->f1();  // Resuelto en tiempo de ejecución → Derivada::f1()
    ptr->f2();  // Resuelto en tiempo de ejecución → Base::f2()
    ptr->f3();  // Resuelto en tiempo de compilación → Base::f3()
    
    // ptr->f4();  // ERROR: Base no tiene f4()
    
    delete ptr;
    
    cout << "\n📌 Explicación: Cada objeto tiene un puntero virtual (vptr)\n";
    cout << "que apunta a la vtable de su clase. Las llamadas virtuales\n";
    cout << "usan la vtable para encontrar la función correcta en tiempo real.\n";
    
    return 0;
}
