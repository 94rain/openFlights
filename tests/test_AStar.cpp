#include "../OpenFlight.h"
#include "../algorithm/AStar.h"
#include "./catch/catch.hpp"
#include <string>
#include <vector>

TEST_CASE("Astar default dataset sample check", "[astar][dataset=0]") {

  OpenFlight o1("data/airports.csv", "data/routes.csv", "2922");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("1");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 5);
  vector<string> actual_path{"2922", "2908", "3077", "5", "1"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #1 check", "[astar][dataset=1]") {

  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "3");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("4");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 3);
  vector<string> actual_path{"3", "1", "4"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #2 case #1 check", "[astar][dataset=2]") {

  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "2922");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("2965");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 5);
  vector<string> actual_path{"2922", "6969", "2975", "2990", "2965"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #2 case #2 check", "[astar][dataset=2]") {

  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "6156");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("2922");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 5);
  vector<string> actual_path{"6156" ,"2990" ,"2975" ,"6969" ,"2922"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #3 case #1 check", "[astar][dataset=3]") {

  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv", "1550");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("302");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 4);
  vector<string> actual_path{"1550", "502", "1064", "302"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #3 case #2 check", "[astar][dataset=3]") {

  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv", "302");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("502");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 3);
  vector<string> actual_path{"302", "1064", "502"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #4 case #1 check", "[astar][dataset=4]") {

  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv", "1154");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("344");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 5);
  vector<string> actual_path{"1154", "1074", "1128", "1555", "344"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #4 case #2 check", "[astar][dataset=4]") {

  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv", "1128");
  AStar a1;
  Airport start = o1.getStart();
  Airport end = o1.getAirport("1154");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 3);
  vector<string> actual_path{"1128", "1074", "1154"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}