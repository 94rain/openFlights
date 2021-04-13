#include "Airport.h"

Airport::Airport() {
  this->id = "";
  this->city = "";
  this->country = "";
  this->info = "";
  this->location = std::make_pair(0, 0);
  this->name = "";
}

Airport::Airport(string id, string name, string city, string country,
                 double latitude, double longitude, string info) {
  this->id = id;
  this->name = name;
  this->city = city;
  this->country = country;
  this->location.first = latitude;
  this->location.second = longitude;
  this->info = info;
}

pair<double, double> Airport::getLocation() const { return location; }

string Airport::getID() const { return id; }

string Airport::getName() const { return name; }

string Airport::getCity() const { return city; }

string Airport::getCountry() const { return country; }

string Airport::getInfo() const { return info; }

bool operator==(const Airport &a1, const Airport &a2) {
  return a1.getCity() == a2.getCity() && a1.getCountry() == a2.getCountry() &&
         a1.getID() == a2.getID() && a1.getInfo() == a2.getInfo() &&
         a1.getLocation() == a2.getLocation() && a1.getName() == a2.getName();
}