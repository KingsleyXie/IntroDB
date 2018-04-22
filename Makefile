# Test Environment: gcc version 5.2.1, Windows 10
C = g++ -O2 -Wall -std=c++11

demo-test: tests/catch.hpp tests/demo.cpp
	@$(C) -o tests/demo tests/demo.cpp && ./tests/demo

json-test: tests/catch.hpp tests/json.cpp db/json.hpp
	@$(C) -o tests/json tests/json.cpp && ./tests/json

btree-test: tests/catch.hpp tests/btree.cpp db/json.hpp db/btree.hpp
	@$(C) -o tests/btree db/btree.hpp tests/btree.cpp && ./tests/btree
