#pragma once
#include <iostream>
#include <string>

class Contact
{
private:
	std::string _firstName;
	std::string _lastName;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;

public:
	Contact();

	void setFirstName(const std::string &value);
	void setLastName(const std::string &value);
	void setNickname(const std::string &value);
	void setPhoneNumber(const std::string &value);
	void setDarkestSecret(const std::string &value);

	std::string getFirstName() const;
	std::string getLastName() const;
	std::string getNickname() const;
	std::string getPhoneNumber() const;
	std::string getDarkestSecret() const;
	
	void displaySummary(int index) const;
	void displayFull() const;
};