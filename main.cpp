#include "OpenFlight.h"
#include "algorithm/BFS.h"
#include <iostream>
#include <vector>
#include "algorithm/Dijkstra.h"
using std::cout;
using std::endl;

//int main(int argc, const char * argv[]) {
int main() {
  // how to use getAjacentRoute, pass a code of an airport

  OpenFlight o2("data/simple_airports_3.csv", "data/simple_routes_3.csv", "1064");
  for (unsigned i = 0; i < o2.getAdjacentRoute(o2.getStart().getID()).size(); i++) {
    cout << o2.getAdjacentRoute(o2.getStart().getID())[i].getDest().getID() << ", "<< o2.getAdjacentRoute(o2.getStart().getID())[i].getDistance() << "; ";
  }
  cout << "finish" << endl;
  Dijkstra d(o2, o2.getAirport("1550"));
  cout << d.get_distance() << endl;
  Dijkstra c(o2, o2.getAirport("1064"));
  cout << c.get_distance() << endl;
  Dijkstra b(o2, o2.getAirport("302"));
  cout << b.get_distance() << endl;
  for (unsigned i = 0; i < d.get_path().size(); i++) {
    cout << d.get_path()[i].getID() << ", ";
  }
  cout<< "finish" <<endl;
}
