#include "Circle.h"

	Circle::Circle()
    		: Shape(), center(0.0, 0.0), radius(1.0) {}
	

	Circle::Circle(std::string color, Point2D center, double radius)
    		: Shape(color), center(center), radius(radius) {}
	

	Point2D Circle::get_center() const {
		return center;
	}

	void Circle::set_center(Point2D p){
		center = p;
	}

	double Circle::get_radius() const{
		return radius;
	}

	void Circle::set_radius(double r){
		radius = r;
	}

	ostream& operator<<(ostream &out, const Circle &c){
		out << "Circulo de color " << c.color
		    << " con centro " << c.center
		    << " y radio " << c.radius;
		return out;
	}
	
	void Circle::print() {
   		cout << "Círculo de color " << color
              	<< " con centro " << center
              		<< " y radio " << radius << std::endl;
	}

	double Circle::area() const{
		return 3.141592 * pow(radius,2);
	}

	double Circle::perimeter()const{
		return 2 * 3.141592 * radius;
	}

	void Circle::translate(double incX, double incY){
		center.x += incX;
		center.y += incY;
	}



