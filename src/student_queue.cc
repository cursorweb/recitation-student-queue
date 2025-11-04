#include "student_queue.hpp"

void StudentQueue::Enqueue(const Student& student) {
  Node* n = new Node(student);
  std::cout << n->student_.GetAttendancePercentage();
  // TODO
}
void StudentQueue::Dequeue() {
  // TODO
}
StudentQueue::StudentQueue(const StudentQueue& other) {
  // TODO
}
StudentQueue& StudentQueue::operator=(const StudentQueue& other) {
  // TODO
  return *this;
}
StudentQueue::~StudentQueue() { Clear(); }

void StudentQueue::Clear() {
  // TODO
}
Student StudentQueue::Front() const {
  if (head_ == nullptr) {
    throw std::runtime_error("Queue is empty");
  }
  return head_->student_;
}
void StudentQueue::Display() const {
  Node* current = head_;
  while (current != nullptr) {
    std::cout << "--------------------------------\n";
    std::cout << "Name: " << current->student_.GetName() << '\n';
    std::cout << "GPA: " << current->student_.GetGPA() << '\n';
    std::cout << "Attendance Percentage: "
              << current->student_.GetAttendancePercentage() << '\n';
    std::cout << "--------------------------------\n";
    std::cout << "                |                \n";
    std::cout << "                |                \n";
    std::cout << "                |                \n";
    std::cout << "                V                \n";
    current = current->next_;
  }
  std::cout << "--------------------------------\n";
  std::cout << "|            nullptr           |\n";
  std::cout << "--------------------------------\n";
}