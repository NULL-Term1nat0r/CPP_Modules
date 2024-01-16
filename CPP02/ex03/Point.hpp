
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 11:18:22 by mdoll             #+#    #+#             */
/*   Updated: 2023/09/07 19:28:38 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

#include <iostream>
#include "Fixed.hpp"
#include <cmath>

class Point {
public:
	//constructor
	Point();
	//deconstructor
	~Point();
	//copy constructor
	Point(const Point &other);
	//constructor that takes two float point numbers and initializes x and y
	Point(const Fixed x_input, const Fixed y_input);
	//int constructor
	Point(const int number1, const int number2);
	//float constructor
	Point(const float number1, const float number2);
	//copy assignment constructor
	Point &operator=(const Point &other);

	//get_functions
	Fixed getPointX(void) const;
	Fixed getPointY(void) const;
	//set_function
	void setPoints(int const x_input, int const y_input);

	void outputToStream(std::ostream &out, const Point &fixed) const;


private:
	// Private members and methods
	Fixed x;
	Fixed y;
};

std::ostream &operator<<(std::ostream &out, Point const &fixed);
std::istream &operator>>(std::istream &in, Point &fixed);
bool bsp(Point const a, Point const b, Point const c, Point const point);

#endif
