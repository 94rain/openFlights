#pragma once
#include <queue>
#include <unordered_map>

#include "../OpenFlight.h"

using std::queue;
using std::vector;

class BFS{
    public:
        vector<Airport> getPath(OpenFlight graph);
        int count;
        Airport end;
    private:
        vector<Airport> path;
};