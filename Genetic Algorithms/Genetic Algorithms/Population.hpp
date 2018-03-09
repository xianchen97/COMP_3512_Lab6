#pragma once
#include "City.hpp"
#include "Tour.hpp"
class Population {

	/* Remember to avoid magic numbers by defining constants */

	static const int  ASCII_OFFSET = 65;    // if we cast an int with value 65
	// as a char, we get 'A'
	
	static const int  ITERATIONS = 1000;   // Number of loops for the algorithm

	static const int  MAP_BOUNDARY = 1000;    // Size of the map (X and Y)

	static const int  PARENT_POOL_SIZE = 5;
	// Number of members randomly selected
	// from the population, from which the
	// fittest is made a 'parent'

	static const int  MUTATION_RATE = 0.15; // Chance of being mutated

	static const int  NUMBER_OF_PARENTS = 2;    // Number of 'parents' for each cross

	static const int  NUMBER_OF_ELITES = 1;   // The number of 'fittest' that remain
	// uncrossed and unmutated into the next gen

	/* Variables */
	int    i = 0, j = 0, iterations = 0;
	int    index_of_shortest_tour = 0;
	double best_distance = 0.0;
	double best_iteration_distance = 0.0;
	double improvement_factor = 0.3;

	/* Declares the pointers to our statically allocated memory. */
	static Tour * population ;      // Holds our candidate population
	static Tour * parents;         // Used during crossover
	static Tour * crosses;         // Used during calculations
	static Tour * temporary_tour;  // Used during calculations
	static City * cities_to_visit; // Stores master list of cities
	static Tour * child;


public:

	Tour * select_parents(Tour & population);

	Tour * crossover(Tour & parents);

	void mutate(Tour & population);

	int contains_city(Tour & candidate_tour, int length, City & candidate_city);



};



