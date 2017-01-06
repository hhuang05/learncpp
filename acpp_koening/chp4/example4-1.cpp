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

int main()
{
  std::vector<Student_info> students;
  Student_info record;
  std::string::size_type maxlen = 0;

  // read and store all the students data.
  // Invariant: students contains all the student records read so far
  // maxlen contains the length of the longest name in students
  while (read(cin, record)) {
    // find length of longest name
    maxlen = std::max(maxlen, record.name.size());
    students.push_back(record);
  }

  // alphabetize the student records
  sort(students.begin(), students.end(), compare);

  for (std::vector<Student_info>::size_type i = 0;
       i != students.size(); ++i) {

    // write the name, padded on the right to maxlen + 1 characters
    cout << students[i].name
         << string(maxlen + 1 - students[i].name.size(), ' ');
    
    try {
      double final_grade = grade(students[i]);
      streamsize prec = std::cout.precision();
      std::cout << setprecision(3) << final_grade << setprecision(prec);
    } catch (std::domain_error e) {
      std::cout << e.what();
    }
    std::cout << std::endl;
  }
  
  return 0;
}
