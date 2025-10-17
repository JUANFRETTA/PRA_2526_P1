#include "Rectangle.h"
#include <cmath>
#include <iomanip>


bool Rectangle::check(Point2D* vertices){
	
	double d1 = Point2D::distance(vertices[0],vertices[1]);
	double d2 = Point2D::distance(vertices[2],vertices[3]);
	double d3 = Point2D::distance(vertices[1],vertices[2]);
	double d4 = Point2D::distance(vertices[3],vertices[0]);

	return (fabs(d1-d2) == 0) && (fabs(d3-d4) == 0);
}

Rectangle::Rectangle() : Shape(){
	vs = new Point2D[N_VERTICES]{
		Point2D(-1,0.5),
		Point2D(1, 0.5),
		Point2D(1,-0.5),
		Point2D(-1,-0.5),
	};
}

Rectangle::Rectangle(string color, Point2D* vertices)
	:Shape(){
	
	if(!check(vertices))
		throw invalid_argument("Los vertices no forman un rectangulo.");
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i < N_VERTICES;i++)
		vs[i] = vertices[i];
}

Rectangle::Rectangle(const Rectangle &r) : Shape(r.color) {
	vs = new Point2D[N_VERTICES];
	for(int i = 0; i<N_VERTICES; i++)
			vs[i] = r.vs[i];
}

Rectangle::~Rectangle(){
	delete[] vs;
}


Point2D Rectangle::get_vertex(int ind) const{
	if(ind < 0 || ind >= N_VERTICES)
		throw out_of_range("Indice fuera de rango");
	return vs[ind];
}





// ---- Método set_vertices ----
void Rectangle::set_vertices(Point2D* vertices) {
    if (!check(vertices))
        throw invalid_argument("Los vértices no forman un rectángulo válido.");

    for (int i = 0; i < N_VERTICES; ++i)
        vs[i] = vertices[i];
}

// ---- Método area ----
double Rectangle::area() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);
    return base * altura;
}

// ---- Método perimeter ----
double Rectangle::perimeter() const {
    double base = Point2D::distance(vs[0], vs[1]);
    double altura = Point2D::distance(vs[1], vs[2]);
    return 2 * (base + altura);
}

// ---- Método translate ----
void Rectangle::translate(double incX, double incY) {
    for (int i = 0; i < N_VERTICES; ++i) {
        vs[i].x += incX;
        vs[i].y += incY;
    }
}

// ---- Método print ----
void Rectangle::print() {
    cout << fixed << setprecision(2);
    cout << "Rectángulo de color " << color << " con vértices: ";
    for (int i = 0; i < N_VERTICES; ++i) {
        cout << vs[i];
        if (i < N_VERTICES - 1) cout << ", ";
    }
    cout << endl;
}

// ---- Operador de asignación ----
Rectangle& Rectangle::operator=(const Rectangle& r) {
    if (this != &r) {
        color = r.color;

        delete[] vs;
        vs = new Point2D[N_VERTICES];
        for (int i = 0; i < N_VERTICES; ++i)
            vs[i] = r.vs[i];
    }
    return *this;
}

// ---- Operador de salida << ----
ostream& operator<<(ostream& out, const Rectangle& r) {
    out << "Rectángulo de color " << r.color << " con vértices: ";
    for (int i = 0; i < Rectangle::N_VERTICES; ++i) {
        out << r.vs[i];
        if (i < Rectangle::N_VERTICES - 1) out << ", ";
    }
    return out;
}
