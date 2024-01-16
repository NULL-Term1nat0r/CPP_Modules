/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:44 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/03 18:02:44 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "Serializer.hpp"
#include <iostream>

int	main()
{
	Serializer	seri;
	Data *serialized = new Data;
	serialized->name = "jon";
	serialized->age = 30;
	uintptr_t i = seri.serialize(serialized);
	std::cout << "i: " << i << std::endl;
	Data	*deserialized = seri.deserialize(i);
	std::cout << "name: " << deserialized->name << std::endl;
	std::cout << "age: " << deserialized->age << std::endl;
	delete serialized;
}