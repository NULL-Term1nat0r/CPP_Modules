/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:18:08 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/06 15:18:08 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "../includes/easyfind.hpp"
#include "../includes/colors.hpp"

int main (){
	std::vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	try {
		std::cout << magenta << "-------------------TEST-1------------------" << reset <<std::endl;
		std::cout << *easyfind(v, 3) << std::endl;
		std::cout << magenta << "-------------------TEST-2------------------" << reset <<std::endl;
		std::cout << *easyfind(v, 5) << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}