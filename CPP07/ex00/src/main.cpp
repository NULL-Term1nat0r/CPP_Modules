/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:27:43 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/04 08:31:04 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/template.hpp"

#define magenta "\033[35m"
#define reset "\033[0m"

int main( void ) {
	std::cout << magenta << "-------------------TEST-1------------------" << reset << std::endl;
	int a = 2;
	int b = 3;
	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;
	std::string c = "chaine1";
	std::string d = "chaine2";
	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;

	std::cout << magenta << "-------------------TEST-2------------------" << reset << std::endl;
	int *a1 = new int(2);
	int *b1 = new int(3);
	::swap( a1, b1 );
	std::cout << "a = " << *a1 << ", b = " << *b1 << std::endl;
	std::cout << "min( a, b ) = " << ::min( a1, b1 ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a1, b1 ) << std::endl;
	delete a1;
	delete b1;

	std::cout << magenta << "-------------------TEST-3------------------" << reset << std::endl;
	int *array1 = new int[5];
	int *array2 = new int[5];
	for (int i = 0; i < 5; i++)
	{
		array1[i] = i;
		array2[i] = i + 5;
	}
	::swap( array1, array2 );
	std::cout << "array1 = ";
	for (int i = 0; i < 5; i++)
		std::cout << array1[i] << " ";
	std::cout << std::endl;
	std::cout << "array2 = ";
	for (int i = 0; i < 5; i++)
		std::cout << array2[i] << " ";
	std::cout << std::endl;
	std::cout << "min( array1, array2 ) = " << ::min( array1, array2 ) << std::endl;
	std::cout << "max( array1, array2 ) = " << ::max( array1, array2 ) << std::endl;
	delete [] array1;
	delete [] array2;


	return 0;
}
