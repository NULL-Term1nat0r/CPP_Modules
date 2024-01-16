/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AllClasses.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:30:28 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/03 18:30:28 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AllClasses.hpp"

Base::~Base(){}

Base * generate(void)
{
	static bool srandCalled = false;

	if (!srandCalled) {
		std::srand(std::time(0));
		srandCalled = true;
	}

	int rand_num = std::rand() % 3;
	if (rand_num == 0){
		std::cout << blue << "new random class A got created\n" << reset;
		return new A;
	}
	else if (rand_num == 1) {
		std::cout << blue << "new random class B got created\n" << reset;
		return new B;
	}
	else {
		std::cout << blue << "new random class C got created\n" << reset;
		return new C;
	}
}

void identify(Base* p)
{
	if (dynamic_cast<A*>(p))
		std::cout << red <<  "*P points to type A\n" << reset;
	else if (dynamic_cast<B*>(p))
		std::cout << red << "*P points to type B\n" << reset;
	else if (dynamic_cast<C*>(p))
		std::cout << red << "*P points to type C\n" << reset;
	else
		std::cout << red << "*P points to unknown class\n" << reset;
}

void identify(Base& p)
{
	try
	{
		A	&a = dynamic_cast<A&>(p);
		std::cout << green << "&P points to type A\n" << reset;
	}
	catch(const std::exception& e){}
	try
	{
		B	&b = dynamic_cast<B&>(p);
		std::cout << green << "&P points to type B\n" << reset;
	}
	catch(const std::exception& e){}
	try
	{
		C	&c = dynamic_cast<C&>(p);
		std::cout << green << "&P points to type C\n" << reset;
	}
	catch(const std::exception& e){}
}