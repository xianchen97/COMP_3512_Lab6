#include "Population.hpp"

/*
* Mixes the contents of the NUMBER_OF_PARENTS tours pointed to by
* the parents pointer, and returns a pointer to the mixture.
*
* How are we mixing them?  Not very well, yet.  This method has
* been hard-coded for 2 parents.  Can you see how we can extend the
* code to incorporate cities from > 2 parents?  Do we need any
* preconditions (i.e. NUMBER_OF_PARENTS < POPULATION )?
*
* We select a random index and use the cities from one parent
* to populate the mixed tour up to and including that index, and then
* the cities from the second parent to top up the tour, making sure we
* don't add cities that are already in the mixed tour.
*
* Can you think of ways to improve the way we cross the 'parents'?
*
* PARAM:  parents, a pointer to a struct tour
* PRE:    parents is a valid pointer to NUMBER_OF_PARENTS struct tours
* RETURN: a pointer to a struct tour combination of the parents
*/
Tour * crossover(Tour & parents)
{
	/* Variables */
	int i = 0;

	Tour * child

	/* Here's how we use rand again.  We invoke the rand() function, and since
	we want the result to be between 0 and (CITIES_IN_TOUR - 1), we use the
	modulus operator */
	int boundary_index = rand() % CITIES_IN_TOUR;

	/* Sets the index of the mixed result to 0.0 */
	child->fitness = 0.0;

	/* Copies the first 'boundary_index' cities in order from parent 1 to the mixed
	result */
	for (i = 0; i < boundary_index; i++) {
		child->permutation[i] = parents->permutation[i];
	}

	/* Fills the rest of the cells with cities from parent 2 */
	while (boundary_index < CITIES_IN_TOUR) {
		for (i = 0; i < CITIES_IN_TOUR; ++i) {
			/* If the mixed tour doesn't already contain the city at that index in parent two... */
			if (!contains_city(child, boundary_index, &((parents + 1)->permutation[i]))) {

				/* ...then we add it from the second parent to the child... */
				child->permutation[boundary_index] = (parents + 1)->permutation[i];

				/* And increment the boundary_index */
				boundary_index++;
			}
		}
	}

	return child;
}