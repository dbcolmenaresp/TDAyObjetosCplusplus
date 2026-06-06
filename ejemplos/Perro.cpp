#include <iostream>
#include <string>
using namespace std;

// Definición de la Clase
class Perro {
public: // Por ahora público, luego veremos encapsulamiento
    string nombre;
    int edad;
    
    void ladrar() {
        cout << nombre << " dice: ¡Guau!" << endl;
    }
};

int main() {
    // Creación de objetos (instancias)
    Perro miPerro;
    miPerro.nombre = "Rex";
    miPerro.edad = 3;
    miPerro.ladrar(); // Salida: Rex dice: ¡Guau!
    
    Perro* perroPtr = new Perro();
    perroPtr->nombre = "Luna";
    perroPtr->ladrar();
    delete perroPtr; // ¡Importante!
    return 0;
}
