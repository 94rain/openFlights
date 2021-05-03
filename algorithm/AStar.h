#pragma once
#include "../OpenFlight.h"
#include <cfloat>
#include <queue>

using std::make_pair;
using std::priority_queue;

class AStar {
    public:
        /**
         * get the path of all airports during A* search
         * @param  graph the OpenFlight graph for A* search
         * @param  src starting airport
         * @param  dest ending airport
         * @return {vector<Airport>}
         */
        vector<Airport> reconstructPath(OpenFlight graph, Airport src, Airport dest);
    private:
        /**
         * construct the path from starting airport to ending airport
         * @param  graph the OpenFlight graph for A* search
         * @param  src starting airport
         * @param  dest ending airport
         * @return {Airport}
         */
        Airport aStarSearch(OpenFlight graph, Airport src, Airport dest);
        /**
         * Comparator for priority_queue (open_set)
         */
        struct Comparator {
            bool operator()(const pair<Airport, double> &lhs,
                            const pair<Airport, double> &rhs) {
              return lhs.second > rhs.second;
            }
        };
        /**
         * we need to check whether nearby airport has already been in the open_set
         * @param  temp_set the copy of open_set
         * @param  nearby nearby airport
         * @return {bool}
         */
        bool isExist(priority_queue<pair<Airport, double>,
                                    vector<pair<Airport, double>>, Comparator>
                         temp_set,
                     const Airport &nearby) const;
        /**
         * heuristic function
         * @param  src starting airport
         * @param  dest ending airport
         * @return {double}
         */
        double heuristic(const Airport &src, const Airport &dest) const;


        // We use this queue to find the min f
        priority_queue<pair<Airport, double>, vector<pair<Airport, double>>,
                       Comparator>
            open_set;
        // f is the total cost of the node
        unordered_map<string, double> f;
        // g is the distance between the current and the start
        unordered_map<string, double> g;
        // pre is used as path backtrace
        unordered_map<string, Airport> pre;
};