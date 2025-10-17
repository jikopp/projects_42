#include <iostream>
#include <string>
#include <fstream>

// void print_input(std::string filename, std::string s1, std::string s2)
// {
	
// 	// ---------------------------------
// 	std::cout << "----------------------------------------------------" << std::endl << std::endl;
// 	std::cout << "INPUTS: " << std::endl;
// 	std::cout << "- " << filename << std::endl;
// 	std::cout << "- " << s1 << std::endl;
// 	std::cout << "- " << s2 << std::endl;
// 	std::cout << std::endl << "----------------------------------------------------" << std::endl << std::endl;
// 	// ---------------------------------
// }

void replace_str(std::fstream& inFile, const std::string& s1, const std::string& s2, std::ofstream& outFile)
{
	std::string line;
	while(std::getline(inFile, line))
	{
		std::string new_string;
		std::size_t pos = 0;
		std::size_t found;

		while((found = line.find(s1, pos)) != std::string::npos)
		{
			// first append "new_string" until the first match
			new_string += line.substr(pos, found - pos);

			// use temp for swapping
			std::string temp = s2;

			// append s2 from postion of first match in "new_string"
			new_string.append(temp.begin(), temp.end());

			// update position to carry with the search after the first match
			// (found equal s1[0], first char of s1, + size to reach the last char of s1)
			pos = found + s1.size();

		}
		// add the remaining string after the last match in the line
		new_string += line.substr(pos);
		outFile << new_string << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
	{
		std::cout << "Please add the following argumetns: " << std::endl;
		std::cout << "--Filename--  --Old str--  --New str--" << std::endl;
		return (1) ;
		
	}
	const std::string filename = av[1];
	const std::string s1 = av[2];
	const std::string s2 = av[3];
	
	if (s1.empty())
	{
		std::cout << "s1 string cannot be empty." << std::endl;
		return (1) ;
	}
		
	// TEST PRINT
	// print_input(filename, s1, s2);

	std::fstream inFile(filename.c_str(), std::ios::in);	
	if (!inFile.is_open())
	{	
		std::cout << "Error reading the file. Yes, it is your fault." << std::endl;
		return (1) ;
	}

	const std::string outFilename = filename + ".replace";
	std::ofstream outFile(outFilename.c_str());
	if (!outFile.is_open())
	{	
		std::cout << "Error creating the output file. Yes, it is your fault." << std::endl;
		inFile.close();
		return (1) ;
	}

	// use .find and .swap in a loop, .replace is not allowed
	replace_str(inFile, s1, s2, outFile);

	inFile.close();
	outFile.close();

	std::cout << "\nReplacement complete.\nOutput file: " <<
		outFilename << std::endl << std::endl;

	return (0);
}