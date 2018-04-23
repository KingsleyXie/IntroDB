# Test Environment: gcc version 5.2.1, Windows 10
C = g++ -std=c++11

test: demo-test json-test btree-test kvnode-test serialize-test

demo-test:
	@$(C) -o tests/demo tests/demo.cpp
	@./tests/demo

json-test:
	@$(C) -o tests/json tests/json.cpp
	@./tests/json

btree-test:
	@$(C) -o tests/btree tests/btree.cpp
	@./tests/btree

kvnode-test:
	@$(C) -o tests/kvnode tests/kvnode.cpp
	@./tests/kvnode

serialize-test:
	@$(C) -o tests/serialize tests/serialize.cpp
	@./tests/serialize
