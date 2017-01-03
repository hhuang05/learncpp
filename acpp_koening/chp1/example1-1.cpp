// Asks for a person's name, and greet the person
#include <iostream>
#include <string>

int main()
{
  // Asks for the person's name
  std::cout << "Please enter your first name: ";

  // Now read the name
  std::string name; //Define name
  std::cin >> name; //Read into

  // Write a greeting
  std::cout << "Hello, " << name << "!" << std::endl;
  return 0;
}
