#pragma once
#include "Contact.hpp"

class PhoneBook
{
private:
	Contact _contacts[8];
	int _contactCount;
	int _oldestIndex;
	void _displayHeader() const;
	std::string promptNonEmptyField(const std::string &prompt);

public:
	PhoneBook();
	void addContact();
	void searchContact() const;

};