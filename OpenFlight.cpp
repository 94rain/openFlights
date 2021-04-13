#include "OpenFlight.h"
using std::stringstream;
using std::ifstream;
using std::cout;
using std::stod;
using std::endl;


OpenFlight::OpenFlight(string airport_file,string route_file, string start_ID){
    loadAirportData(airport_file);
    loadRouteData(route_file);
    this->start = airports[start_ID];
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
			getline(ss,id,',');//there exists comma in the name,city,country which lead to wrong parsing
            ss.ignore(256, '"');//we do not need to include the " "
            getline(ss, name, '"');
            ss.ignore(256, ',');
            ss.ignore(2, '"');
            getline(ss, city, '"');
            ss.ignore(256, ',');
            ss.ignore(2, '"');
            getline(ss, country, '"');
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
        cout<<"Cannot open the airport file"<<endl;
    }
    infile.close();
}


void OpenFlight::loadRouteData(string route_file){
    string line;
	ifstream infile (route_file);
     if (infile.is_open()) {
        while (getline(infile, line)) {
            	stringstream ss(line);  
                string airline;
                string airline_id;
                string source;
                string source_id;
                string destination;
                string destination_id;
                string other_info;
                getline(ss, airline,',');
                getline(ss, airline_id,',');
                getline(ss, source,',');
                getline(ss, source_id,',');
                getline(ss, destination,',');
                getline(ss, destination_id,',');
                getline(ss, other_info,'\n');
                //initialize a new route
                Route new_route(airports[source_id],airports[destination_id],airline);
                airport_routes[source_id].push_back(new_route);
        }
     }else{
        cout<<"Cannot open the route_file"<<endl;
     }
     infile.close();
}