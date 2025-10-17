#include "../include/Zombie.hpp"

int main()
{
	Zombie* Zipper = newZombie("Zipper");
	Zipper->announce();
	randomChump("Ash");
	// std::cout << "Ash deleted earlier, because the destructor was called as soon as the function random Chimp() has finished execution." << std::endl;
	delete Zipper;
	return (0) ;
}