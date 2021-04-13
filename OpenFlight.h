#pragma once
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>
#include <utility>
#include "Airport.h"
#include "Route.h"
#include <sstream>
using std::vector;
using std::unordered_map;


class OpenFlight{
    public:
        OpenFlight(string airport_file,string route_file,string start_ID);
        
        //pass id to this function to get all of routes of one airports
        vector<Route> getAdjacentRoute(string id);
        //get one airport
        Airport getAirport(string id);
        //get starting airport;
        Airport getStart();
        //parse airport_data
        void loadAirportData(string airport_file);
        //parse route_data
        void loadRouteData(string route_file);

    private:
        // get a airport and its routes
        unordered_map<string,vector <Route> > airport_routes;
        //a container of airports
        unordered_map<string,Airport> airports;
        //start point
        Airport start;

};