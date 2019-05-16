// Asks for a person's name, and greet the person
#include <iostream>
#include <string>

std::string add_border(std::string input)
{
  return "*" + input + "*";
}

int main()
{
  // Asks for the person's name
  std::cout << "Please enter your first name: ";

  std::string name; //Define name
  std::cin >> name; //Read into

  // Build message that we intend to write
  const std::string greeting = "Hello, " + name + "!";

  // Accounting for padding
  const unsigned int rowpad = 2; // no of padding rows
  const unsigned int colpad = 3; // no of col spacers
  
  // Number of rows: 2 for frame, 1 for message, then have to factor in padding
  const unsigned int rows = rowpad * 2 + 3; 

  const std::string colpad_str = std::string(colpad, ' ');
  const std::string final_greeting = colpad_str + greeting + colpad_str;
  const std::string rowpad_str = std::string(final_greeting.size(), ' ');
  const std::string frame = std::string(final_greeting.size(), '*');

  for (unsigned int r = 0; r < rows; ++r) {
    if (r == 0) {
      std::cout << add_border(frame) << std::endl;
    } else if (r <= rowpad) {
      std::cout << add_border(rowpad_str) << std::endl;
    } else if (r == rowpad+1) {
      std::cout << add_border(final_greeting) << std::endl;
    } else if (r < rows-1) {
      std::cout << add_border(rowpad_str) << std::endl;
    } else {
      std::cout << add_border(frame) << std::endl;
    }
  }
  
  return 0;
}
