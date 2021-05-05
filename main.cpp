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
using std::vector;


int main() {
  string algorithm;
  string airport_file;
  string route_file;
  string src;
  string dest;
  vector<string> airport_files {"data/airports.csv", "data/simple_airports_1.csv", "data/simple_airports_2.csv", 
    "data/simple_airports_3.csv", "data/simple_airports_4.csv", "data/simple_airports_5.csv"};
  vector<string> route_files {"data/routes.csv", "data/simple_routes_1.csv", "data/simple_routes_2.csv", 
    "data/simple_routes_3.csv", "data/simple_routes_4.csv", "data/simple_routes_5.csv"};
  while (true) {
    cout << "Please select the dataset in which you hope to find the shortest path: (enter a number from 0, 1, 2, 3, 4, 5, 6)\n"
         << "Input \t Airport dataset location \t Routes dataset location " << endl;
    cout << "0\t " << airport_files[0] << " \t \t " << route_files[0] << endl; // output this separately for alignment
    for (unsigned i = 1; i < airport_files.size(); ++i) {
      cout << i << "\t "<< airport_files[i] << "\t " << route_files[i] << endl;
    }
    cout << "6\t Customize input files" << endl;
    int file_num = 0;
    cin >> file_num;
    getchar();
    // getline(cin,"\n");
    if (file_num == 6) {
      cout << "Input the relative path of your airport dataset: (Example: data/airports.csv) " << endl;
      getline(cin, airport_file);
      cout << "Input the relative path of your routes dataset: (Example: data/routes.csv) " << endl;
      getline(cin, route_file);
    } else if (file_num >= 0 && file_num <= 5) {
      airport_file = airport_files[file_num];
      route_file = route_files[file_num];
    } else {
      cout << "Invalid input." << endl;
      continue;
    }
    break;
  }
  while (true) {
    cout << "Select your algorithm from: (enter a number from 1, 2, 3 or exit) \n 1. BFS \n 2. Dijkstra \n 3. A* " << endl;
    getline(cin, algorithm);
    // this part is for BFS
    if (algorithm == "1") {
      OpenFlight o(airport_file, route_file);
      BFS s;
      auto path = s.getPath(o);
      cout << "Path of Traversed airports:" << endl;
      for (auto airport : path) {
        cout << airport.getID() << ":\t" << airport.getName() << endl;
      }
      cout << "The total number of Airports is " << s.getCount() << endl;
      // this part is for dijkstra
    } else if (algorithm == "2") {
      cout << "please enter the ID of starting airport: " << endl;
      getline(cin, src);
      cout << "please enter the ID of ending airport: " << endl;
      getline(cin, dest);
      OpenFlight o(airport_file, route_file);
      Airport start = o.getAirport(src);
      Dijkstra d(o,start);
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
    } else if (algorithm == "3") {
      cout << "please enter the ID of starting airport: " << endl;
      getline(cin, src);
      cout << "please enter the ID of ending airport: " << endl;
      getline(cin, dest);
      OpenFlight o(airport_file, route_file);
      AStar a;
      Airport start = o.getAirport(src);
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
    } else if (algorithm == "exit") {
      cout << "Program ends" << endl;
      break;
      // invalid command line
    } else {
      cout << "Your input is invalid. Please try again. (enter a number from 1, 2, 3 or exit)" << endl;
      continue;
    }
    cout <<"========= The algorithm completed, you can try another algorithm if you wish ========= " << endl;
  }
}