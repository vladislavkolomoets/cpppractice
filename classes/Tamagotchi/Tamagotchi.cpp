#include <iostream>
#include <string>
#include <vector>

class Tamagotchi 
{

protected:
    std::string name{};

    double hp{};
    
    double happiness{};

    Tamagotchi(const std::string& _name, double _hp=0, double _happiness=0) : name(_name), hp(_hp), happiness(_happiness)
    {}
    
public:    
    Tamagotchi() = delete;
    
    virtual void feed() = 0;
    
    virtual void play() = 0;
    
    virtual void makeSound() = 0 ;
    
    virtual ~Tamagotchi() = default;
};

class Cat : public Tamagotchi
{
public: 

    Cat(const std::string& _name, double _hp=0, double _happiness=0) : Tamagotchi(_name, _hp, _happiness)
    {}
    
    void feed()
    {
        std::cout << "feeding of a cat named " << name << std::endl;
        std::cout << "hp of a cat named " << name << " is " << ++hp << std::endl;
    }
    
    void play()
    {
        std::cout << "playing with a cat named " << name << std::endl;
        std::cout << "happiness of a cat named " << name << " is " << ++happiness << std::endl;
    }
    
    void makeSound()
    {
        std::cout << "a cat named " << name << " just said 'meow!'" << std::endl;
    }
    
    ~Cat()
    {
        std::cout << "a cat named " << name << " just said 'Bye! Bye!'" << std::endl;    
    }
};

class Dog : public Tamagotchi
{
public: 

    Dog(const std::string& _name, double _hp=0, double _happiness=0) : Tamagotchi(_name, _hp, _happiness)
    {}
    
    void feed()
    {
        std::cout << "feeding of a dog named " << name << std::endl;
        std::cout << "hp of a dog named " << name << " is " << ++hp << std::endl;
    }
    
    void play()
    {
        std::cout << "playing with a dog named " << name << std::endl;
        std::cout << "happiness of a dog named " << name << " is " << ++happiness << std::endl;
    }
    
    void makeSound()
    {
        std::cout << "a dog named " << name << " just said 'woof!'" << std::endl;
    }
    
    ~Dog()
    {
        std::cout << "a dog named " << name << " just said 'Bye! Bye!'" << std::endl;    
    }
};

class Fish : public Tamagotchi
{
public: 

    Fish(const std::string& _name, double _hp=0, double _happiness=0) : Tamagotchi(_name, _hp, _happiness)
    {}
    
    void feed()
    {
        std::cout << "feeding of a fish named " << name << std::endl;
        std::cout << "hp of a fish named " << name << " is " << ++hp << std::endl;
    }
    
    void play()
    {
        std::cout << "playing with a fish named " << name << std::endl;
        std::cout << "happiness of a fish named " << name << " is " << ++happiness << std::endl;
    }
    
    void makeSound()
    {
        std::cout << "a fish named " << name << " just said 'dam!'" << std::endl;
    }
    
    ~Fish()
    {
        std::cout << "a fish named " << name << " just said 'Bye! Bye!'" << std::endl;    
    }
};


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