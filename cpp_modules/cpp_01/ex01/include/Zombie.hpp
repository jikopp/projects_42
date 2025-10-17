#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>

class Zombie {

private:
	std::string _name;
	
public:
	Zombie();
	void announce();
	void setZombieName( const std::string& input_name );
	~Zombie();

};

Zombie* zombieHorde( int N, std::string name );

#endif