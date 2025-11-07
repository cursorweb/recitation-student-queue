#include "student.hpp"

Student::Student(const std::string& name,
                 double gpa,
                 double attendancePercentage):
    name_(name), gpa_(gpa), attendancePercentage_(attendancePercentage) {}
std::string Student::GetName() const { return name_; }
double Student::GetGPA() const { return gpa_; }
double Student::GetAttendancePercentage() const {
  return attendancePercentage_;
}
bool Student::operator<(const Student& other) const {
  if (attendancePercentage_ == other.attendancePercentage_) {
    return gpa_ > other.gpa_;
  }

  return attendancePercentage_ < other.attendancePercentage_;
}