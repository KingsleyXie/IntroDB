# Test Environment: gcc version 5.2.1, Windows 10

hw: hw.cpp
	@g++ -o hw hw.cpp && ./hw

demo: demo.cpp
	@g++ -std=c++11 -o demo demo.cpp && ./demo
