/**
 * EJEMPLO 10: FUNCIONES VIRTUALES (POLIMORFISMO)
 * Concepto: Una función virtual permite que la versión de la clase
 * derivada se ejecute a través de un puntero de la clase base.
 * Aprendizaje: Uso de 'virtual', 'override', vinculación dinámica.
 */

#include <iostream>
#include <string>
using namespace std;

class Animal {
protected:
    string nombre;
public:
    Animal(string n) : nombre(n) {}
    
    // Método VIRTUAL: permite polimorfismo
    virtual void hacerSonido() const {
        cout << nombre << " hace un sonido genérico." << endl;
    }
    
    // Destructor virtual: importante para herencia polimórfica
    virtual ~Animal() {
        cout << "Destructor Animal" << endl;
    }
};

class Perro : public Animal {
public:
    Perro(string n) : Animal(n) {}
    
    void hacerSonido() const override {  // 'override' es opcional pero recomendado
        cout << "🐕 " << nombre << " ladra: ¡Guau!" << endl;
    }
};

class Gato : public Animal {
public:
    Gato(string n) : Animal(n) {}
    
    void hacerSonido() const override {
        cout << "🐈 " << nombre << " maúlla: Miau" << endl;
    }
};

class Vaca : public Animal {
public:
    Vaca(string n) : Animal(n) {}
    
    void hacerSonido() const override {
        cout << "🐄 " << nombre << " muge: Muuu" << endl;
    }
};

int main() {
    // Array de punteros a la clase base
    Animal* animales[3];
    
    animales[0] = new Perro("Rex");
    animales[1] = new Gato("Misi");
    animales[2] = new Vaca("Lola");
    
    cout << "=== POLIMORFISMO EN ACCIÓN ===" << endl;
    for (int i = 0; i < 3; i++) {
        // Aunque el tipo es Animal*, se ejecuta el método de la clase real
        animales[i]->hacerSonido();
    }
    
    // Liberar memoria (destructores virtuales aseguran limpieza correcta)
    for (int i = 0; i < 3; i++) {
        delete animales[i];
    }
    
    return 0;
}
