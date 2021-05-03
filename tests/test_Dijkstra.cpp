#include "../OpenFlight.h"
#include "../algorithm/BFS.h"
#include "../algorithm/Dijkstra.h"
#include "./catch/catch.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;
using namespace std;

TEST_CASE("Dijkstra dataset sample #1 check", "[dijkstra][dataset=1]") {

  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "1");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("3");
  REQUIRE( ( d.get_distance(end) - 124.481 ) < 0.001 );
  vector<string> actual_path{ "1", "3" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #1 check case2", "[dijkstra][dataset=1]") {
  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "2");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("3");
  REQUIRE( ( d.get_distance(end) - 231.194 ) < 0.001 );
  vector<string> actual_path{ "2", "1", "3" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #2 check ", "[dijkstra][dataset=2]") {
  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "2922");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("2975");
  REQUIRE( ( d.get_distance(end) - 2240.129  ) < 0.001 );
  vector<string> actual_path{ "2922", "6969", "2975" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #2 check case2 ", "[dijkstra][dataset=2]") {
  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "2990");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("2975");
  REQUIRE( ( d.get_distance(end) - 723.523 ) < 0.001 );
  vector<string> actual_path{ "2990", "2975" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #3 check ", "[dijkstra][dataset=3]") {
  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv", "502");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("302");
  REQUIRE( ( d.get_distance(end) - 4999.118 ) < 0.001 );
  vector<string> actual_path{ "502", "1064", "302" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #3 check case2  ", "[dijkstra][dataset=3]") {
  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv", "502");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("1064");
  REQUIRE( ( d.get_distance(end) - 2437.793 ) < 0.001 );
  vector<string> actual_path{ "502", "1064" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #4 check ", "[dijkstra][dataset=4]") {
  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv", "1128");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("1074");
  REQUIRE( ( d.get_distance(end) - 3683.733 ) < 0.001 );
  vector<string> actual_path{ "1128", "1074" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra dataset sample #4 check case2 ", "[dijkstra][dataset=4]") {
  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv", "1128");
  Dijkstra d(o1);
  Airport start = o1.getStart();
  Airport end = o1.getAirport("1154");
  REQUIRE( ( d.get_distance(end) - 6285.745 ) < 0.001 );
  vector<string> actual_path{ "1128", "1074", "1154" };
  auto path = d.get_path(end);
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getID() == actual_path[i]);
  }
}

TEST_CASE("Dijkstra on total dataset", "[dijkstra][totaldataset]") {

  OpenFlight o1("data/airports.csv", "data/routes.csv", "2965");
  Dijkstra d1(o1);
  Airport start1 = o1.getStart();
  Airport end1 = o1.getAirport("2990");
  REQUIRE( ( d1.get_distance(end1) - 1506.825 ) < 0.001 );
  vector<string> actual_path1{ "2965", "2990" };
  auto path1 = d1.get_path(end1);
  for (unsigned i = 0; i < path1.size(); i++) {
    REQUIRE(path1[i].getID() == actual_path1[i]);
  }
  
  OpenFlight o2("data/airports.csv", "data/routes.csv", "2965");
  Dijkstra d2(o2);
  Airport start2 = o2.getStart();
  Airport end2 = o2.getAirport("6160");
  REQUIRE( ( d2.get_distance(end2) - 2289.289 ) < 0.001 );
  vector<string> actual_path2{ "2965", "4029", "6160" };
  auto path2 = d2.get_path(end2);
  for (unsigned i = 0; i < path2.size(); i++) {
    REQUIRE(path2[i].getID() == actual_path2[i]);
  }
   
  OpenFlight o3("data/airports.csv", "data/routes.csv", "9026");
  Dijkstra d3(o3);
  Airport start3 = o3.getStart();
  Airport end3 = o3.getAirport("6969");
  REQUIRE( ( d3.get_distance(end3) - 4505.188 ) < 0.001 );
  vector<string> actual_path3{ "9026", "2937", "4374", "2975", "6969" };
  auto path3 = d3.get_path(end3);
  for (unsigned i = 0; i < path3.size(); i++) {
    REQUIRE(path3[i].getID() == actual_path3[i]);
  }

  OpenFlight o4("data/airports.csv", "data/routes.csv", "9026");
  Dijkstra d4(o4);
  Airport start4 = o4.getStart();
  Airport end4 = o4.getAirport("9026");
  REQUIRE( ( d4.get_distance(end4) - 0 ) < 0.001 );
  vector<string> actual_path4{ "9026" };
  auto path4 = d3.get_path(end4);
  for (unsigned i = 0; i < path4.size(); i++) {
    REQUIRE(path4[i].getID() == actual_path4[i]);
  }

  OpenFlight o5("data/airports.csv", "data/routes.csv", "9026");
  Dijkstra d5(o5);
  Airport start5 = o5.getStart();
  Airport end5 = o5.getAirport("9026");
  REQUIRE( ( d5.get_distance(end5) - 0 ) < 0.001 );
  vector<string> actual_path5{ "9026" };
  auto path5 = d3.get_path(end5);
  for (unsigned i = 0; i < path5.size(); i++) {
    REQUIRE(path5[i].getID() == actual_path5[i]);
  }
  
  // testcase for non-connected airports
  OpenFlight o6("data/airports.csv", "data/routes.csv", "3090");  
  Dijkstra d6(o6);
  Airport start6 = o6.getStart();
  Airport end6 = o6.getAirport("995");
  auto path6 = d6.get_path(end6);
  REQUIRE( path6.empty() );

}

