#include "ScalarConverter.hpp"


int	main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cout << "Wrong number of args, has to be 1\n";
		return 1;
	}
	ScalarConverter::convertTypes(argv[1]);
}

