#include "ScalarConverter.h"

int main(int argc, char **argv)
{
	std::cout << "Scalar Converter: \n";
	if (argc != 2)
		std::cout<< "Give me something i can work with...\n";
	else
		ScalarConverter::converter(argv[1]);
	return EXIT_SUCCESS;
}