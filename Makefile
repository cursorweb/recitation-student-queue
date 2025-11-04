CXX=clang++
INCLUDES=-Iincludes/
CXXFLAGS=-std=c++20 -gdwarf-4 -Wall -Wextra -pedantic -fsanitize=address,null -Wno-error=unused $(INCLUDES)

exec: bin/exec
tests: bin/tests

bin/exec: ./src/driver.cc ./includes/student.hpp ./src/student.cc ./includes/student_queue.hpp ./src/student_queue.cc ./includes/node.hpp
	$(CXX) $(CXXFLAGS) ./src/driver.cc ./src/student.cc ./src/student_queue.cc -o $@

bin/tests: obj/catch_main.o ./tests/tests.cc ./includes/student.hpp ./src/student.cc ./includes/student_queue.hpp ./src/student_queue.cc ./includes/node.hpp
	$(CXX) $(CXXFLAGS) obj/catch_main.o ./tests/tests.cc ./src/student.cc ./src/student_queue.cc -o $@

obj/catch_main.o: ./tests/catch.cc ./tests/catch.hpp
	$(CXX) $(CXX_FLAGS) -c ./tests/catch.cc -o $@

.DEFAULT_GOAL := exec
.PHONY: clean exec tests

clean:
	rm -fr bin/* obj/*