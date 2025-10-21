#include "Drawing.h"
#include <typeinfo>   // para typeid
using namespace std;

// ==============================================
// Constructor
// ==============================================
Drawing::Drawing() {
    shapes = new ListLinked<Shape*>();  // instanciamos la lista enlazada
}

// ==============================================
// Destructor
// ==============================================
Drawing::~Drawing() {
    // Liberamos cada figura de la lista
    for (int i = 0; i < shapes->size(); i++) {
        delete shapes->get(i);
    }
    delete shapes;  // liberamos la lista
}

// ==============================================
// Añadir figura al frente
// ==============================================
void Drawing::add_front(Shape* shape) {
    shapes->insert(0, shape);  // al inicio
}

// ==============================================
// Añadir figura al fondo
// ==============================================
void Drawing::add_back(Shape* shape) {
    shapes->append(shape);  // al final
}

// ==============================================
// Mostrar todas las figuras
// ==============================================
void Drawing::print_all() const {
    cout << "=== Dibujo actual ===" << endl;
    for (int i = 0; i < shapes->size(); i++) {
        shapes->get(i)->print();
    }
    cout << endl;
}

// ==============================================
// Calcular área total de todos los círculos
// ==============================================
double Drawing::get_area_all_circles() const {
    double total = 0.0;
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        if (typeid(*s) == typeid(Circle))
            total += s->area();
    }
    return total;
}

// ==============================================
// Mover todos los cuadrados
// ==============================================
void Drawing::move_squares(double incX, double incY) {
    for (int i = 0; i < shapes->size(); i++) {
        Shape* s = shapes->get(i);
        if (typeid(*s) == typeid(Square))
            s->translate(incX, incY);
    }
}
