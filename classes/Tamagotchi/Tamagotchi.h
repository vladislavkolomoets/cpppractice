#ifndef TAMAGOTCHI_H
#define TAMAGOTCHI_H

#include <string>

class Tamagotchi 
{
protected:
    std::string name{};
    double hp{};
    double happiness{};

    Tamagotchi(const std::string& _name, double _hp, double _happiness) : 
    name(_name), hp(_hp), happiness(_happiness)
    {
    }
    
public:    
    Tamagotchi() = delete;
    virtual void feed() = 0;
    virtual void play() = 0;
    virtual void makeSound() = 0;
    virtual ~Tamagotchi() = default;
};

#endif // TAMAGOTCHI_H