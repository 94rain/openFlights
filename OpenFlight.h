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
        /**
         * OpenFlight 
         * 
         * @param  {string} airport_file : 
         * @param  {string} route_file   : 
         */
        OpenFlight(string airport_file, string route_file);
        /**
         * pass id to this function to get all of routes of one airports
         * @param  {string} id      : 
         * @return {vector<Route>}  : 
         */
        vector<Route> getAdjacentRoute(string id);
        /**
         * get one airport
         * @param  {string} id : 
         * @return {Airport}   : 
         */
        Airport getAirport(string id);
        /**
         * get all airports
         * @return {unordered_map<string,}  : 
         */
        unordered_map<string, Airport> getAirport();
        /**
         * parse airport_data
         * @param  {string} airport_file : 
         */
        void loadAirportData(string airport_file);
        /**
         * parse route_data
         * @param  {string} route_file : 
         */
        void loadRouteData(string route_file);
        /**
         * get total_airport_routes
         * @return {unordered_map<string,}  : 
         */
        unordered_map<string, vector<Route> > getAirportRoutes();
    private:
        // get a airport and its routes
        unordered_map<string, vector<Route> > airport_routes;
        // a container of airports
        unordered_map<string, Airport> airports;
};
