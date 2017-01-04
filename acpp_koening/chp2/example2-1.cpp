// Asks for a person's name, and greet the person
#include <iostream>
#include <string>

int main()
{
  // Asks for the person's name
  std::cout << "Please enter your first name: ";

  std::string name; //Define name
  std::cin >> name; //Read into

  // Build message that we intend to write
  const std::string greeting = "Hello, " + name + "!";

  // Have to rewrite
  // Number of blanks surrounding greeting
  const int pad = 1;
  const int rows = pad * 2 + 3;

  // separate output from input
  std::cout << std::endl;

  // write rows of output
  int r = 0;

  while (r != rows) {
    std::cout << "rows:" << r <<std::endl;
    ++r;
  }
  
  return 0;
}
