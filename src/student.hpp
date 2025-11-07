#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>

class Student {
public:
  Student(const std::string& name, double gpa, double attendancePercentage);
  std::string GetName() const;
  double GetGPA() const;
  double GetAttendancePercentage() const;
  bool operator<(const Student& other) const;

private:
  std::string name_;
  double gpa_ = 0.0;
  double attendancePercentage_ = 0.0;
};

#endif
