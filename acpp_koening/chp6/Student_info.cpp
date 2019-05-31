#include "Student_info.h"
#include <algorithm>

bool compare(const Student_info& x, const Student_info& y)
{
  return x.name < y.name;
}

std::istream& read(std::istream& is , Student_info& s)
{
  // read and store the student's name and midterm and final exam grades
  is >> s.name >> s.midterm >> s.final;
  read_hw(is, s.homework);
  return is;
  // read and store all the student's homework grades
}

std::istream& read_hw(std::istream& in, std::vector<double>& hw)
{
  if (in) {
    // get rid of previous contents
    hw.clear() ;
    // read homework grades
    double x;
    while (in >> x)
      hw.push_back(x);
    // clear the stream so that input will work for the next student
    in.clear();
  }
  return in;
}

bool did_all_hw(const Student_info& s)
{
  return (std::find(s.homework.begin(), s.homework.end(), 0) == s.homework.end());
}
