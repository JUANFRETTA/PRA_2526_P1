#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <stdexcept>
#include <iostream>
#include "Shape.h"
#include "Point2D.h"
using namespace std;

class Rectangle : public Shape {
protected:
    Point2D* vs;
public:
    static const int N_VERTICES = 4;

private:
    static bool check(Point2D* vertices);

public:
    Rectangle();
    Rectangle(string color, Point2D* vertices);
    Rectangle(const Rectangle &r);
    ~Rectangle();

    Point2D get_vertex(int ind) const;
    Point2D operator[](int ind) const;

    virtual void set_vertices(Point2D* vertices);

    // Sobrecarga de asignación
    Rectangle& operator=(const Rectangle &r);

    // Implementaciones de los métodos abstractos de Shape
    double area() const override;
    double perimeter() const override;
    void translate(double incX, double incY) override;
    void print() override;

    // Operador de salida
    friend ostream& operator<<(ostream &out, const Rectangle &r);
};

#endif
