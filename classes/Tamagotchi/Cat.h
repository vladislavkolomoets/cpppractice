#ifndef CAT_H
#define CAT_H

#include <string>
#include "Tamagotchi.h"

class Cat : public Tamagotchi
{
public: 
    Cat(const std::string& _name, double _hp=0, double _happiness=0) : Tamagotchi(_name, _hp, _happiness)
    {
    }
    
    void feed() override;
    void play() override;
    void makeSound() override;
    ~Cat() override;
};

#endif // CAT_H