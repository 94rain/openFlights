#include "../OpenFlight.h"
#include "./catch/catch.hpp"

TEST_CASE("Airport constrcutor and getters") {
  Airport a1("1", "Goroka Airport", "Goroka", "Papua New Guinea", -6.081689834590001, -145.391998291, "5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  REQUIRE(a1.getID() == "1");
  REQUIRE(a1.getName() == "Goroka Airport");
  REQUIRE(a1.getCity() == "Goroka");
  REQUIRE(a1.getCountry() == "Papua New Guinea");
  REQUIRE(a1.getInfo() == "5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
  REQUIRE(a1.getLocation().first - (-6.081689834590001) < 0.001);
  REQUIRE(a1.getLocation().second - 145.391998291 < 0.001);
}

TEST_CASE("Route constrcutor and getters") {
    Airport a1("2965","Sochi International Airport","Sochi","Russia",43.449902,39.9566,"89,3,\"N\",\"Europe/Moscow\",\"airport\",\"OurAirports\"");
    Airport a2("2990","Kazan International Airport","Kazan","Russia",55.606201171875,49.278701782227,"411,3,\"N\",\"Europe/Moscow\",\"airport\",\"OurAirports\"");
    Route r1(a1, a2, "2B");
    REQUIRE(r1.getAirline() == "2B");
    REQUIRE(r1.getSource() == a1);
    REQUIRE(r1.getDest() == a2);
}

TEST_CASE("OpenFlight graph basic tests", "[start=2]") {
  OpenFlight o1("data/airports.csv", "data/routes.csv", "2");

  SECTION("Starting Airport is exactly the input") {
    REQUIRE(o1.getStart().getID() == "2");
  }

  SECTION("Airport properties check") {
    Airport a1_test = o1.getAirport("1");
    REQUIRE(a1_test.getID() == "1");
    REQUIRE(a1_test.getName() == "Goroka Airport");
    REQUIRE(a1_test.getCity() == "Goroka");
    REQUIRE(a1_test.getCountry() == "Papua New Guinea");
    REQUIRE(a1_test.getInfo() == "5282,10,\"U\",\"Pacific/Port_Moresby\",\"airport\",\"OurAirports\"");
    REQUIRE(a1_test.getLocation().first - (-6.081689834590001) < 0.001);
    REQUIRE(a1_test.getLocation().second - 145.391998291 < 0.001);
  }
}

