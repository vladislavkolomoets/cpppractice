#ifndef DOG_H
#define DOG_H

#include <string>
#include "Tamagotchi.h"

class Dog : public Tamagotchi
{
public: 
    Dog(const std::string& _name, double _hp=0, double _happiness=0) : Tamagotchi(_name, _hp, _happiness)
    {
    }
    
    void feed() override;
    void play() override;
    void makeSound() override;
    ~Dog() override;
};

#endif // DOG_H