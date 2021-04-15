#pragma once
#include "Airport.h"
#include "Route.h"
#include <fstream>
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <unordered_map>
#include <utility>
#include <vector>
using std::unordered_map;
using std::vector;

class OpenFlight {
    public:
        OpenFlight(string airport_file, string route_file, string start_ID);
        // pass id to this function to get all of routes of one airports
        vector<Route> getAdjacentRoute(string id);
        // get one airport
        Airport getAirport(string id);
        // get all airports
        unordered_map<string, Airport> getAirport();
        // get starting airport;
        Airport getStart();
        // parse airport_data
        void loadAirportData(string airport_file);
        // parse route_data
        void loadRouteData(string route_file);
        //get total_airport_routes
        unordered_map<string, vector<Route>> getAirportRoutes();
    private:
        // get a airport and its routes
        unordered_map<string, vector<Route>> airport_routes;
        // a container of airports
        unordered_map<string, Airport> airports;
        // start point
        Airport start;
};
