
#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP
#include <string>
#include <sstream>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cmath>
#include <stdexcept>

#define MAX_INT 2147483647
#define MIN_INT -2147483648
#define MY_NAN (0.0 / 0.0) // Define NaN as a division by zero result (platform-dependent)
#define MY_NANF (0.0f / 0.0f) // Define NaN as a division by zero result (platform-dependent)
#define MY_HUGE_VAL (1.0 / 0.0)
#define MY_HUGE_VALF (1.0f / 0.0f)

class ScalarConverter
{
private:

	static void printChar(std::string convert);
	static void printInt(std::string convert);
	static void printFloat(std::string convert);
	static void printDouble(std::string convert);

	static double stringToDouble(const std::string& str);
	static float stringToFloat(const std::string& str);
	static int stringToInt(const std::string& str);

	static bool checkIfNumericLimits(std::string convert);
	static bool isValidInput(const std::string& str);


	static bool isChar(const std::string& str);
	static bool isPrintableChar(const std::string& str);
	static bool isNumber(const std::string& str);
	static bool isInt(const std::string& str);




public:
	ScalarConverter();
	ScalarConverter(ScalarConverter const &converter);
	~ScalarConverter();
	ScalarConverter	&operator=(ScalarConverter const &converter);

	static void convertTypes(std::string convert);

};

#endif