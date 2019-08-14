#include <stdexcept>
#include <vector>
#include "grade.h"
#include "median.h"
#include "Student_info.h"

/* 
   Compute a student's overall grade from midterm 
   and final exam grades and homeworks
 */
double grade(double midterm, double final, double homework)
{
  return 0.2 * midterm + 0.4 * final + 0.4 * homework;
}

// compute a student's overall grade from midterm and final exam grades
// and vector of homework grades.
// this function does not copy its argument, because median does so for us.
double grade(double midterm, double final, const std::vector<double>& hw)
{
  if (hw.size() == 0)
    throw std::domain_error("student has done no homework");
  return grade(midterm, final, median(hw));
}

double grade(const Student_info& s)
{
  return grade(s.midterm, s.final, s.homework);
}

double grade_aux(const Student_info& s)
{
  try {
    return grade(s);
  } catch (std::domain_error) {
    return grade(s.midterm, s.final, 0);
  }
}