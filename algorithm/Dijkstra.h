#pragma once
#include "../OpenFlight.h"
#include <unordered_map>

using namespace std;

class Dijkstra{
    public:
    Dijkstra(OpenFlight graph, Airport desti);
    double get_distance();
    vector<Airport> get_path();

    private:
    unordered_map<string, double> dis;
    unordered_map<string, Airport> last_airport;
    Airport destination;
    Airport start;

};