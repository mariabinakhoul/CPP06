#include "Base.h"
#include <cstdlib>
#include <iostream>

Base::~Base() {}

Base	*gen(void)
{
	int	rand;
	srand(time(0));
	rand = std::rand() % 3;

	switch (rand)
	{
		case 0:
			return new A;
		case 1:
			return new B;
		default:
			return new C;
	}
}

void	identify(Base *ptr)
{
	if (dynamic_cast<A *>(ptr))
	{
		std::cout << "(PTR) Type is ------->";
		std::cout <<  " | A |"  << std::endl;
	}
	else if (dynamic_cast<B *>(ptr))
	{
		std::cout << "(PTR) Type is ------->";
		std::cout <<  " | B |"  << std::endl;
	}
	else if (dynamic_cast<C *>(ptr))
	{
		std::cout << "(PTR) Type is -------->";
		std::cout <<  " | C |"  << std::endl;
	}
	else
		std::cout <<  "Yeah, we dont have that here"  << std::endl;
}

void	identify(Base &ref)
{
	try {
		(void)dynamic_cast<A &>(ref);
		std::cout << "(REF) Type is ------->";
		std::cout <<  " | A |"  << std::endl;
	} catch (...)
	{
		try {
			(void)dynamic_cast<B &>(ref);
			std::cout << "(REF) Type is ------->";
			std::cout <<  " | B |"  << std::endl;
		} catch (...) {
			try {
				(void)dynamic_cast<C &>(ref);
				std::cout << "(REF) Type is ------->";
				std::cout <<  " | C |"  << std::endl;
			} catch (...){
				std::cout << "Yeah, we dont have that here";
			}
		}
	}
}