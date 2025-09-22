#ifndef SERIALIZER_H
# define SERIALIZER_H

#include <iomanip>
#include <iostream>
# include "Data.h"
# include <stdint.h>


class Serializer {
public:
	Serializer();
	Serializer(const Serializer &cpy);
	Serializer &operator=(const Serializer &cpy);
	virtual ~Serializer() = 0;

	static	uintptr_t	serialize(Data *ptr);
	static	Data		*deserialize(uintptr_t raw);
private:
	
};

#endif // !SERIALIZER_HPP