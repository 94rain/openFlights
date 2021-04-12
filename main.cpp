#include <iostream>
#include <vector>
#include "Route.h"

int main(int argc, const char * argv[]) {
    Airport a1("123","a1","","",0,0,"");
    Airport a2("123","a2","","",3,4,"");
    Route r1(a1,a2,"1111");
    std::cout <<r1.getDistance()<< std::endl;
    std::cout <<r1.getAirline()<< std::endl;
    std::cout <<a1.getName()<<std::endl;
    std::cout <<a2.getName()<<std::endl;
}
