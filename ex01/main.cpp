#include "Serializer.h"
#include "Data.h"
#include <cstdlib>
#include <stdlib.h>

#include <iomanip>

static int	serializer()
{
	Data	data;
	data.value = 20;
	uintptr_t x = Serializer::serialize(&data); 
	Data *ptr = Serializer::deserialize(x);
    std::cout <<"Address: " << &data << std::endl;
    std::cout << "Deserialized ptr: " << ptr << std::endl;
    std::cout << "Value: " << ptr->value << std::endl;
    if (ptr == &data)
		return (1);
    else
		return (0);
}

int main ()
{
	int	res;

	std::cout << "starting...\n";
	res = serializer();
	if (!res)
	{
		std::cout << "oops, that didn't work out" << std::endl;
		return (1);
	}
	return (0);
}