#include <iostream>
#include <vector>
#include "OpenFlight.h"
#include "algorithm/BFS.h"
using std::endl;
using std::cout;


int main(int argc, const char * argv[]) {
    //how to use getAjacentRoute, pass a code of an airport
    OpenFlight o1("data/simple_airports.csv","data/simple_routes.csv","1");
    BFS s;
    auto path = s.getPath(o1);
    cout<<s.count<<endl;
    for(auto p:path){
        cout<<p.getName()<<endl;
    }
}
