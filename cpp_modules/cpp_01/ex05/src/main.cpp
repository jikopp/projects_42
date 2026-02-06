#include "Harl.hpp"

int main()
{
	Harl randomInstance;

	randomInstance.complain("DEBUG");
    randomInstance.complain("INFO");
    randomInstance.complain("WARNING");
    randomInstance.complain("ERROR");
    // randomInstance.complain("RANDOM"); // test if it handles error

	return (0) ;
}