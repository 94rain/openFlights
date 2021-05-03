#include "Dijkstra.h"
#include <iostream>

using namespace std;

double Dijkstra::get_distance(Airport desti) {
    return dis[desti.getID()];
}

Dijkstra::Dijkstra(OpenFlight graph) {
    // set the start point
    start = graph.getStart();
    // initialize every value in the dis to the max
    for (auto v : graph.getAirport()) {
        dis[v.first] = DBL_MAX;
    }
    // set the start point dis to 0 and push the start airport
    dis[start.getID()] = 0;
    q.push(make_pair(start, dis[start.getID()]));
    // loop through the airports calculating the distance to the start airport
    while (!q.empty()) {
        Airport current = q.top().first;
        q.pop();
        for (auto i : graph.getAdjacentRoute(current.getID())) {
            if (dis[current.getID()] + i.getDistance() < dis[i.getDest().getID()]) {
                dis[i.getDest().getID()] = dis[current.getID()] + i.getDistance();
                last_airport[i.getDest().getID()] = current;
                q.push(make_pair(i.getDest(), dis[i.getDest().getID()]));
            }
        }
    }
}

vector<Airport> Dijkstra::get_path(Airport desti) {
    vector<Airport> output;
    // if there is no path from the start to desti return a empty vector
    if (dis[desti.getID()] == DBL_MAX) {
        return output;
    }
    // using last_airport to find the path from desti to the start and then reverse it 
    for (Airport airport = desti; dis[airport.getID()] != 0; airport = last_airport[airport.getID()]) {
        output.push_back(airport);
    }
    output.push_back(start);
    reverse(output.begin(), output.end());
    return output;
}