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

#include "../includes/array.hpp"

#define magenta "\033[35m"
#define reset "\033[0m"

class Example
{
public:
	Example (void) {initialize_list(); }
	int get(int index) const { return this->n[index]; }
	void initialize_list() { this->n[0] = 1, this->n[1] = 2, this->n[2] = 3; }
	int n[3];
};

std::ostream & operator<<( std::ostream & o, Example const & rhs )
{
	static int index = 0;
	o << rhs.get(index++);
	if (index == 3)
		index = 0;
	return o;
}

int main (){
	std::cout << magenta << "-------------------TEST-1------------------" << reset <<std::endl;
	int tab[] = {0, 1, 2, 3, 4};
	iter(tab, 5, printArray);
	std::cout << std::endl;
	std::cout << magenta << "-------------------TEST-2------------------" << reset <<std::endl;
	Example tab2[3];
	iter(tab2, 3, printArray<Example>);
	std::cout << std::endl;
	return 0;
}
