#include "Airport.h"

Airport::Airport(){
    this->id="";
    this->city="";
    this->country="";
    this->info="";
    this->location=std::make_pair(0,0);
    this->name="";
}

Airport::Airport(string id, string name, string city, string country,double latitude, double longitude,string info){
    this->id = id;
    this->name = name;
    this->city = city;
    this->country = country;
    this->location.first = latitude;
    this->location.second = longitude;
    this->info = info;
}

pair<double, double> Airport::getLocation()const{
    return location;
}

string Airport::getID()const{
    return id;
}

string Airport::getName()const{
    return name;
}

string Airport::getCity()const{
    return city;
}

string Airport::getCountry()const{
    return country;
}

string Airport::getInfo()const{
    return info;
}

