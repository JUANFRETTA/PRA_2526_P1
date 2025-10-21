#ifndef DRAWING_H
#define DRAWING_H

#include <iostream>
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Rectangle.h"
#include "List.h"
#include "ListLinked.h"

class Drawing {
private:
    List<Shape*>* shapes;   // interfaz polimórfica

public:
    // Constructor y destructor
    Drawing();
    ~Drawing();

    // Añadir figuras
    void add_front(Shape* shape);
    void add_back(Shape* shape);

    // Mostrar todas las figuras
    void print_all() const;

    // Área total de todos los círculos
    double get_area_all_circles() const;

    // Mover todos los cuadrados
    void move_squares(double incX, double incY);
};

#endif
