#include <iostream>
#include <vector>
#include "OpenFlight.h"
#include "algorithm/BFS.h"
using std::endl;
using std::cout;


int main(int argc, const char * argv[]) {
    //how to use getAjacentRoute, pass a code of an airport
    OpenFlight o1("data/airports.csv","data/airports_routes.csv","1");
    BFS s;
    s.getPath(o1);
    cout<<s.count<<endl;
}
