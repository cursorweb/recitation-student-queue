// clang-format off
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
//  Written By : Student Name                    Environment : ubuntu:bionic               //
//  Date ......: 2023/06/02                      Compiler ...: clang++                  //
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
// clang-format on

///////////////////////////////////////////////////////////////////////////////
//                             Framework Set-up //
///////////////////////////////////////////////////////////////////////////////
#ifdef CATCH_CONFIG_MAIN
#  undef CATCH_CONFIG_MAIN
#endif
#include "catch.hpp"

///////////////////////////////////////////////////////////////////////////////
//                                 Includes //
///////////////////////////////////////////////////////////////////////////////
#include <stdexcept>

///////////////////////////////////////////////////////////////////////////////
//                             Helpers/Constants //
///////////////////////////////////////////////////////////////////////////////
#include "student.hpp"
#include "student_queue.hpp"

///////////////////////////////////////////////////////////////////////////////
//                                Test Cases //
///////////////////////////////////////////////////////////////////////////////

TEST_CASE("add item", "[lol]") {
  StudentQueue q;
  q.Enqueue(Student("A", 2.0, 70.0));
  q.Enqueue(Student("B", 3.0, 80.0));
  q.Dequeue();

  REQUIRE(q.Front().GetName() == "A");
}

TEST_CASE("ass1", "[ass1]") {
  StudentQueue q;
  q.Enqueue(Student("A", 2.0, 70.0));

  StudentQueue b(q);

  REQUIRE(b.head_ != q.head_);
}

TEST_CASE("ass2", "[ass2]") {
  StudentQueue q;
  StudentQueue b(q);

  REQUIRE(b.head_ == q.head_);
}

TEST_CASE("ass3", "[ass3]") {
  StudentQueue q;
  q.Enqueue(Student("A", 1.0, 2.3));
  q.Enqueue(Student("B", 1.0, 2.3));
  q.Enqueue(Student("C", 1.0, 2.3));

  StudentQueue b(q);

  REQUIRE(b.Front().GetName() == q.Front().GetName());
}

TEST_CASE("ass4", "[ass4]") {
  StudentQueue q;
  StudentQueue b(q);

  REQUIRE(b.head_ == nullptr);
  REQUIRE(b.tail_ == nullptr);
}

TEST_CASE("ass5", "[ass5]") {
  StudentQueue q;
  q.Enqueue(Student("o", 1.0, 2.0));
  StudentQueue b(q);

  REQUIRE(b.head_ == b.tail_);
  REQUIRE(b.head_ != nullptr);
}

TEST_CASE("ass6", "[ass6]") {
  StudentQueue q;
  q.Enqueue(Student("o", 5.0, 100.0));
  q.Enqueue(Student("b", 2.0, 3.0));
  StudentQueue b(q);

  REQUIRE(b.Front().GetName() == "o");
  REQUIRE(b.tail_->student_.GetName() == "b");
}

///////////////////////////////////////////////////////////////////////////////