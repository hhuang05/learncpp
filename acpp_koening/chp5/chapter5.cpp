// Splits a string

#include <cctype>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using std::string;
using std::vector;

string& pad_string(string& s, bool is_border=false)
{
  if (is_border) {
    s = "**" + s + "**";
  } else {
    s = "* " + s + " *";
  }

  return s;
}


// Takes in a vector of strings of the message to write
// Outputs the message with frame
vector<string> frame(const vector<string>& s)
{
  vector<string> ret;
  string::size_type max_len = 0;
  vector<string>::const_iterator read_it;
  
  // 1. Find length of longest string in vector
  for (read_it = s.begin(); read_it != s.end(); ++read_it) {
    if (read_it->size() > max_len) {
      max_len = read_it->size();
    }
  }

  // reprocess the input vector to pad appropriately.
  // left spacing is one space, right space is whatever is left over

  // Obvious
  string border_str = string(max_len, '*');
  string border = pad_string(border_str, true);
  ret.emplace_back(border);
  
  unsigned int num_spaces = 0;
  for (read_it = s.begin(); read_it != s.end(); ++read_it) {
    string newstring(*read_it);
    if (newstring.size() < max_len) {
      string::size_type pad_size = max_len-newstring.size();
      string pad = string(pad_size, ' ');
      newstring += pad; //pad on right      
    }
    
    ret.emplace_back(pad_string(newstring));
  }

  ret.emplace_back(border);
  return ret;
}

vector<string> split(const string& s)
{
  vector<string> ret;
  typedef string::size_type string_size;
  string_size i = 0;

  while (i != s.size()) {
    //ignore leading spaces
    while (i != s.size() && isspace(s[i]))
      ++i;

    string_size j = i;
    while (j != s.size() && !isspace(s[j]))
      j++;

    if (i != j) {
      ret.push_back(s.substr(i, j-i));
      i=j;
    }    
  }
  
  return ret;
}

int main()
{
  std::string s;
  // read and split each line of input
  while (getline(std::cin, s)) {
    vector<string> v = split(s);
    vector<string> retval = frame(v);

    for (vector<string>::const_iterator cit = retval.begin();
         cit != retval.end(); ++cit) {
      std::cout << *cit << std::endl;
    }
  }
  return 0;  
}
