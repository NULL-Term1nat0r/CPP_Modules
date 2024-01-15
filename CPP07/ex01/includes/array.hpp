/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:59:09 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/04 08:59:09 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <string>

template <typename T, typename Func>
void iter(T *array, size_t length, Func f){
	for (size_t i = 0; i < length; i++)
		f(array[i]);
}

template <typename T>
bool isConst(const T&) {
	return true;
}

template <typename T>
bool isConst(T&) {
	return false;
}

#endif
