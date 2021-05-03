#include "AStar.h"

Airport AStar::aStarSearch(OpenFlight graph, Airport src, Airport dest) {
    pre.clear();
    // initialize f and g with default value of infinity
    for (auto i : graph.getAirport()) {
      f[i.first] = DBL_MAX;
      g[i.first] = DBL_MAX;
    }
    g[src.getID()] = 0;
    f[src.getID()] = heuristic(src, dest);
    open_set.push(make_pair(src, f[src.getID()]));
    while (!open_set.empty()) {
      // we need to find smallest fscore
      Airport current = open_set.top().first;
      string currentID = current.getID();
      // if current node is destination, we finished our search
      if (current.getID() == dest.getID()) {
        return current;
      }
      open_set.pop();
      vector<Route> routes = graph.getAdjacentRoute(currentID);
      for (auto route : routes) {
        const Airport &nearby = route.getDest();
        if (g[currentID] + route.getDistance() < g[nearby.getID()]) {
          // This path is cheaper than any previous one.
          // Thus we need to update g and f
          pre[nearby.getID()] = current;
          g[nearby.getID()] = g[currentID] + route.getDistance();
          f[nearby.getID()] = g[nearby.getID()] + heuristic(nearby, dest);
          // we use this to check whether nearby is in open_set
          if (!isExist(open_set, nearby)) {
            open_set.push(make_pair(nearby, f[nearby.getID()]));
          }
        }
      }
    }
    // we did not found the destination airport
    return Airport();
}

// we need to check whether nearby airport has already been in the open_set
bool AStar::isExist(priority_queue<pair<Airport, double>, vector<pair<Airport, double>>, Comparator>
                        temp_set, const Airport &nearby) const {
    while (!temp_set.empty()) {
      const Airport &temp_airport = temp_set.top().first;
      if (temp_airport.getID() == nearby.getID()) {
        return true;
      }
      temp_set.pop();
    }
    return false;
}

// Distance for the heuristic function
double AStar::heuristic(const Airport &src, const Airport &dest) const {
    // convert lati and long to distance
    pair<double, double> src_location = src.getLocation();
    pair<double, double> dest_location = dest.getLocation();
    double lat1 = src_location.first * M_PI / 180;
    double lat2 = dest_location.first * M_PI / 180;
    double dlat = (dest_location.first - src_location.first) * M_PI / 180;
    double dlon = (dest_location.second - src_location.second) * M_PI / 180;
    double a =
        pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) * pow(sin(dlon / 2), 2);
    double c = 2 * atan2(sqrt(a), sqrt(1 - a));
    return c * 6371;
}

vector<Airport> AStar::reconstructPath(OpenFlight graph, Airport src, Airport dest) {
    vector<Airport> search_path;
    Airport current = aStarSearch(graph, src, dest);
    string currentID = current.getID(); 
    // backtrace search path
    while (pre.find(currentID) != pre.end()) {
      search_path.insert(search_path.begin(), current);
      current = pre[currentID];
      currentID = current.getID();
    }
    search_path.insert(search_path.begin(), current);   
    return search_path;
}
