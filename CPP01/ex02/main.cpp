#include <iostream>

int main(){
	std::string myString = "HI THIS IS BRAIN";
	std::string* stringPTR = &myString;
	std::string& stringREF = myString;

	std::cout << "Adress of myString:  " << &myString << std::endl;
	std::cout << "Adress stringPTR:    " << stringPTR << std::endl;
	std::cout << "Adress of stringREF: " << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << "value of myString:   " << myString << std::endl;
	std::cout << "value  of stringPTR: " << *stringPTR << std::endl;
	std::cout << "value of stringREF:  " << stringREF << std::endl;

	return 0;
}
