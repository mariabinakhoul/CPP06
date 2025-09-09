#include "ScalarConverter.h"
#include <cstdlib>  // for strtol, strtof
#include <cctype>
#include <cfloat> 
#include <cmath>
#include <iomanip>

ScalarConverter::ScalarConverter(){}

ScalarConverter::ScalarConverter(const ScalarConverter&){}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &){return *this;}

ScalarConverter::~ScalarConverter(){}

void ScalarConverter::converter(const std::string &literal)
{
	if (literal.size() == 1 && !isdigit(literal[0]))
	{
		char c = literal[0];
		std::cout << "char: '" << c << "'\n";
		std::cout << "int: " << static_cast<int>(c)<<std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: "<< static_cast<float>(c) << "f\n";
		std::cout << "double: " << static_cast<double>(c) << std::endl;
		return;
	}
	if (literal == "nan" || literal == "nanf")
		{
			std::cout << "char: impossible\n";
			std::cout << "int: impossible\n";
			std::cout << "float: nanf\n";
			std::cout << "double: nan\n";
			return;
		}
	if (literal == "+inf" || literal == "+inff" || literal == "-inf" || literal == "-inff")
		{
			bool isPositive = literal[0] != '-';
			std::string sign = isPositive ? "+" : "-";
			std::cout << "char : impossible\n";
			std::cout << "int: impossible\n";
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << sign << "inff" <<std::endl;
			std::cout << "double: "<< sign << "inf\n";
			return; 
		}
	char *endptr = NULL;
	long l = strtol(literal.c_str(), &endptr, 10);
	if (*endptr == '\0' &&
		l >= std::numeric_limits<int>::min() && l <= std::numeric_limits<int>::max())
	{
		int i = static_cast<int>(l);
		std::cout << "char: ";
		if (i >= 32 && i <= 126)
			std::cout << "'"<< static_cast<char>(i) << "'\n" ;
		else
			std::cout << "Non displayable\n";
		std::cout << "int: " << i << std::endl;
		std::cout << std::fixed << std::setprecision(1);
		std::cout << "float: "<< static_cast<float>(i)<< "f\n";
		std::cout << "double: " << static_cast<double>(i) <<std::endl;
		return;
	}
	if (!literal.empty() && literal[literal.size() - 1] == 'f')
	{
		std::string tmp = literal.substr(0, literal.size() - 1);
		char *endptrf = NULL;
		float f = strtof(tmp.c_str(), &endptrf);
		if (*endptrf == '\0')
		{
			std::cout << "char: " << ((f >= 32 && f <= 126) ? std::string("'") + static_cast<char>(f) + "'" : "Non displayable") << std::endl;
			std::cout << "int: " << static_cast<int>(f) << std::endl;
			std::cout << std::fixed << std::setprecision(1);
			std::cout << "float: " << static_cast<float>(f) << "f\n";
			std::cout << "double: " << f << std::endl;
			return;
		}
	}
	std::cout << "Invalid literal\n";
}
