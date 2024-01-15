/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:59:03 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/04 08:59:03 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/Array.hpp"

int main (){
	std::cout << green << "-------------------TEST-1-(proper construction)------------------" << reset <<std::endl;
	try {
		Array<int> integerArray1(100);
		integerArray1.print();
		std::cout << cyan << "Number at index[3]:  " << integerArray1[3] << reset << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << green << "-------------------TEST-2-(copy contructor)------------------" << reset <<std::endl;
	try {
		Array<int> integerArray1(100);
		Array<int> integerArray2 = integerArray1;
		integerArray2.print();
		std::cout << cyan << "Number at index[3]:  " << integerArray1[3] << reset << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << green << "-------------------TEST-3-(wrong index)------------------" << reset <<std::endl;
	try {
		Array<int> integerArray1(100);
		std::cout << cyan << "Number at index[3]:  "<< integerArray1[130] << reset << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << green << "-------------------TEST-4-(deconstructor)------------------" << reset <<std::endl;
	try {
		Array<int> integerArray1(100);
		Array<int>integerArray2(integerArray1);
		std::cout << cyan << "Objects have gone out of scope, destructors have been called. No segfault accured" << reset << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << "We dont even get here because it would segfault\n";
	}
	std::cout << green << "-------------------TEST-5-(default constructor)------------------" << reset <<std::endl;
	try {
		Array<int> integerArray1;
		integerArray1.print();
	}
	catch (const std::exception &e)
	{
		std::cout << "We dont even get here because it would segfault\n";
	}
	std::cout << green << "-------------------TEST-6-(return size)------------------" << reset <<std::endl;
	try {
		Array<int> integerArray1;
		std::cout << cyan << "size of integerArray1: " << integerArray1.size() << reset << std::endl;
		Array<int> integerArray2(100);
		std::cout << cyan << "size of integerArray2: " << integerArray2.size() << reset << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
