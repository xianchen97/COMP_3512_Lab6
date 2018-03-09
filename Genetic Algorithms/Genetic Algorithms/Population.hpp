#pragma once
#include "City.hpp"
#include "Tour.hpp"
class Population {
	/* Variables */
	int    i = 0, j = 0, iterations = 0;
	int    index_of_shortest_tour = 0;
	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;

public:

	void shuffle_cities(City * permutation);

	double get_distance_between_cities(City a, City b);

	double get_tour_distance(Tour city_list);

	int determine_fitness(Tour * population, int population_size);

	void swap_cities(int index_one, int index_two, City * permutation);

	Tour * select_parents(Tour * population);

	Tour * crossover(Tour * parents);

	void mutate(Tour * population);

	int contains_city(Tour * candidate_tour, int length, City * candidate_city);



};



