#include "../OpenFlight.h"
#include "./catch/catch.hpp"

TEST_CASE("Airport constructor and getters", "[graph]") {
  Airport a1(
      "1", "Goroka Airport", "Goroka", "Papua New Guinea", -6.081689834590001,
      -145.391998291,
      "5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  REQUIRE(a1.getID() == "1");
  REQUIRE(a1.getName() == "Goroka Airport");
  REQUIRE(a1.getCity() == "Goroka");
  REQUIRE(a1.getCountry() == "Papua New Guinea");
  REQUIRE(a1.getLocation().first - (-6.081689834590001) < 0.001);
  REQUIRE(a1.getLocation().second - 145.391998291 < 0.001);
  REQUIRE(a1.getInfo() ==
          "5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
}

TEST_CASE("Route constructor and getters", "[graph]") {
  Airport a1("2965", "Sochi International Airport", "Sochi", "Russia",
             43.449902, 39.9566,
             "89,3,\"N\",\"Europe/Moscow\",\"airport\",\"OurAirports\"");
  Airport a2("2990", "Kazan International Airport", "Kazan", "Russia",
             55.606201171875, 49.278701782227,
             "411,3,\"N\",\"Europe/Moscow\",\"airport\",\"OurAirports\"");
  Route r1(a1, a2, "2B");
  REQUIRE(r1.getAirline() == "2B");
  REQUIRE(r1.getSource() == a1);
  REQUIRE(r1.getDest() == a2);
}

TEST_CASE("OpenFlight graph basic tests", "[graph]") {
  OpenFlight o1("data/simple_airports_1.csv", "data/simple_routes_1.csv");

  SECTION("Airport properties check") {
    Airport a1 = o1.getAirport("1");
    REQUIRE(a1.getID() == "1");
    REQUIRE(a1.getName() == "Goroka Airport");
    REQUIRE(a1.getCity() == "Goroka");
    REQUIRE(a1.getCountry() == "Papua New Guinea");
    REQUIRE(a1.getLocation().first - (-6.081689834590001) < 0.001);
    REQUIRE(a1.getLocation().second - 145.391998291 < 0.001);
    REQUIRE(a1.getInfo() == "5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");

    Airport a2 = o1.getAirport("2");
    REQUIRE(a2.getID() == "2");
    REQUIRE(a2.getName() == "Madang Airport");
    REQUIRE(a2.getCity() == "Madang");
    REQUIRE(a2.getCountry() == "Papua New Guinea");
    REQUIRE(a2.getLocation().first - (-5.20707988739) < 0.001);
    REQUIRE(a2.getLocation().second - 145.789001465 < 0.001);
    Airport a3 = o1.getAirport("3");

    REQUIRE(a3.getID() == "3");
    REQUIRE(a3.getName() == "Mount Hagen Kagamuga Airport");
    REQUIRE(a3.getCity() == "Mount Hagen");
    REQUIRE(a3.getCountry() == "Papua New Guinea");
    REQUIRE(a3.getLocation().first - (-5.826789855957031) < 0.001);
    REQUIRE(a3.getLocation().second - 144.29600524902344 < 0.001);
    Airport a4 = o1.getAirport("4");

    REQUIRE(a4.getID() == "4");
    REQUIRE(a4.getName() == "Nadzab Airport");
    REQUIRE(a4.getCity() == "Nadzab");
    REQUIRE(a4.getCountry() == "Papua New Guinea");
    REQUIRE(a4.getLocation().first - (-6.569803) < 0.001);
    REQUIRE(a4.getLocation().second - 146.725977 < 0.001);
  }
}
