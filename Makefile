# Executable Name
EXENAME = openflight
TEST = test

# Object Types
OBJS = main.o OpenFlight.o Airport.o Route.o BFS.o Dijkstra.o AStar.o
OBJS_TEST =tests/catch/catchmain.cpp test_graph.o test_BFS.o test_AStar.o test_Dijkstra.o OpenFlight.o Airport.o Route.o BFS.o AStar.o Dijkstra.o

# Compilation Flags
CXX = clang++
CXXFLAGS = -std=c++1y -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++1y -stdlib=libc++ -lc++abi -lm

# Custom Clang Enforcement
include make/customClangEnforcement.mk

# Define Makefile Rules
.PHONY: all test clean output_msg

all : $(EXENAME)

output_msg: ; $(CLANG_VERSION_MSG)

$(EXENAME): output_msg $(OBJS)
	$(LD) $(OBJS) $(LDFLAGS) -o $(EXENAME)

main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp

OpenFlight.o: OpenFlight.cpp
	$(CXX) $(CXXFLAGS) OpenFlight.cpp

Airport.o: Airport.cpp
	$(CXX) $(CXXFLAGS) Airport.cpp

Route.o: Route.cpp
	$(CXX) $(CXXFLAGS) Route.cpp

BFS.o: algorithm/BFS.cpp
	$(CXX) $(CXXFLAGS) algorithm/BFS.cpp

Dijkstra.o: algorithm/Dijkstra.cpp
	$(CXX) $(CXXFLAGS) algorithm/Dijkstra.cpp

AStar.o: algorithm/AStar.cpp
	$(CXX) $(CXXFLAGS) algorithm/AStar.cpp


$(TEST): output_msg $(OBJS_TEST) 
	$(LD) $(OBJS_TEST) $(LDFLAGS) -o $(TEST)

test_graph.o : tests/test_graph.cpp 
	$(CXX) $(CXXFLAGS) tests/test_graph.cpp

test_BFS.o : tests/test_BFS.cpp 
	$(CXX) $(CXXFLAGS) tests/test_BFS.cpp

test_AStar.o : tests/test_AStar.cpp 
	$(CXX) $(CXXFLAGS) tests/test_AStar.cpp

test_Dijkstra.o : tests/test_Dijkstra.cpp 
	$(CXX) $(CXXFLAGS) tests/test_Dijkstra.cpp

clean:
	-rm -f *.o $(EXENAME) $(TEST)
