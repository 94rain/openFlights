#include "../OpenFlight.h"
#include "../algorithm/BFS.h"
#include "./catch/catch.hpp"
#include <string>
#include <vector>
using std::string;
using std::vector;

TEST_CASE("BFS dataset sample #1 check", "[bfs][dataset=1]") {
  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv", "1");
  BFS s;
  auto path = s.getPath(o1);
  REQUIRE(s.getCount() == 4);
  vector<string> actual_path{"Nadzab Airport", "Madang Airport",
                             "Goroka Airport", "Mount Hagen Kagamuga Airport"};
  unsigned i = 0;
  for (i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getName() == actual_path[i]);
  }
  REQUIRE(s.getEnd().getName() == "Mount Hagen Kagamuga Airport");
}

TEST_CASE("BFS dataset sample #2 check", "[bfs][dataset=2]") {
  OpenFlight o1("data/simple_airports_2.csv", "data/simple_routes_2.csv", "2922");
  BFS s;
  auto path = s.getPath(o1);
  REQUIRE(s.getCount() == 7);
  vector<string> actual_path{"Heydar Aliyev International Airport" ,"Begishevo Airport" ,"Sochi International Airport" ,"Dushanbe Airport" ,"Belgorod International Airport" ,"Khrabrovo Airport" ,"Kazan International Airport" ,"Heydar Aliyev International Airport"};
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getName() == actual_path[i]);
  }
    REQUIRE(s.getEnd().getName() == "Kazan International Airport");
}

TEST_CASE("BFS dataset sample #3 check", "[bfs][dataset=3]") {
  OpenFlight o1("data/simple_airports_3.csv", "data/simple_routes_3.csv", "1064");
  BFS s;
  auto path = s.getPath(o1);
  REQUIRE(s.getCount() == 4);
  vector<string> actual_path{"Al Massira Airport", "London Gatwick Airport", "Brussels Airport", "Verona Villafranca Airport"};
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getName() == actual_path[i]);
  }
    REQUIRE(s.getEnd().getName() == "Verona Villafranca Airport");
}



TEST_CASE("BFS dataset sample #4 check", "[bfs][dataset=4]") {
  OpenFlight o1("data/simple_airports_4.csv", "data/simple_routes_4.csv", "1154");
  BFS s;
  auto path = s.getPath(o1);
  REQUIRE(s.getCount() == 5);
  vector<string> actual_path{"Benina International Airport", "Mohammed V International Airport", "Cairo International Airport", "Leonardo da Vinci–Fiumicino Airport", "Cologne Bonn Airport"};
  for (unsigned i = 0; i < path.size(); i++) {
    REQUIRE(path[i].getName() == actual_path[i]);
  }
    REQUIRE(s.getEnd().getName() == "Cologne Bonn Airport");
}

TEST_CASE("BFS comprehensive dataset number of traversed airports check", "[bfs]") {
  OpenFlight o1("data/airports.csv", "data/routes.csv", "1");
  BFS s;
  auto path = s.getPath(o1);
  REQUIRE(s.getCount() == 7699);
  REQUIRE(s.getEnd().getName() == "Sky Ranch At Carefree Airport");
}
