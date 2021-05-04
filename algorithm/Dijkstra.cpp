#include "Dijkstra.h"

double Dijkstra::get_distance(Airport desti) {
    return dis[desti.getID()];
}

Dijkstra::Dijkstra(OpenFlight graph, Airport src) {
    // initialize every value in the dis to the max
    for (auto v : graph.getAirport()) {
        dis[v.first] = DBL_MAX;
    }
    // set the start point dis to 0 and push the start airport
    dis[src.getID()] = 0;
    q.push(make_pair(src, dis[src.getID()]));
    // loop through the airports calculating the distance to the start airport
    while (!q.empty()) {
        Airport current = q.top().first;
        q.pop();
        for (auto i : graph.getAdjacentRoute(current.getID())) {
            if (dis[current.getID()] + i.getDistance() < dis[i.getDest().getID()]) {
                dis[i.getDest().getID()] = dis[current.getID()] + i.getDistance();
                last_airport[i.getDest().getID()] = current;
                // we use this to check whether nearby is in q
                if (!isExist(q, i.getDest())) {
                    q.push(make_pair(i.getDest(), dis[i.getDest().getID()]));
                }
            }
        }
    }
}

// we need to check whether nearby airport has already been in the q
bool Dijkstra::isExist(priority_queue<pair<Airport, double>, vector<pair<Airport, double>>, Comparator>
                        temp_q, const Airport &nearby) const {
    while (!temp_q.empty()) {
      const Airport &temp_airport = temp_q.top().first;
      if (temp_airport.getID() == nearby.getID()) {
        return true;
      }
      temp_q.pop();
    }
    return false;
}

vector<Airport> Dijkstra::get_path(Airport desti) {
    vector<Airport> output;
    Airport current = desti;
    string currentID = desti.getID(); 
    // if there is no path from the start to desti return a empty vector
    if(dis[currentID] == DBL_MAX){
        return output;
    }
    // using last_airport to find the path from desti to the start and then reverse it 
    while (last_airport.find(currentID) != last_airport.end()) {
      output.push_back(current);
      current = last_airport[currentID];
      currentID = current.getID();
    }
    output.push_back(current);
    reverse(output.begin(), output.end());
    return output;
}