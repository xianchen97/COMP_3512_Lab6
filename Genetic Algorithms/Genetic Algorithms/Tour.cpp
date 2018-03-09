#include "Tour.hpp"

int Tour::determine_fitness(Tour * population, int population_size)
{
	int i = 0, index_of_shortest_tour = 0;
	double shortest_tour_in_population = (double)RAND_MAX; // Begin by assuming distance is enormous
	double candidate_distance = 0.0;

	for (i = 0; i < population_size; ++i) {
		candidate_distance = get_tour_distance(population[i]);
		population[i].fitness = FITNESS_SCALER / candidate_distance;
		if (candidate_distance <= shortest_tour_in_population) {
			index_of_shortest_tour = i;
			shortest_tour_in_population = candidate_distance;
		}
	}

	return index_of_shortest_tour;
}

double Tour::get_tour_distance(Tour city_list)
{
	int i = 0;
	double distance = 0.0;
	for (i = 0; i < CITIES_IN_TOUR; ++i) {
		distance +=
			City::get_distance_between_cities                      // so we create a loop
			(city_list.permutation[i], (city_list.permutation[(i + 1) % CITIES_IN_TOUR]));
	}
	return distance;
}

void Tour::shuffle_cities(City & permutation)
{
	int i = 0, index_one = 0, index_two = 0;
	for (i = 0; i < SHUFFLES; ++i) {
		index_one = rand() % CITIES_IN_TOUR;
		index_two = rand() % CITIES_IN_TOUR;

		swap_cities(index_one, index_two, permutation);
	}
	return;
}
