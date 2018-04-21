# Test Environment: gcc version 5.2.1, Windows 10

demo: test/catch.hpp test/demo.cpp
	@g++ -std=c++11 -o test/demo test/demo.cpp && ./test/demo
