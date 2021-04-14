#include "BFS.h"


vector<Airport> BFS::getPath(OpenFlight graph){
    queue<Airport> q;
    unordered_map<string, bool> explored;
    explored[graph.getStart().getID()]=true;
    q.push(graph.getStart());
    count = 0;
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
        if(q.empty()){
            end = source;
        } 
    }




    return path;
}