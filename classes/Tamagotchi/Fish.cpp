#include <iostream>
#include "Fish.h"

void Fish::feed()
{
    std::cout << "feeding of a fish named " << name << std::endl;
    std::cout << "hp of a fish named " << name << " is " << ++hp << std::endl;
}

void Fish::play()
{
    std::cout << "playing with a fish named " << name << std::endl;
    std::cout << "happiness of a fish named " << name << " is " << ++happiness << std::endl;
}

void Fish::makeSound()
{
    std::cout << "a fish named " << name << " just said 'dam!'" << std::endl;
}

Fish::~Fish()
{
    std::cout << "a fish named " << name << " just said 'Bye! Bye!'" << std::endl;    
}