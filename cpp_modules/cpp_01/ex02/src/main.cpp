#include <string>
#include <iostream>


int main()
{
	/*------INIT------*/
	//A string variable initialized to "HI THIS IS BRAIN"
	std::string str = "HI THIS IS BRAIN";
	
	//stringPTR: a pointer to the string.
	std::string* stringPTR = &str;
	
	// stringREF: a reference to the string
	std::string& stringREF = str;

	/*------PRINT ADDRESS------*/
	std::cout << "str memory address: " << &str << std::endl;
	std::cout << "stringPTR  address: " << stringPTR << std::endl;
	std::cout << "stringREF  address: " << &stringREF << std::endl;
	
	/*------PRINT VALUE------*/
	std::cout << "str       value: " << str << std::endl;
	std::cout << "stringPTR value: " << *stringPTR << std::endl;
	std::cout << "stringREF value: " << stringREF << std::endl;

	return (0) ;
}