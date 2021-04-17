#include "OpenFlight.h"
#include "algorithm/BFS.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

//int main(int argc, const char * argv[]) {
int main() {
  // how to use getAjacentRoute, pass a code of an airport

//   OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "1");
  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "6156");
  BFS s;
  auto path = s.getPath(o1);
  cout << s.getCount() << endl;
  for (auto p : path) {
    cout << p.getName() << endl;
  }
}
