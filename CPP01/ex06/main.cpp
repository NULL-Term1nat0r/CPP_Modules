/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:20:48 by estruckm          #+#    #+#             */
/*   Updated: 2023/09/05 19:56:55 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"


int main(int argc, char **argv){

	Harl harl;
	if (argc != 2){
		std::cout << "provide a valid number of arguments\n";
		return (1);
	}
	harl.print(argv[1]);

	return 0;
}



