#include "../include/Zombie.hpp"

// Constructor
Zombie::Zombie( const std::string& input_name )
{
	this->_name = input_name;
}

void Zombie::announce()
{
	std::cout << this->_name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// Destructor
Zombie::~Zombie()
{
	 std::cout << this->_name << " destroyed" << std::endl;
}
