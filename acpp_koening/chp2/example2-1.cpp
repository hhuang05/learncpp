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
  const int rowpad = 1;
  const int colpad = 5;
  const int rows = rowpad * 2 + 3;

  // separate output from input
  std::cout << std::endl;

  // Type to use for size of string
  const std::string::size_type cols = greeting.size() + colpad * 2 + 2;
  
  // write rows of output
  for (int r = 0; r != rows; ++r) {

    std::string::size_type c = 0;
    
    // invariant: we have written c characters so far in the current row    
    while (c != cols) {
      
      // If we are writing the message
      if (r == rowpad+1 && c == colpad+1) {
        std::cout << greeting;
        c += greeting.size();
      } else {
        // If we are on the border
        if (r == 0 || r == rows-1 || c == 0 || c == cols-1) {
          std::cout << "*"; //Yes, write *
          ++c; 
        } else {         // If we are NOT on the border
          if (r != rowpad+1) {
            std::string spaces(cols-2, ' ');
            std::cout << spaces;
            c += spaces.size();;
          } else { //Now we're on the message row
            std::string spaces(colpad, ' ');
            std::cout << spaces;
            c += spaces.size();;
          }
        }
      }      
    }

    std::cout << std::endl;
  }
  
  return 0;
}
