#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>
#include <stdexcept>
#include "Rectangle.h"
#include "Point2D.h"
using namespace std;

class Square : public Rectangle {

	private:
		static bool check(Point2D* vertices);

	public:
		Square();

		Square(string color, Point2D* vertices);

		void set_vertices(Point2D* vertices)override;

		friend ostream& operator<<(ostream &out, const Square &square);

		void print() override;

		double area() const override;

		double perimeter() const override;

    		void translate(double incX, double incY) override;

};

#endif
