#include "../OpenFlight.h"
#include "../algorithm/BFS.h"
#include "../algorithm/Dijkstra.h"
#include "./catch/catch.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

TEST_CASE("Dijkstra dataset sample #1 check", "[dijkstra][dataset=1]") {

  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "1");
  Dijkstra d(o1, o1.getAirport("3"));
  REQUIRE( ( d.get_distance() - 1.1252443055) < 0.0001 );
  vector<string> actual_path{ "1", "3" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }

}

TEST_CASE("Dijkstra dataset sample #1 check case2", "[dijkstra][dataset=1]") {
  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "2");
  Dijkstra d(o1, o1.getAirport("3"));
  REQUIRE( ( d.get_distance() - 2.08574) < 0.0001 );
  vector<string> actual_path{ "2", "1", "3" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #2 check ", "[dijkstra][dataset=2]") {
  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "2922");
  Dijkstra d(o1, o1.getAirport("2975"));
  REQUIRE( ( d.get_distance() - 24.0247) < 0.0001 );
  vector<string> actual_path{ "2922", "6969", "2975" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}


TEST_CASE("Dijkstra dataset sample #2 check case2 ", "[dijkstra][dataset=2]") {
  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "2990");
  Dijkstra d(o1, o1.getAirport("2975"));
  REQUIRE( ( d.get_distance() - 11.5799) < 0.0001 );
  vector<string> actual_path{ "2990", "2975" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #3 check ", "[dijkstra][dataset=3]") {
  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv", "502");
  Dijkstra d(o1, o1.getAirport("302"));
  REQUIRE( ( d.get_distance() - 47.6041 ) < 0.0001 );
  vector<string> actual_path{ "502", "1064", "302" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #3 check case2  ", "[dijkstra][dataset=3]") {
  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv", "502");
  Dijkstra d(o1, o1.getAirport("1064"));
  REQUIRE( ( d.get_distance() - 22.7741 ) < 0.0001 );
  vector<string> actual_path{ "502", "1064" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #4 check ", "[dijkstra][dataset=4]") {
  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv", "1128");
  Dijkstra d(o1, o1.getAirport("1074"));
  REQUIRE( ( d.get_distance() - 39.1304 ) < 0.0001 );
  vector<string> actual_path{ "1128", "1074" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #4 check case2 ", "[dijkstra][dataset=4]") {
  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv", "1128");
  Dijkstra d(o1, o1.getAirport("1154"));
  REQUIRE( ( d.get_distance() - 67.0188 ) < 0.0001 );
  vector<string> actual_path{ "1128", "1074", "1154" };
  auto path = d.get_path();
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}