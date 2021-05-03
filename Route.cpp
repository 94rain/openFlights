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
double Route::getDistance(){
    // convert lati and long to distance
    pair<double,double> src_location = src.getLocation();
    pair<double,double> dest_location = dest.getLocation();
    double lat1 = src_location.first * M_PI/180; 
    double lat2 = dest_location.first * M_PI/180; 
    double dlat = (dest_location.first - src_location.first) * M_PI/180; 
    double dlon = (dest_location.second-src_location.second) * M_PI/180;
    double a = pow(sin(dlat/2), 2) + cos(lat1)*cos(lat2)*pow(sin(dlon/2), 2); 
    double c = 2 * atan2(sqrt(a), sqrt(1-a)); 
    return c * 6371; 
}