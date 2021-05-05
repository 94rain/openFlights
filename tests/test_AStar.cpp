#include "../OpenFlight.h"
#include "../algorithm/AStar.h"
#include "./catch/catch.hpp"
#include <string>
#include <vector>

TEST_CASE("Astar default dataset sample check", "[astar][dataset=0]") {

  OpenFlight o1("data/airports.csv", "data/routes.csv");
  AStar a1;
  Airport start = o1.getAirport("2922");
  Airport end = o1.getAirport("1");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 5);
  vector<string> actual_path{"2922", "2908", "3077", "5", "1"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #1 check", "[astar][dataset=1]") {

  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv");
  AStar a1;
  Airport start = o1.getAirport("3");
  Airport end = o1.getAirport("4");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 3);
  vector<string> actual_path{"3", "1", "4"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #2 case #1 check", "[astar][dataset=2]") {

  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv");
  AStar a1;
  Airport start = o1.getAirport("2922");
  Airport end = o1.getAirport("2965");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 4);
  vector<string> actual_path{"2922", "6969", "2990", "2965"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #2 case #2 check", "[astar][dataset=2]") {

  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv");
  AStar a1;
  Airport start = o1.getAirport("2979");
  Airport end = o1.getAirport("2922");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 5);
  vector<string> actual_path{"2979" ,"2965" ,"2990" ,"6969" ,"2922"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #3 case #1 check", "[astar][dataset=3]") {

  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv");
  AStar a1;
  Airport start = o1.getAirport("1550");
  Airport end = o1.getAirport("302");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 4);
  vector<string> actual_path{"1550", "502", "1064", "302"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #3 case #2 check", "[astar][dataset=3]") {

  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv");
  AStar a1;
  Airport start = o1.getAirport("302");
  Airport end = o1.getAirport("502");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 3);
  vector<string> actual_path{"302", "1064", "502"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #4 case #1 check", "[astar][dataset=4]") {

  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv");
  AStar a1;
  Airport start = o1.getAirport("1128");
  Airport end = o1.getAirport("344");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 3);
  vector<string> actual_path{"1128", "1555", "344"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #4 case #2 check", "[astar][dataset=4]") {

  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv");
  AStar a1;
  Airport start = o1.getAirport("1154");
  Airport end = o1.getAirport("344");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 4);
  vector<string> actual_path{"1154", "1128", "1555", "344"};
    for (unsigned i = 0; i < path.size(); i++) {
      REQUIRE(path[i].getID() == actual_path[i]);
    }
}

TEST_CASE("Astar dataset sample #5", "[astar][dataset=5]") {
  OpenFlight o1("data/simple_airports_5.csv", "data/simple_routes_5.csv");
  AStar a1;
  Airport start = o1.getAirport("3395");
  Airport end = o1.getAirport("9481");
  vector<Airport> path = a1.reconstructPath(o1, start, end);
  REQUIRE(path.size() == 1);
  REQUIRE(path[0]==Airport());
}