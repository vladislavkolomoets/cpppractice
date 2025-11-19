#include <iostream>
#include <vector>
#include <string>
#include <memory>

#include "Cat.h"
#include "Dog.h"
#include "Fish.h"

int main()
{
    std::vector<std::unique_ptr<Tamagotchi>> creatures{};
    creatures.push_back(std::make_unique<Cat>("Murzik"));
    creatures.push_back(std::make_unique<Dog>("Sharik"));
    creatures.push_back(std::make_unique<Fish>("Nemo"));
    
    for (const auto& creature : creatures) 
    {
        creature->feed();
        creature->play();
        creature->makeSound();
        std::cout << std::endl;
    }
    
    return 0;
}