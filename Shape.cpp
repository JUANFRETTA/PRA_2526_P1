#include "Shape.h"

	Shape::Shape(){
	color = "rojo";
	}

	Shape::Shape(string color){
	this->color = color;
	}

	string Shape::get_color()const{
	return color;
	}

	void Shape::set_color(string color){
	this->color = color;
	}
