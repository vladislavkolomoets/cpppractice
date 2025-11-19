#ifndef FISH_H
#define FISH_H

#include <string>
#include "Tamagotchi.h"

class Fish : public Tamagotchi
{
public: 
    Fish(const std::string& _name, double _hp=0, double _happiness=0) : Tamagotchi(_name, _hp, _happiness)
    {
    }

    void feed() override;
    void play() override;
    void makeSound() override;
    ~Fish() override;
};

#endif // FISH_H