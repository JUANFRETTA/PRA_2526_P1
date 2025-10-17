#include "Square.h"
#include <cmath>

bool Square::check(Point2D* vertices){
	double d0 = Point2D::distance(vertices[0],vertices[1]);
	double d1 = Point2D::distance(vertices[2],vertices[3]);
	double d2 = Point2D::distance(vertices[1],vertices[2]);
	double d3 = Point2D::distance(vertices[0],vertices[3]);

	return (fabs(d0) == fabs(d1) &&  fabs(d1) == fabs(d2) && fabs(d2) == fabs(d3));
}

Square::Square() : Rectangle() {
	vs = new Point2D[N_VERTICES]{
		Point2D(-1,1),
		Point2D(1,1),
		Point2D(1,-1),
		Point2D(-1,-1)
		};
}

Square::Square(string color, Point2D* vertices) : Rectangle(color,vertices){
	if(!check(vertices))
		throw invalid_argument("Cuadrado no válido");

	set_vertices(vertices);
}

void Square::set_vertices(Point2D* vertices){
	if(!check(vertices))
		throw invalid_argument ("Vertices no validos");
	for(int i = 0; i < N_VERTICES; i++)
		vs[i] = vertices[i];
}


void Square::print(){
	cout << "Cuadrado de color " << color << "con vertices: ";

	for(int i  = 0; i<N_VERTICES;i++)
		cout << vs[i] << " ";
	cout << endl;
}


ostream& operator<<(ostream &out, const Square &square){

	out << "Cuadrado de color " << square.color << " con vértices: ";
    	for (int i = 0; i < Rectangle::N_VERTICES; ++i)
        	out << square.vs[i] << " ";
    	return out;
}



double Square::area() const {
    double lado = Point2D::distance(vs[0], vs[1]);
    return lado * lado;
}


double Square::perimeter() const {
    double lado = Point2D::distance(vs[0], vs[1]);
    return 4 * lado;
}


void Square::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

	




