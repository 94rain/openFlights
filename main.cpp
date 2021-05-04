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
  string src;
  string dest;
  while (true) {
    cout << "Select your algorithm from: (enter a number from 1, 2, 3 or exit) \n 1. BFS \n 2. Dijkstra \n 3. A* " << endl;
    getline(cin, str);
    // this part is for BFS
    if (str == "1") {
      OpenFlight o("data/airports.csv", "data/routes.csv", "1");
      BFS s;
      auto path = s.getPath(o);
      for (auto i : path) {
        cout << i.getName() << endl;
      }
      cout << "The total number of Airport is " << s.getCount() << endl;
      // this part is for dijkstra
    } else if (str == "2") {
      cout << "please enter the ID of starting airport: " << endl;
      getline(cin, src);
      cout << "please enter the ID of ending airport: " << endl;
      getline(cin, dest);
      OpenFlight o("data/airports.csv", "data/routes.csv", src);
      Dijkstra d(o);
      Airport start = o.getStart();
      Airport end = o.getAirport(dest);
      vector<Airport> path = d.get_path(end);
      if (path.empty() || path[0] == Airport()) {
        cout << "Error, there is no route between source airport and "
                "destination airport"
             << endl;
      } else {
        cout << "Starting Airport is " << start.getName() << endl;
        cout << "Ending Airport is " << end.getName() << endl;
        cout << "Dijkstra path: " << endl;
        for (auto airport : path) {
          cout << airport.getID() << ":\t" << airport.getName() << endl;
        }
      }
      // this part is for Astar
    } else if (str == "3") {
      cout << "please enter the ID of starting airport: " << endl;
      getline(cin, src);
      cout << "please enter the ID of ending airport: " << endl;
      getline(cin, dest);
      OpenFlight o("data/simple_airports_2.csv", "data/simple_routes_2.csv", src);
      AStar a;
      Airport start = o.getStart();
      Airport end = o.getAirport(dest);
      vector<Airport> path = a.reconstructPath(o, start, end);
      if (path[0] == Airport()) {
        cout << "Error, there is no route between source airport and destination airport" << endl;
      } else {
        cout << "Starting Airport is " << start.getName() << endl;
        cout << "Ending Airport is " << end.getName() << endl;
        cout << "A* search path: " << endl;
        for (auto airport : path) {
          cout << airport.getID() << ":\t" << airport.getName() << endl;
        }
      }
      // exit our program
    } else if (str == "exit") {
      cout << "Program ends" << endl;
      break;
      // invalid command line
    } else {
      cout << "Your input is invalid. Please try again. (enter a number from 1, 2, 3 or exit)" << endl;
    }
  }
}