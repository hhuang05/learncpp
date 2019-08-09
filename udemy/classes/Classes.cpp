#include <iostream>
#include <string>
#include "Cat.h"


int main()
{
    std::cout << "*** Starting program ***\n";
    {
        Cat bob("bob");
        bob.speak();
    }
    std::cout << "*** Ending program ***\n";
    return 0;
}
