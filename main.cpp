#include "OpenFlight.h"
#include "algorithm/AStar.h"
#include "algorithm/BFS.h"
#include "algorithm/Dijkstra.h"
#include <iostream>
#include <string>
#include <vector>
using std::cin;
using std::cout;
using std::endl;
using std::string;

// int main(int argc, const char * argv[]) {
int main() {

  string str;
  cout << "Select your algorithm from: (enter a number from 1, 2, 3) \n 1. BFS "
          "\n 2. Dijkstra \n 3. A*"
       << endl;
  while (true) {

    getline(cin, str);
    if (str == "1") {
      OpenFlight o1("data/airports.csv", "data/routes.csv", "1");
      BFS s;
      auto path = s.getPath(o1);
      for (auto i : path) {
        cout << i.getName() << endl;
      }
      break;
    } else if (str == "2") {
      OpenFlight o1("data/airports.csv", "data/routes.csv", "1");

      break;
    } else if (str == "3") {
      OpenFlight o1("data/airports.csv", "data/routes.csv", "2922");
      AStar a1;
      Airport start = o1.getStart();
      Airport end = o1.getAirport("502");
      vector<Airport> s = a1.reconstructPath(o1, start, end);
      cout << "Starting Airport is " << start.getName() << endl;
      cout << "Ending Airport is " << end.getName() << endl;
      cout << "A* search path: " << endl;
      if (s[0] == Airport()) {
        cout << "Error, there is no route between source airport and destination airport" << endl;
      } else {
        for (auto x : s) {
          cout << x.getID() << ":" << "\t" << x.getName() << endl;
        }
      }
      break;
    } else {
      cout << "Your input is invalid. Please try again. (enter a number from 1, 2, 3)" << endl;
    }
  }
  // how to use getAjacentRoute, pass a code of an airport

  // OpenFlight o2("data/airports.csv", "data/routes.csv", "1");
  // for (unsigned i = 0; i < o2.getAdjacentRoute(o2.getStart().getID()).size();
  //      i++) {
  //   cout << o2.getAdjacentRoute(o2.getStart().getID())[i].getDest().getID()
  //        << ", " <<
  //        o2.getAdjacentRoute(o2.getStart().getID())[i].getDistance()
  //        << "; ";
  // }
  // cout << d.get_distance(o2.getAirport("2962")) << endl;
  // cout << d.get_distance(o2.getAirport("2966")) << endl;
  // Dijkstra c(o1);

  // cout << c.get_distance(o1.getAirport("2966")) << endl;
  // for (auto i : c.get_path(o1.getAirport("2966"))) {
  //   cout << i.getID() << endl;
  // }
}
