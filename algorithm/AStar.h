#pragma once
#include "../OpenFlight.h"
#include <cfloat>
#include <queue>

using std::priority_queue;
using std::make_pair;

class AStar{
    public:
        vector<Airport> reconstructPath(OpenFlight graph, Airport src, Airport dest);
    private:
        Airport aStarSearch(OpenFlight graph, Airport src, Airport dest);
        // Comparator for priority_queue
        struct Comparator{
            bool operator ()(const pair<Airport,double> & lhs, const pair<Airport,double> &rhs){
                 return lhs.second > rhs.second;
            }
        };
        // we need to check whether nearby airport has already been in the open_set
        bool isExist(priority_queue< pair<Airport,double> , vector< pair<Airport,double> >, Comparator > temp_set, const Airport& nearby)const;
        //heuristic function 
        double heuristic(const Airport &src,const Airport &dest)const;
        // // We use this queue to find the minest f
        priority_queue< pair<Airport,double> , vector< pair<Airport,double> >, Comparator > open_set;
        // f is the total cost of the node
        unordered_map<string, double>f;
        // g is the distance between the current and the start
        unordered_map<string, double>g;
        // pre is used as path backtrace
        unordered_map<string, Airport>pre;
};