#include "Route.h"

Route::Route(Airport& src_,Airport& dest_,string airline):src(src_),dest(dest_){
    this->airline = airline;
    this->distance = getDistance();
}

Airport Route::getSource()const{
    return src;
}
Airport Route::getDest()const{
    return dest;
}
string Route::getAirline()const{
    return airline;
}
double Route::getDistance(){//Euclidean distance
    pair<double,double> src_location = src.getLocation();
    pair<double,double> dest_location = dest.getLocation();
    double distance = ((src_location.first-dest_location.first)*(src_location.first-dest_location.first))+((src_location.second-dest_location.second)*(src_location.second-dest_location.second));
    return sqrt(distance);
}