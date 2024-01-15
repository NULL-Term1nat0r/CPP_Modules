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

#include "../includes/easyfind.hpp"

const char* OutOfRangeException::what() const throw() {
	return "integer provided is out of range";
}

template <typename T>
typename T::iterator easyfind(T &container, int n) {
	typename T::iterator it = std::find(container.begin(), container.end(), n);
	if (it == container.end())
		throw OutOfRangeException();
	return it;
}