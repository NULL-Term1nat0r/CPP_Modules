/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 20:42:55 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/07 22:49:35 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


int main()
{
	// Fixed a(5);
	// Fixed b(6);


	// Point c(a, b);
	Point a(0, 0);
	Point b(4, 0);
	Point c(2, 3);

	// std::cout << p << std::endl;
	Point g,h,j,p;
	std::cout << "Let's set up a triangle :)\n\n";
	std::cin >> g >> h >> j;
	std::cout << "you've chosen well:\n";
	std::cout << "(" << g << ") " << "(" << h << ") " << "(" << j << ")" << std::endl;
	std::cout << "which point do you wanna check ? Pls type it in: \n";
	std::cin >> p;

	if (bsp(g, h, j, p)) {
		std::cout << "Point is inside the triangle." << std::endl;
	} else {
		std::cout << "Point " << "(" << g << ") " << "is outside the triangle." << std::endl;
	}
	return 0;
}



