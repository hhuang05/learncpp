/* 5-11. In text processing it is sometimes useful to know whether a word has any
   ascenders or descenders. Ascenders are the parts of lowercase letters that extend above
   the text line; in the English alphabet, the letters b, d, f, h, k, l, and t have ascenders.
   Similarly, the descenders are the parts of lowercase letters that descend below the line;
   In English, the letters g, j, p, q, and y have descenders. 

   1. Write a program to determine whether a word has any ascenders or descenders. 

   2. Extend that program to find thelongest word in the dictionary that has neither ascenders nor descenders.
*/

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <locale>

int countAscDesc(const std::string& s, const std::set<char>& dict)
{
  int count = 0;
  for (std::string::const_iterator it = s.begin();
       it != s.end(); ++it) {
    if (dict.find(*it) != dict.end())
      count++;
  }
  return count;
}

std::istream& readInput(std::istream& in, std::vector<std::string>& words)
{
  if (in) {
    // get rid of previous contents
    words.clear() ;
    // read homework grades
    std::string s;
    std::locale loc;
    while (in >> s) {
      std::string::const_iterator it = s.begin();
      if (std::islower(*it, loc))        
        words.push_back(s);
    }
    // clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}

void findAscDesc()
{
  std::set<char> ascenders;
  std::set<char> descenders;
  
  ascenders.insert('b');
  ascenders.insert('d');
  ascenders.insert('f');
  ascenders.insert('h');
  ascenders.insert('k');
  ascenders.insert('l');
  ascenders.insert('t');

  descenders.insert('g');
  descenders.insert('j');
  descenders.insert('p');
  descenders.insert('q');
  descenders.insert('y');

  std::vector<std::string> words;
  readInput(std::cin, words);

  std::string::size_type maxlen = 0;
  std::string longestword;
  
  for (std::vector<std::string>::const_iterator it = words.begin();
       it != words.end(); ++it) {

    int numAsc = countAscDesc(*it, ascenders);
    int numDesc = countAscDesc(*it, descenders);
    // std::cout << "Asc: " << numAsc;
    // std::cout << "  Desc: " << numDesc;
    // std::cout << "   " << *it  << std::endl;

    if (numAsc == 0 && numDesc == 0 && it->size() > maxlen) {
      maxlen = it->size();
      longestword = *it;
    }
  }

  std::cout << "Longest word w/o. asc and desc is: " << longestword
            << " at length of " << maxlen << std::endl;
}

bool isPalindrome(const std::string& s)
{
  // If even numbers, will go one past mid, if odd number of characters,
  // we will hit mid exactly
  int mid = s.size() /2; 

  std::string::const_iterator s_it = s.begin();
  std::string::const_reverse_iterator s_revit = s.rbegin();

  int index = 0;

  while (index != mid) {
    if (*s_it != *s_revit) {
      return false;
    } else {
      ++s_it;
      ++s_revit;
      ++index;
    }
  }
  
  return true;
}

bool is_palindrome(const std::string& s)
{
  return std::equal(s.begin(), s.end(), s.rbegin());
}

void findPalindrome()
{
  std::vector<std::string> words;
  readInput(std::cin, words);

  // Iterate over each word and check if it is a palindrome
  for (std::vector<std::string>::const_iterator it = words.begin();
       it != words.end(); ++it) {
    if (is_palindrome(*it)) {
      std::cout << "Length: " << it->size() << "   " << *it << std::endl;
    }
  }
}



int main()
{
  //findAscDesc();
  findPalindrome();
  return 0;
}
