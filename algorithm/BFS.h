#pragma once
#include <queue>
#include <unordered_map>
#include "../OpenFlight.h"

using std::queue;
using std::vector;

class BFS{
    public:
        /**
         * get the path of all visited airports during BFS
         * @param  graph the OpenFlight graph for BFS traversal
         * @return {vector<Airport>}
         */
        vector<Airport> getPath(OpenFlight graph); 
        /**
         * get the number of visited airports during BFS
         * @return {int}
         */
        int getCount();    
        /**
         * get the ending airport during BFS
         * @return {Airport}
         */
        Airport getEnd();
    private:
        vector<Airport> path;
        int count;
        Airport end;
};
