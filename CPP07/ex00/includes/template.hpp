/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 08:27:54 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/04 08:28:59 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

#include <iostream>

template<typename T>
void swap(T &a, T &b) {
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename T>
T min(T &a, T &b) {
	return a >= b ? b : a;
}

template<typename T>
T max(T &a, T &b) {
	return b >= a ? b : a;
}

#endif
