#pragma once
#include <queue>
#include <unordered_map>

#include "../OpenFlight.h"

using std::queue;
using std::vector;

class BFS{
    public:
        vector<Airport> getPath(OpenFlight graph); 
        int getCount();    
        Airport getEnd();
    private:
        vector<Airport> path;
        int count;
        Airport end;
};
