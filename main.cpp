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

  OpenFlight o2("data/airports.csv", "data/routes.csv", "2965");
  // OpenFlight o2("data/airports.csv", "data/routes.csv", "1");
  //for (unsigned i = 0; i < o2.getAdjacentRoute(o2.getStart().getID()).size(); i++) {
    //cout << o2.getAdjacentRoute(o2.getStart().getID())[i].getDest().getID() << ", "<< o2.getAdjacentRoute(o2.getStart().getID())[i].getDistance() << "; ";
  //}
  cout << "finish" << endl;
  Dijkstra d(o2, o2.getAirport("3400"));
  cout << "finish constructing" << endl;
  cout << d.get_distance() << endl;
  //cout << d.get_distance(o2.getAirport("2962")) << endl;
  //cout << d.get_distance(o2.getAirport("2966")) << endl;
  //Dijkstra c(o2, o2.getAirport("1"));
  //cout << c.get_distance(o2.getAirport("2")) << endl;
  for (unsigned i = 0; i < d.get_path().size(); i++) {
    cout << d.get_path()[i].getID() << ", ";
  }
  cout<< "finish" <<endl;
  
    

}
