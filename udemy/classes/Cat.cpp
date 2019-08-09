#include "Cat.h"

// constructor
Cat::Cat(std::string name):
    m_name(name),
    m_happy(true)
{
    std::cout << ">> Cat created with name: "
              << m_name << "\n";    
}

Cat::~Cat()
{
    std::cout << ">> " << m_name << " has been destroyed\n";
}
      
void Cat::speak()
{
    std::cout << "Meow!!" << std::endl;
}
