#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>
#include <vector>
#include <locale>

static std::locale loc;

// true if the argument is whitespace, false otherwise
bool space(char c)
{
  return std::isspace(c, loc);
}

// false if the argument is whitespace, true otherwise
bool not_space(char c)
{
  return !std::isspace(c, loc);
}

std::vector<std::string> split(const std::string& str)
{
  typedef std::string::const_iterator iter;
  std::vector<std::string> ret;

  iter i = str.begin();
  while (i != str.end()) {
    // ignore leading blanks
    // Find first index in string in which it is not a space
    i = std::find_if(i, str.end(), not_space);
    // find end of next word
    // First first index in the remaining string in which a space occurs
    iter j = std::find_if(i, str.end(), space);
    // copy the characters in [i, j)
    if (i != str.end())
      ret.push_back(std::string(i, j));
    i = j;
  }
  return ret;
}

int main()
{
  std::string test = "This is a test. Let's see if this works!";
  std::vector<std::string> words = split(test);
  
  for(std::vector<std::string>::const_iterator it = words.begin();
      it != words.end(); ++it) {
    std::cout << *it << std::endl;
  }

  return 0;
}
