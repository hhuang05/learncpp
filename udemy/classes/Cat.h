/* Cat.h
 */

#ifndef CAT_H_
#define CAT_H_

#include <iostream>
#include <string>

class Cat
{
public:
    
    Cat(std::string name); // constructor
    ~Cat();
    
    void speak();
    
private:
    std::string m_name;
    bool m_happy;
};


#endif /* CAT_H_ */
