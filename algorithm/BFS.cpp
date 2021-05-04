#include "BFS.h"

vector<Airport> BFS::getPath(OpenFlight graph) {
    queue<Airport> q;
    unordered_map<string, bool> explored;
    count = 0;
    unordered_map<string, Airport> total_airport = graph.getAirport();
    // initialize our explored to default false
    for(auto v : total_airport){
        explored[v.first] = false;
    }
    // begin to traverse our total_airport
    for (auto v : total_airport) {
        if (explored[v.first] == false) {
            explored[v.first] = true;
            q.push(v.second);
            while (!q.empty()) {
                Airport source = q.front();
                path.push_back(q.front());
                q.pop();
                // incident edge (route) of source
                vector<Route> routes = graph.getAdjacentRoute(source.getID()); 
                for (auto edge : routes) {
                    Airport dest = edge.getDest();
                    // if we did not explore nearby airport, we need to push it our queue
                    if (explored[dest.getID()] == false) {
                        q.push(dest);
                        explored[dest.getID()] = true;
                    }
                }
                // we use this record the total number of airports we have traversed
                count++;
                //if our queue is empty, then we finish our traversal.
                if (q.empty()) {
                    end = source;
                } 
            }
        }
    }

    return path;
}

int BFS::getCount() {
    return count;
}

Airport BFS::getEnd() {
    return end;
}
