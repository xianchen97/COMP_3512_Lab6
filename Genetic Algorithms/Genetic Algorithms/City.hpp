#pragma once
#include <math.h>

class City {
	char name;
	int x_coordinate;
	int y_coordinate;
public:	
	double get_distance_between_cities(City a, City b);
};