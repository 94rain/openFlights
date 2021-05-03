#pragma once
#include "../OpenFlight.h"
#include <unordered_map>
#include <cfloat>
#include <queue>

using namespace std;

class Dijkstra{
    public:
    /** 
    * Constructor
    * determine a startpoint for finding the path
    * @param  graph the OpenFlight graph for Dijkstra algorithm
    */
    Dijkstra(OpenFlight graph);
    /** 
    * calculate the distance based on the given destination
    * @param  destination  the endpoint for Dijkstra algorithm
    * @return {double}
    */
    double get_distance(Airport desti);
    /**
    * store the path between two different airports
    *  @param  destination  the endpoint for Dijkstra algorithm
    *  @return {vector<Airport>}
    */
    vector<Airport> get_path(Airport desti);

    // the comparator for the priority_queue
    struct Comparator {
        bool operator()(const pair<Airport, double> &lhs,
                        const pair<Airport, double> &rhs) {
            return lhs.second > rhs.second;
        }
    };
    /**
     * we need to check whether nearby airport has already been in the q
     * @param  temp_q the copy of q
     * @param  nearby nearby airport
     * @return {bool}
     */
    bool isExist(priority_queue<pair<Airport, double>,
                                  vector<pair<Airport, double>>, Comparator>
                        temp_q,
                    const Airport &nearby) const;
    private:
    // priority queue to find the min dis
    priority_queue<pair<Airport, double>, vector<pair<Airport, double>>,Comparator> q;
    // the map of the distance from each airport to the start point
    unordered_map<string, double> dis;
    // the map for finding the path from start point to the destination
    unordered_map<string, Airport> last_airport;
    // the start airport
    Airport start;

};