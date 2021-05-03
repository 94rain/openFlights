#include "OpenFlight.h"
#include "algorithm/AStar.h"
#include "algorithm/BFS.h"
#include "algorithm/Dijkstra.h"
#include <iostream>
#include <vector>
using std::cout;
using std::endl;

// int main(int argc, const char * argv[]) {
int main() {
    // how to use getAjacentRoute, pass a code of an airport    
    OpenFlight o1("data/airports.csv", "data/routes.csv", "1");
    // OpenFlight o2("data/airports.csv", "data/routes.csv", "1");
    // for (unsigned i = 0; i < o2.getAdjacentRoute(o2.getStart().getID()).size();
    //      i++) {
    //   cout << o2.getAdjacentRoute(o2.getStart().getID())[i].getDest().getID()
    //        << ", " << o2.getAdjacentRoute(o2.getStart().getID())[i].getDistance()
    //        << "; ";
    // }
    // cout << d.get_distance(o2.getAirport("2962")) << endl;
    // cout << d.get_distance(o2.getAirport("2966")) << endl;
    Dijkstra c(o1);
    
    cout << c.get_distance(o1.getAirport("2966")) << endl;
    for (auto i : c.get_path(o1.getAirport("2966"))) {
      cout << i.getID() << endl;
    }
    
  
}
