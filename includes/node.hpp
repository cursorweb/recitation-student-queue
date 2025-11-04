#ifndef NODE_HPP
#define NODE_HPP

#include "student.hpp"

struct Node {
  Node(const Student& student): student_(student), next_(nullptr) {}
  Student student_;
  Node* next_ = nullptr;
};

#endif