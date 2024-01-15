/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: estruckm <estruckm@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/11 23:49:42 by estruckm          #+#    #+#             */
/*   Updated: 2024/01/11 23:49:46 by estruckm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class MyClass {
private:
	int value;
	int test;

public:
	// Constructor is private
	MyClass(int initialValue) : value(initialValue) {
		// Initialization logic goes here
		test = 532;
	}

	// Factory method to create an instance
	static MyClass createInstance(int initialValue) {
		// Additional setup logic goes here
		// This method can return an instance of MyClass
		return MyClass(initialValue);
	}

	// Other methods can be defined here
	void printValue() {
		std::cout << "Value: " << value << std::endl;
	}
};

int main() {
	// Use the factory method to create an instance
	MyClass obj = MyClass::createInstance(42);

	// Use the object
	obj.printValue();

	return 0;
}