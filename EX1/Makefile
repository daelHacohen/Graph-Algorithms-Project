CXX = g++
CXXFLAGS = -Wall -Wextra -pedantic -std=c++11

SRC = main.cpp Graph.cpp Algorithms.cpp Queue.cpp MinHeap.cpp UnionFind.cpp
EXE = bin/Main

all: Main

Main: $(SRC)
	@mkdir -p bin
	$(CXX) $(CXXFLAGS) $(SRC) -o $(EXE)

run: Main
	./$(EXE)

valgrind: Main
	valgrind --leak-check=full ./$(EXE)

valgrind-tests: test
	valgrind --leak-check=full ./bin/test

test:
	$(CXX) $(CXXFLAGS) tests.cpp Graph.cpp Algorithms.cpp Queue.cpp MinHeap.cpp UnionFind.cpp -o bin/test
	./bin/test

clean:
	rm -rf bin *.o *.out *.exe