#include "student_queue.hpp"

int main() {
  StudentQueue old_queue = StudentQueue();  // Enqueue
  old_queue.Enqueue(Student("Martha", 2.0, 70.0));
  old_queue.Enqueue(Student("Steven", 3.5, 75.5));
  old_queue.Display();
  std::cout << "################################" << std::endl;
  StudentQueue new_queue = StudentQueue();
  new_queue.Enqueue(Student("Georges", 3.0, 95.0));  // Enqueue
  new_queue.Enqueue(Student("Ryan", 3.8, 75.5));
  new_queue.Enqueue(Student("Steven", 3.8, 65.5));
  new_queue.Display();
  std::cout << "################################" << std::endl;
  old_queue = new_queue;  // Copy Assignment
  old_queue.Display();
  std::cout << "################################" << std::endl;
  StudentQueue queue = StudentQueue(new_queue);  // Copy Constructor
  queue.Display();
  std::cout << "################################" << std::endl;
  return 0;
}