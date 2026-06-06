/**
 * EJEMPLO 5: ARRAY DE OBJETOS
 * Concepto: Agrupar múltiples objetos en un arreglo.
 * Aprendizaje: Crear y manipular colecciones de objetos.
 */

#include <iostream>
#include <string>
using namespace std;

class Libro {
private:
    string titulo;
    string autor;
    int anio;
    bool prestado;
    
public:
    // Constructor por defecto
    Libro() : titulo("Sin título"), autor("Anónimo"), anio(0), prestado(false) {}
    
    // Constructor con parámetros
    Libro(string t, string a, int an) : titulo(t), autor(a), anio(an), prestado(false) {}
    
    void prestar() {
        if (!prestado) {
            prestado = true;
            cout << "📖 \"" << titulo << "\" ha sido prestado." << endl;
        } else {
            cout << "⚠️ \"" << titulo << "\" ya está prestado." << endl;
        }
    }
    
    void devolver() {
        if (prestado) {
            prestado = false;
            cout << "📚 \"" << titulo << "\" ha sido devuelto." << endl;
        }
    }
    
    void mostrar() const {
        cout << "📕 \"" << titulo << "\" - " << autor << " (" << anio << ") "
             << (prestado ? "[PRESTADO]" : "[DISPONIBLE]") << endl;
    }
    
    string getTitulo() const { return titulo; }
};

int main() {
    // Crear un array de 3 libros (objetos)
    Libro biblioteca[3] = {
        Libro("Cien años de soledad", "Gabriel García Márquez", 1967),
        Libro("El Quijote", "Miguel de Cervantes", 1605),
        Libro("1984", "George Orwell", 1949)
    };
    
    cout << "=== CATÁLOGO INICIAL ===" << endl;
    for (int i = 0; i < 3; i++) {
        biblioteca[i].mostrar();
    }
    
    // Operaciones
    cout << "\n=== OPERACIONES ===" << endl;
    biblioteca[0].prestar();
    biblioteca[2].prestar();
    biblioteca[0].prestar();  // Intento de prestar nuevamente
    
    cout << "\n=== CATÁLOGO FINAL ===" << endl;
    for (int i = 0; i < 3; i++) {
        biblioteca[i].mostrar();
    }
    
    return 0;
}
