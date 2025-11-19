#include <iostream>
#include "Cat.h"

void Cat::feed()
{
    std::cout << "feeding of a cat named " << name << std::endl;
    std::cout << "hp of a cat named " << name << " is " << ++hp << std::endl;
}

void Cat::play()
{
    std::cout << "playing with a cat named " << name << std::endl;
    std::cout << "happiness of a cat named " << name << " is " << ++happiness << std::endl;
}

void Cat::makeSound()
{
    std::cout << "a cat named " << name << " just said 'meow!'" << std::endl;
}

Cat::~Cat()
{
    std::cout << "a cat named " << name << " just said 'Bye! Bye!'" << std::endl;    
}