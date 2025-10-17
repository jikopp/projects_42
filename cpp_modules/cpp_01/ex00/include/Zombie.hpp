#pragma once
#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <string>

class Zombie {

private:
	std::string _name;
	
public:
	Zombie( const std::string& input_name );
	void announce( void );
	~Zombie();

};

void	randomChump( std::string name );
Zombie*	newZombie( std::string name );

#endif