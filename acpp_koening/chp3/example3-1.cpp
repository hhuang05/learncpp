#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::setprecision;
using std::string;
using std::streamsize;

typedef std::vector<double>::size_type vec_sz;

int main()
{
  // ask for and read the student's name
  cout << "Please enter your first name: ";
  string name;
  cin >> name;
  cout << "Hello, " << name << "!" << endl;

  // ask for and read the midterm and final grades
  cout << "Please enter your midterm and final exam grades: ";

  double midterm, final;
  cin >> midterm >> final;

  // ask for the homework grades
  cout << "Enter all your homework grades, "
          "followed by end-of-file: ";
  
  // the number and sum of grades read so far
  int count = 0;
  std::vector<double> hwgrades;

  // a variable into which to read
  double x;
  
  // invariant:  
  // we have read count grades so far, and
  // sum is the sum of the first count grades
  while (cin >> x) {
    ++count;
    hwgrades.emplace_back(x);
  }

  vec_sz size = hwgrades.size();
  if (size == 0) {
    std::cout << std::endl << "You must enter you grades.  "
      "Please try again." << std::endl;
    return 1;
  }

  // Sorts in place the hwgrades vector
  std::sort(hwgrades.begin(), hwgrades.end());

  //Calculate median
  vec_sz mid = size/2;
  double median;
  median = size % 2 == 0 ? (hwgrades[mid] + hwgrades[mid-1]) / 2
                         : hwgrades[mid];
  

  // write the result
  streamsize prec = cout.precision();
  cout << "Your final grade is " << setprecision(3)
       << 0.2 * midterm + 0.4 * final + 0.4 * median
       << setprecision(prec) << endl;
  
  return 0;
}
