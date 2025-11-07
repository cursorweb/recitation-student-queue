#include "student_queue.hpp"

void StudentQueue::Enqueue(const Student& student) {
  Node* s = new Node(student);

  if (head_ == nullptr) {
    head_ = tail_ = s;
    return;
  }

  Node* prev = nullptr;
  Node* node = head_;
  while (node != nullptr && s->student_ < node->student_) {
    prev = node;
    node = node->next_;
  }

  if (prev == nullptr) {
    s->next_ = head_;
    head_ = s;
  } else if (node == nullptr) {
    tail_->next_ = s;
    tail_ = s;
  } else {
    prev->next_ = s;
    s->next_ = node;
  }
}

void StudentQueue::Dequeue() {
  if (head_ == nullptr) {
    return;
  }

  Node* out = head_;
  head_ = head_->next_;

  // if its empty then also set tail
  if (head_ == nullptr) {
    tail_ = nullptr;
  }

  delete out;
}

StudentQueue::StudentQueue(const StudentQueue& other) {
  if (other.head_ == nullptr) {
    return;
  }

  head_ = new Node(other.head_->student_);
  Node* tstart = head_;
  Node* ostart = other.head_->next_;

  while (ostart != nullptr) {
    tstart->next_ = new Node(ostart->student_);
    ostart = ostart->next_;
    tstart = tstart->next_;
  }

  tail_ = tstart;
}

StudentQueue& StudentQueue::operator=(const StudentQueue& other) {
  if (this == &other) return *this;

  Clear();

  if (other.head_ == nullptr) {
    return *this;
  }

  head_ = new Node(other.head_->student_);
  Node* tstart = head_;
  Node* ostart = other.head_->next_;

  while (ostart != nullptr) {
    tstart->next_ = new Node(ostart->student_);
    ostart = ostart->next_;
    tstart = tstart->next_;
  }

  tail_ = tstart;

  return *this;
}

StudentQueue::~StudentQueue() { Clear(); }

void StudentQueue::Clear() {
  while (head_ != nullptr) {
    Node* temp = head_;
    head_ = head_->next_;
    delete temp;
  }

  tail_ = nullptr;
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