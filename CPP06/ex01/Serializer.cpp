/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:02:56 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/03 18:02:56 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer(){}


Serializer::Serializer(Serializer const &serial)
{
	*this = serial;
}

Serializer::~Serializer() {}

Serializer	&Serializer::operator=(Serializer const &serial)
{
	*this = serial;
	return *this;
}

uintptr_t	Serializer::serialize(Data* ptr)
{
	uintptr_t convert = reinterpret_cast<uintptr_t>(ptr);
	return convert;
}

Data	*Serializer::deserialize(uintptr_t raw)
{
	Data	*convert = reinterpret_cast<Data*>(raw);
	return convert;
}