# Executable Name
EXENAME = openflight
TEST = test
# Object Types
OBJS = main.o Openflight.o Airport.o Route.o BFS.o Dijkstra.o PageRank.o
OBJS_TEST =tests/catch/catchmain.cpp test_BFS.o test_PageRank.o test_Dijkstra.o Openflight.o Airport.o Route.o BFS.o PageRank.o Dijkstra.o
# Compilation Flags
CXX = clang++
CXXFLAGS = -std=c++14 -stdlib=libc++ -c -g -O0 -Wall -Wextra -pedantic
LD = clang++
LDFLAGS = -std=c++14 -stdlib=libc++ -lc++abi -lm

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

Openflight.o: Openflight.cpp
	$(CXX) $(CXXFLAGS) Openflight.cpp

Airport.o: Airport.cpp
	$(CXX) $(CXXFLAGS) Airport.cpp

Route.o: Route.cpp
	$(CXX) $(CXXFLAGS) Route.cpp

BFS.o: algorithm/BFS.cpp
	$(CXX) $(CXXFLAGS) algorithm/BFS.cpp

Dijkstra.o: algorithm/Dijkstra.cpp
	$(CXX) $(CXXFLAGS) algorithm/Dijkstra.cpp

PageRank.o: algorithm/PageRank.cpp
	$(CXX) $(CXXFLAGS) algorithm/PageRank.cpp


$(TEST): output_msg $(OBJS_TEST) 
	$(LD) $(OBJS_TEST) $(LDFLAGS) -o $(TEST)

test_BFS.o : tests/test_BFS.cpp 
	$(CXX) $(CXXFLAGS) tests/test_BFS.cpp

test_PageRank.o : tests/test_PageRank.cpp 
	$(CXX) $(CXXFLAGS) tests/test_PageRank.cpp

test_Dijkstra.o : tests/test_Dijkstra.cpp 
	$(CXX) $(CXXFLAGS) tests/test_Dijkstra.cpp

clean:
	-rm -f *.o $(EXENAME) $(TEST)
