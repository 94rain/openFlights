#include "BFS.h"
#include <iostream>
using std::cout;
using std::endl;

vector<Airport> BFS::getPath(OpenFlight graph){
    queue<Airport> q;
    unordered_map<string, bool> explored;
    count = 0;
    unordered_map<string, Airport> total_airport=graph.getAirport();
    for(auto v:total_airport){
        if(explored.find(v.second.getID()) == explored.end()){
            explored[v.second.getID()]=true;
            q.push(v.second);
            while(!q.empty()){
                Airport source = q.front();
                path.push_back(q.front());
                q.pop();
                vector<Route> routes = graph.getAdjacentRoute(source.getID());//incident edge(route)of source
                for(auto edge:routes){
                    Airport dest = edge.getDest();
                    if(explored.find(dest.getID()) == explored.end()){
                        q.push(dest);
                        explored[dest.getID()]=true;
                    }
                }
                count++;
                if(q.empty()){
                    end = source;
                } 
            }
        }
    }

    return path;
}