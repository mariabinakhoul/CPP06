#include "Base.h"

int main (void)
{
	Base *hello = gen();

	identify(hello);
	identify(*hello);

	delete hello;
	return 0;
}