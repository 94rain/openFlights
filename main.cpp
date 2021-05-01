#include "OpenFlight.h"
#include "algorithm/BFS.h"
#include <iostream>
#include <vector>
#include "algorithm/Dijkstra.h"
#include "algorithm/AStar.h"
using std::cout;
using std::endl;

//int main(int argc, const char * argv[]) {
int main() {
  // how to use getAjacentRoute, pass a code of an airport

  OpenFlight o1("data/airports.csv", "data/routes.csv", "2922");
  // OpenFlight o2("data/airports.csv", "data/routes.csv", "1");
  //for (unsigned i = 0; i < o2.getAdjacentRoute(o2.getStart().getID()).size(); i++) {
    //cout << o2.getAdjacentRoute(o2.getStart().getID())[i].getDest().getID() << ", "<< o2.getAdjacentRoute(o2.getStart().getID())[i].getDistance() << "; ";
  //}
  //cout << d.get_distance(o2.getAirport("2962")) << endl;
  //cout << d.get_distance(o2.getAirport("2966")) << endl;
  //Dijkstra c(o2, o2.getAirport("1"));
  //cout << c.get_distance(o2.getAirport("2")) << endl;
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("1");
  vector<Airport> s = a1.reconstructPath(o1,start,end);
  if(s[0]==Airport()){
    cout<<"Error, there is no route between source and destination"<<endl;
  }else{
    for(auto x:s){
      cout<<x.getID()<<endl;
    }
  }
}
