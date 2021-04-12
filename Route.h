#pragma once
#include <string>
#include <utility>
#include "Airport.h"
using std::string;

class Route{
    public:
        Route(Airport& src,Airport& dest,string airline);
        Airport getSource() const;
        Airport getDest() const;
        double  getDistance();
        string  getAirline() const;
    private:
        Airport src;
        Airport dest;
        string  airline;
        double  distance;
};