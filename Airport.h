#pragma once
#include <string>
#include <utility>
using std::pair;
using std::string;

class Airport {
public:
  Airport();
  Airport(string id, string name, string city, string country, double latitude, double longitude, string info);
  /**
   * get the location pair of the airport
   * @return {pair<double, double}
   */
  pair<double, double> getLocation() const; // <latitude, longitude>
  /**
   * get the ID of the airport
   * @return {string}
   */
  string getID() const;
  /**
   * get the name of the airport
   * @return {string}
   */
  string getName() const;
  /**
   * get the city name of the airport
   * @return {string}
   */
  string getCity() const;
  /**
   * get the country name of the airport
   * @return {string}
   */
  string getCountry() const;
  /**
   * get the name of the airport
   * @return {string}
   */
  string getInfo() const;
  /**
   * overloading == operator to compare Airport classes
   * @param  a1 : 
   * @param  a2 : 
   * @return {bool}     
   */
  friend bool operator==(const Airport &a1, const Airport &a2);

private:
  string id;
  string name;
  string city;
  string country;
  pair<double, double> location; // <latitude, longitude>
  string info;
};
