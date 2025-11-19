#include <iostream>
#include "Dog.h"

void Dog::feed()
{
    std::cout << "feeding of a dog named " << name << std::endl;
    std::cout << "hp of a dog named " << name << " is " << ++hp << std::endl;
}

void Dog::play()
{
    std::cout << "playing with a dog named " << name << std::endl;
    std::cout << "happiness of a dog named " << name << " is " << ++happiness << std::endl;
}

void Dog::makeSound()
{
    std::cout << "a dog named " << name << " just said 'woof!'" << std::endl;
}

Dog::~Dog()
{
    std::cout << "a dog named " << name << " just said 'Bye! Bye!'" << std::endl;    
}