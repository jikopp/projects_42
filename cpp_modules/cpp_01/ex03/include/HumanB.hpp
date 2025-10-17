#pragma once
#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB {

private:
	std::string _name;
	Weapon* 	_weapon;

public:
	HumanB( const std::string& name) ;
	void setWeapon( Weapon& newWeapon );
	void attack() const;
};

#endif