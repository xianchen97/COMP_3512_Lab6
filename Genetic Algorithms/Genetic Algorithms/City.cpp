#include "City.hpp"

double City::get_distance_between_cities(City a, City b)
{
	return sqrt(pow((double)(a.x_coordinate - b.x_coordinate), 2.0) +
		pow((double)(a.y_coordinate - b.y_coordinate), 2.0));

}
