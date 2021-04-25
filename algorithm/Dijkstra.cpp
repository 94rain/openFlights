#include "Dijkstra.h"
#include <queue>
#include <iostream>

using namespace std;

double Dijkstra::get_distance() {
    return dis[destination.getID()];
}

Dijkstra::Dijkstra(OpenFlight graph, Airport desti) {
    destination = desti;
    start = graph.getStart();
    unordered_map<string, bool> visited;
    for (auto v : graph.getAirport()) {
        dis[v.first] = -1;
        visited[v.first] = false;
    }
    dis[start.getID()] = 0;
    queue<string> q;
    q.push(start.getID());
    while (q.front() != destination.getID()) {
        string current = q.front();
        for (auto i : graph.getAdjacentRoute(current)) {
            string des = i.getDest().getID();
            if (!visited[des]) {
                q.push(des);
                double new_dis = dis[current] + i.getDistance();
                if (dis[des]<0) {
                    dis[des] = new_dis;
                    last_airport[des] = graph.getAirport(current);
                } else {
                    if (dis[des] > new_dis) {
                        dis[des] = new_dis;
                        last_airport[des] = graph.getAirport(current);
                    }
                }
            }
        }
        visited[current] = true;
        q.pop();
    }
}

vector<Airport> Dijkstra::get_path() {
    vector<Airport> output;
    vector<Airport> result;
    for (Airport airport = destination; dis[airport.getID()] != 0; airport = last_airport[airport.getID()]) {
        output.push_back(airport);
    }
    output.push_back(start);
    for (int i = output.size() - 1; i >= 0; i--) {
        result.push_back(output[i]);
    }
    return result;
}