#include "PhoneBook.hpp"
#include "Contact.hpp"

int	main()
{
	PhoneBook	phonebook;
	std::string	user_command;

	std::cout << "Welcome to my crappy PhoneBook!" << std:: endl;
	std::cout << "You can use the following commands:" << std:: endl;
	std::cout << "ADD, SEARCH, EXIT." << std:: endl;
	while (1)
	{
		std::cout << ">> ";
		if (!std::getline(std::cin, user_command))
			break;
		if (user_command == "ADD")
			phonebook.addContact();
		else if (user_command == "SEARCH")
			phonebook.searchContact();
		else if (user_command == "EXIT")
			break;
		else
			std::cout << "Unkown command, type ADD, SEARCH or EXIT." << std:: endl;
	}
	std::cout << "Thank you for using my crappy phone book. Bye!" << std:: endl;
	return (0);
}
