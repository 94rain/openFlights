#pragma once
#include <string>
#include <utility>
using std::pair;
using std::string;

class Airport {
public:
  Airport();
  Airport(string id, string name, string city, string country, double latitude, double longitude, string info);
  pair<double, double> getLocation() const; // <latitude, longitude>
  string getID() const;
  string getName() const;
  string getCity() const;
  string getCountry() const;
  string getInfo() const;
  friend bool operator==(const Airport &a1, const Airport &a2);

private:
  string id;
  string name;
  string city;
  string country;
  pair<double, double> location; // <latitude, longitude>
  string info;
};
