#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <iostream>

#include "node.hpp"

class StudentQueue {
public:
  StudentQueue() = default;
  ~StudentQueue();
  StudentQueue(const StudentQueue&);
  StudentQueue& operator=(const StudentQueue&);
  void Enqueue(const Student& student);
  void Dequeue();
  Student Front() const;
  void Display() const;

private:
  Node* head_ = nullptr;
  Node* tail_ = nullptr;
  void Clear();
};

#endif