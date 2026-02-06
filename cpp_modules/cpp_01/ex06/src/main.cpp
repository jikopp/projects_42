#include "Harl.hpp"

int main(int ac, char **av)
{
	Harl randomInstance;

	if (ac != 2)
	{
		std::cout << "Add a single parameter for levels." << std::endl;
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return (1);
	}
	randomInstance.complain(av[1]);
	// randomInstance.complain("RANDOM"); // test if it handles error

	return (0) ;
}