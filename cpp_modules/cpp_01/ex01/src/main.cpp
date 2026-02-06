#include "Zombie.hpp"

int main()
{
    int n = 5;
    Zombie *Zipper = zombieHorde(n, "Zipper");

    // test if fucntion worked with calling announce
    for (int i = 0; i < n; i++)
        Zipper[i].announce();
        
    // destroy the array of zombies []
    delete[] Zipper;
    return (0) ;
}