#include "HumanB.hpp"

HumanB::HumanB( const std::string& name ) : _name(name), _weapon(NULL) {}

void HumanB::setWeapon( Weapon& newWeapon ) { this->_weapon = &newWeapon; }

void HumanB::attack() const
{
	if (this->_weapon)
		std::cout << this->_name <<
			" attacks with their " <<
			this->_weapon->getType() <<
			std::endl;
	else
		std::cout << this->_name <<
			" has no weapon to attack with!" <<
			std::endl;
}
