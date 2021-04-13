#include <iostream>
#include <vector>
#include "OpenFlight.h"
using std::endl;;
using std::cout;


int main(int argc, const char * argv[]) {
    //how to use getAjacentRoute, pass a code of an airport
    OpenFlight o1("data/airports.csv","data/routes.csv","2");
    vector<Route> r1 = o1.getAdjacentRoute("641");
    for(auto rst:r1){
        std::cout <<rst.getAirline()<< std::endl;
    }
    //how to use getStart
    Airport a1 = o1.getStart();
    std::cout <<a1.getName()<< std::endl;
    //how to use getAirport
    Airport a2 = o1.getAirport("123");
    std::cout <<a2.getName()<< std::endl;
}
