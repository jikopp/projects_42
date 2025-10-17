#include "Contact.hpp"
#include <iomanip>

// Constructor
Contact::Contact() {}

// Setters
void Contact::setFirstName(const std::string &value) { _firstName = value; }
void Contact::setLastName(const std::string &value) { _lastName = value; }
void Contact::setNickname(const std::string &value) { _nickname = value; }
void Contact::setPhoneNumber(const std::string &value) { _phoneNumber = value; }
void Contact::setDarkestSecret(const std::string &value) { _darkestSecret = value; }

// Getters
std::string Contact::getFirstName() const { return _firstName; }
std::string Contact::getLastName() const { return _lastName; }
std::string Contact::getNickname() const { return _nickname; } 
std::string Contact::getPhoneNumber() const { return _phoneNumber; }
std::string Contact::getDarkestSecret() const { return _darkestSecret; }

// Helper function to format fields if over 10 chars
static std::string formatField(const std::string &field)
{
	if (field.size() > 10)
		return (field.substr(0, 9) + ".");
	return (field);
}

// Helper fucntion to display grid, so user can chose contact info by index number.
// It prints the line as per subject, later using loop to print the grid itself.
//  0 |     Piroska |     Kiss |   Piri
void Contact::displaySummary(int index) const
{
	std::cout << std::setw(10) << index << " | "
			  << std::setw(10) << formatField(_firstName) << " | "
			  << std::setw(10) << formatField(_lastName) << " | "
			  << std::setw(10) << formatField(_nickname) << std::endl;
}

// Display the chosen contact information
void Contact::displayFull()	const
{
	std::cout << "First Name: " << _firstName << std::endl;
	std::cout << "Last Name: " << _lastName << std::endl;
	std::cout << "Nickname: " << _nickname << std::endl;
	std::cout << "Phone Number: " << _phoneNumber << std::endl;
	std::cout << "Darkest Secret: " << _darkestSecret << std::endl;
}
