#pragma once

#include "City.hpp"
#include <vector>
class Tour {
	static const int CITIES_IN_TOUR = 20;
	double fitness;
	City permutations[CITIES_IN_TOUR];
};
