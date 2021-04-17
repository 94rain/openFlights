#pragma once
#include "Airport.h"
#include <string>
#include <utility>
using std::string;

class Route {
public:
  Route(Airport &src, Airport &dest, string airline);
  /**
   * get the source airport object
   * @return {Airport}  : 
   */
  Airport getSource() const;
  /**
   * get the destination airport object
   * @return {Airport}  : 
   */
  Airport getDest() const;
  /**
   * get the distance bewteen source and destination airport
   * @return {double}  : 
   */
  double getDistance();
  /**
   * get the airline of the flight
   * @return {string}  : 
   */
  string getAirline() const;

private:
  Airport src;
  Airport dest;
  string airline;
  double distance;
};
