#pragma once
#include "../OpenFlight.h"
#include <unordered_map>

#pragma once
#include "../OpenFlight.h"
#include <unordered_map>

using namespace std;

class Dijkstra{
    public:
    /** 
    * Constructor
    * determine a startpoint for finding the path
    * @param  graph the OpenFlight graph for Dijkstra algorithm
    * @param  desti the destination for Dijkstra algorithm
    */
    Dijkstra(OpenFlight graph, Airport desti);
    /** 
    * calculate the distance based on the given destination
    * @param  destination  the endpoint for Dijkstra algorithm
    * @return {double}
    */
    double get_distance();
    /**
    * store the path between two different airports
    *  @param  destination  the endpoint for Dijkstra algorithm
    *  @return {vector<Airport>}
    */
    vector<Airport> get_path();

    private:
    unordered_map<string, double> dis;
    unordered_map<string, Airport> last_airport;
    Airport destination;
    Airport start;

};