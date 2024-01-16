#include "Point.hpp"

Point::Point() : x(0), y(0){}
//deconstructor
Point::~Point(){}
//copy constructor
Point::Point(const Point &other){
	*this = other;
}
//int constructor
Point::Point(const int number1, const int number2){
	Fixed a(number1);
	Fixed b(number2);
	x = a;
	y = b;
}

Point::Point(const float number1, const float number2){
	Fixed a(number1);
	Fixed b(number2);
	x = a;
	y = b;
}

//constructor that takes two float point numbers and initializes x and y
Point::Point(const Fixed x_input, const Fixed y_input) : x(x_input), y(y_input){}
//copy assignemnt constructor
Point &Point::operator=(const Point &other){
	x = other.getPointX();
	y = other.getPointY();
	return *this;
}
Fixed Point::getPointX(void) const{
	return x;
}
Fixed Point::getPointY(void) const{
	return y;
}

void Point::outputToStream(std::ostream &out, const Point &fixed) const {
	out << fixed.getPointX().toFloat() << " " << fixed.getPointY().toFloat();
}

std::ostream &operator<<(std::ostream &out, const Point &fixed) {
	fixed.outputToStream(out, fixed);
	return out;
}

std::istream &operator>>(std::istream &in, Point &point) {
	std::cout << "provide the x coordinate\n";
	float inputValue1;
	in >> inputValue1;
	std::cout << "provide the y coordinate\n";
	float inputValue2;
	in >> inputValue2;
	point = Point(inputValue1, inputValue2);
	return in;
}
