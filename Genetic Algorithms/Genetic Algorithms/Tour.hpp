#pragma once

#include "City.hpp"
#include <vector>
class Tour {
	static const int CITIES_IN_TOUR = 20;
	static const int SHUFFLES = 32;  // A shuffle consists of swaps
	static const int  FITNESS_SCALER = 10000.0;// Scales the fitness to move the
											   // decimal place to a reasonable spot
	double fitness;
	std::vector<City *> permutation;

public:
	int determine_fitness(Tour * population, int population_size);
	double get_tour_distance(Tour city_list);
	void shuffle_cities(City & permutation);


};
