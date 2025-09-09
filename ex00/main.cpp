#include "ScalarConverter.h"
#include <iostream>

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Usage: ./convert <literal>" << std::endl;
        return 1;
    }

    std::string literal = argv[1];

    // Call static method directly, no instance needed
    ScalarConverter::converter(literal);

    return 0;
}
