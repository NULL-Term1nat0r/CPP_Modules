/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/06 15:53:22 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/06 15:53:22 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <algorithm>
#include <stdexcept>
#include <vector>
#include <list>


class OutOfRangeException : public std::exception {
public:
	virtual const char *what() const throw();
};
template <typename T>
typename T::iterator easyfind(T &container, int n);

#include "easyfind.tpp"

#endif