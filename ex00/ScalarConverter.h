#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <iostream>

class ScalarConverter
{
	public:
	ScalarConverter();
	ScalarConverter(const ScalarConverter&);
	ScalarConverter &operator=(const ScalarConverter &);
	virtual ~ScalarConverter() = 0;
	static void converter(const std::string &);
};

#endif