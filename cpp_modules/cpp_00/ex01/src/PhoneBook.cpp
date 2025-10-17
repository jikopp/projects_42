#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

PhoneBook::PhoneBook() : _contactCount(0), _oldestIndex(0) {}

std::string PhoneBook::promptNonEmptyField(const std::string &prompt)
{
	std::string input;
	while (true)
	{
		std::cout << prompt;
		if (!std::getline(std::cin, input))
		{
			std::cout << "\n>> Input ended. Why did you have to press CTRL+D???" << std::endl;
			return ("") ; // handle EOF
		}
		if (!input.empty())
			return (input) ;
		std::cout << "Field cannot be empty. Please try again." << std::endl;
	}
}

void PhoneBook::addContact()
{
	Contact &c = _contacts[_oldestIndex];
	std::string input;
	input = promptNonEmptyField("First name: ");
	if (input.empty()) return;
	c.setFirstName(input);

	input = promptNonEmptyField("Last name: ");
	if (input.empty()) return;
	c.setLastName(input);

	input = promptNonEmptyField("Nickname: ");
	if (input.empty()) return;
	c.setNickname(input);

	input = promptNonEmptyField("Phone number: ");
	if (input.empty()) return;
	c.setPhoneNumber(input);

	input = promptNonEmptyField("Darkest secret: ");
	if (input.empty()) return;
	c.setDarkestSecret(input);

	// Override old _contacts if phonebook is full (8)
	_oldestIndex = (_oldestIndex + 1) % 8;
	if (_contactCount < 8)
		_contactCount++;

	std::cout << "Contact added succesfully" << std::endl;
}

void PhoneBook::searchContact() const
{
	if (_contactCount == 0)
	{
		std::cout << "No _contacts in the phonebook" << std::endl;
		return;
	}

	_displayHeader();
	// Display _contacts line by line (in 4 columns)
	for (int i = 0; i < _contactCount; i++)
		_contacts[i].displaySummary(i);

	std::cout << "Enter the index number to view contact details." << std::endl;
	int index = -1;
	std::cin >> index;
	// Collect index number and check for invalid input
	if (!std::cin)
	{
		std::cin.clear(); // clear the flag set by failed cin
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush the buffer
		std::cout << "Invalid input :( " << std::endl;
		return ;
	}
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //flush the buffer
	if (index < 0 || index >= _contactCount)
	{
		std::cout << "Invalid index." << std::endl;
		return ;
	}
	_contacts[index].displayFull();
} 

void PhoneBook::_displayHeader() const
{
	std::cout << std::setw(10) << "Index" << " | "
			  << std::setw(10) << "First Name" << " | "
			  << std::setw(10) << "Last Name" << " | "
			  << std::setw(10) << "Nickname" << std::endl;
	std::cout << std::string(50, '-') << std::endl;
}

