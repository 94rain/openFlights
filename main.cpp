#include <iostream>
#include <vector>
#include "OpenFlight.h"

int main(int argc, const char * argv[]) {
    OpenFlight o1("data/airports.csv","","2");

    std::cout <<o1.getStart().getName()<< std::endl;
    std::cout <<o1.getAirport("1").getName()<< std::endl;
    std::cout <<o1.getAirport("2").getName()<< std::endl;
    std::cout <<o1.getAirport("3").getName()<< std::endl;
    std::cout <<o1.getAirport("4").getName()<< std::endl;
    std::cout <<o1.getAirport("14110").getInfo()<< std::endl;
}
