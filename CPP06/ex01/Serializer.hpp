/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 18:03:00 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/03 18:03:00 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP
# include <cstdint>
# include <string>

typedef struct Data{
	int			age;
	std::string	name;
}Data;

class  Serializer
{
private:

public:
	Serializer();
	Serializer(Serializer const &serial);
	~Serializer();
	Serializer	&operator=(Serializer const &serial);
	uintptr_t serialize(Data* ptr);
	Data* deserialize(uintptr_t raw);
};

#endif