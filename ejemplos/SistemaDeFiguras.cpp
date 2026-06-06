/**
 * EJEMPLO 18: PATRÓN FACTORY (Integrador)
 * Concepto: Clase estática que crea objetos polimórficamente.
 * Aprendizaje: Aplicar POO en un patrón de diseño.
 */

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// Clase abstracta
class FiguraGeometrica {
public:
    virtual double area() const = 0;
    virtual string nombre() const = 0;
    virtual ~FiguraGeometrica() {}
};

class Cuadrado : public FiguraGeometrica {
    double lado;
public:
    Cuadrado(double l) : lado(l) {}
    double area() const override { return lado * lado; }
    string nombre() const override { return "Cuadrado"; }
};

class CirculoFigura : public FiguraGeometrica {
    double radio;
public:
    CirculoFigura(double r) : radio(r) {}
    double area() const override { return M_PI * radio * radio; }
    string nombre() const override { return "Círculo"; }
};

class TrianguloEq : public FiguraGeometrica {
    double lado;
public:
    TrianguloEq(double l) : lado(l) {}
    double area() const override { return (sqrt(3)/4) * lado * lado; }
    string nombre() const override { return "Triángulo Equilátero"; }
};

// FACTORY: crea figuras según tipo
class FiguraFactory {
public:
    static FiguraGeometrica* crear(string tipo, double valor) {
        if (tipo == "cuadrado") return new Cuadrado(valor);
        if (tipo == "circulo") return new CirculoFigura(valor);
        if (tipo == "triangulo") return new TrianguloEq(valor);
        return nullptr;
    }
};

int main() {
    FiguraGeometrica* figuras[3];
    
    figuras[0] = FiguraFactory::crear("cuadrado", 5);
    figuras[1] = FiguraFactory::crear("circulo", 3);
    figuras[2] = FiguraFactory::crear("triangulo", 4);
    
    cout << "=== FIGURAS CREADAS CON FACTORY ===" << endl;
    for (int i = 0; i < 3; i++) {
        if (figuras[i]) {
            cout << figuras[i]->nombre() << " → Área: " << figuras[i]->area() << endl;
            delete figuras[i];
        }
    }
    
    return 0;
}
