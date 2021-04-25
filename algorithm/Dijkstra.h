#pragma once
#include "../OpenFlight.h"
#include <unordered_map>

using namespace std;

class Dijkstra{
    public:
    Dijkstra(OpenFlight graph, Airport start);
    int get_distance(Airport destination);
    vector<Airport> get_path(Airport destination);

    private:
    unordered_map<string, double> dis;
    unordered_map<string, Airport> last_airport;
    Airport StartPoint;
};