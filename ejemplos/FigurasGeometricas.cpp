/**
 * EJEMPLO 11: CLASES ABSTRACTAS (MÉTODOS VIRTUALES PUROS)
 * Concepto: Una clase con al menos un método virtual puro (=0) es abstracta.
 * No se puede instanciar, sirve como interfaz.
 * Aprendizaje: Diseño de interfaces, obligar a implementar métodos.
 */

#include <iostream>
#include <cmath>
using namespace std;

// CLASE ABSTRACTA (INTERFAZ)
class Figura {
public:
    // Métodos virtuales puros → obligan a las clases hijas a implementarlos
    virtual double calcularArea() const = 0;
    virtual double calcularPerimetro() const = 0;
    virtual void dibujar() const = 0;
    
    // Destructor virtual (importante incluso en clases abstractas)
    virtual ~Figura() {}
};

// Clase concreta: Círculo
class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) {}
    
    double calcularArea() const override {
        return M_PI * radio * radio;
    }
    
    double calcularPerimetro() const override {
        return 2 * M_PI * radio;
    }
    
    void dibujar() const override {
        cout << "⚪ Círculo de radio " << radio << endl;
    }
};

// Clase concreta: Rectángulo
class Rectangulo : public Figura {
private:
    double ancho;
    double alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) {}
    
    double calcularArea() const override {
        return ancho * alto;
    }
    
    double calcularPerimetro() const override {
        return 2 * (ancho + alto);
    }
    
    void dibujar() const override {
        cout << "📐 Rectángulo " << ancho << " x " << alto << endl;
    }
};

// Clase concreta: Triángulo
class Triangulo : public Figura {
private:
    double base, altura, lado1, lado2, lado3;
public:
    Triangulo(double b, double a, double l1, double l2, double l3) 
        : base(b), altura(a), lado1(l1), lado2(l2), lado3(l3) {}
    
    double calcularArea() const override {
        return (base * altura) / 2;
    }
    
    double calcularPerimetro() const override {
        return lado1 + lado2 + lado3;
    }
    
    void dibujar() const override {
        cout << "🔺 Triángulo (base=" << base << ", altura=" << altura << ")" << endl;
    }
};

int main() {
    // Figura f;  // ERROR: no se puede instanciar clase abstracta
    
    Figura* figuras[3];
    figuras[0] = new Circulo(5.0);
    figuras[1] = new Rectangulo(4.0, 6.0);
    figuras[2] = new Triangulo(3.0, 4.0, 3.0, 4.0, 5.0);
    
    cout << "=== CÁLCULOS POLIMÓRFICOS ===" << endl;
    for (int i = 0; i < 3; i++) {
        figuras[i]->dibujar();
        cout << "   Área: " << figuras[i]->calcularArea() << endl;
        cout << "   Perímetro: " << figuras[i]->calcularPerimetro() << endl;
        cout << endl;
    }
    
    // Liberar memoria
    for (int i = 0; i < 3; i++) {
        delete figuras[i];
    }
    
    return 0;
}
