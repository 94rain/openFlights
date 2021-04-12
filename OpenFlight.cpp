#include "OpenFlight.h"
using std::stringstream;
using std::ifstream;
using std::make_pair;
using std::cout;
using std::stod;

OpenFlight::OpenFlight(string airport_file,string route_file, string start_ID){
    loadAirportData(airport_file);
    loadRouteData(route_file);
    this->start = getAirport(start_ID);
}

vector<Route> OpenFlight::getAdjacentRoute(string id){
    return airport_routes[id];
}

Airport OpenFlight::getAirport(string id){
    return airports[id];
}

Airport OpenFlight::getStart(){
    return start;
}

void OpenFlight::loadAirportData(string airport_file){
    string line;
	ifstream infile (airport_file);
    int count = 0;
    if (infile.is_open()) {
        while (getline(infile, line)) {
			stringstream ss(line);  
            string id;
            string name;
            string city;
            string country;
            string iata;
            string icao;
            string info;
            string latitude, longitude;
			getline(ss,id,',');//there are some comma in the name
            ss.ignore(2, '"');
            std::getline(ss, name, '"');
            ss.ignore(256, ',');
            ss.ignore(2, '"');
            std::getline(ss, city, '"');
            ss.ignore(256, ',');
            ss.ignore(2, '"');
            std::getline(ss, country, '"');
            ss.ignore(256, ',');
            getline(ss,iata,',');
            getline(ss,icao,',');
            getline(ss,latitude,',');
            getline(ss,longitude,',');
            getline(ss,info,'\n');//we do not need to other useless info.

            //convert str location to double location
            double  latitude_db,longitude_db;
            latitude_db = stod(latitude);
            longitude_db = stod(longitude);
            //initialize a new airport
            Airport new_airport(id,name,city,country,latitude_db,longitude_db,info);
            airports[id] = new_airport;
        }
    }else{
        cout<<"Cannot open the file";
    }
}


void OpenFlight::loadRouteData(string route_file){
    
}