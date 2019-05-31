#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;
using std::vector;

double median_analysis(const vector<Student_info>& students)
{
  vector<double> grades;

  std::transform(students.begin(), students.end(),
                 std::back_inserter(grades), grade_aux);
  return median(grades);
}

int main()
{
  vector<Student_info> did, didnt;
  Student_info student;

  while (read(cin, student)) {
    if (did_all_hw(student))
      did.push_back(student);
    else
      didnt.push_back(student);
  }

  cout << "These students did all the homework" << endl;
  for (vector<Student_info>::const_iterator it = did.begin(); it != did.end(); ++it) {
    cout << it->name << endl;
  }
  
  cout << endl;
  cout << "These students DID NOT do all the homework" << endl;
  for (vector<Student_info>::const_iterator it = didnt.begin();
       it != didnt.end(); ++it) {
    cout << it->name << endl;
  }
  return 0;
}
