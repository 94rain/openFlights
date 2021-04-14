#include <iostream>
#include <vector>
#include "OpenFlight.h"
#include "algorithm/BFS.h"
using std::endl;
using std::cout;


int main(int argc, const char * argv[]) {
    //how to use getAjacentRoute, pass a code of an airport
    OpenFlight o1("data/simple_airports.csv","data/simple_routes.csv","1");
    vector<Route> r1 = o1.getAdjacentRoute("641");
    for(auto rst:r1){
        cout <<rst.getAirline()<< endl;
    }
    //how to use getStart
    Airport a1 = o1.getStart();
    cout <<a1.getName()<< endl;
    //how to use getAirport
    Airport a2 = o1.getAirport("123");
    cout <<a2.getName()<< endl;
    BFS bfs;
    auto path = bfs.getPath(o1);
    for(auto a3:path){
        cout<<a3.getName()<<endl;
    }
    cout<<bfs.end.getName()<<endl;
}
