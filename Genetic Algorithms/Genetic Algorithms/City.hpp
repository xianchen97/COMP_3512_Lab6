#pragma once
#include <math.h>

class City {
	char name;
	int x_coordinate;
	int y_coordinate;
public:	
	static double get_distance_between_cities(City a, City b);
	void swap_cities(int index_one, int index_two, City & permutation);
};