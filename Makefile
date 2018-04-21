# Test Environment: gcc version 5.2.1, Windows 10

demo-test: test/catch.hpp test/demo.cpp
	@g++ -std=c++11 -o test/demo test/demo.cpp && ./test/demo

json-test: test/catch.hpp test/json.cpp db/json.hpp
	@g++ -std=c++11 -o test/json test/json.cpp && ./test/json

btree-test: test/catch.hpp test/btree.cpp db/json.hpp db/btree.hpp
	@g++ -std=c++11 -o test/btree test/btree.cpp && ./test/btree
