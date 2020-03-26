#include "../Configurations/MyConfiguration.h"
#include "Algorithm.h"

#ifndef ALGORITHMS_QUADRATICSIEVE_H_
#define ALGORITHMS_QUADRATICSIEVE_H_

class QuadraticSieve {
public:
	static void Factor(string n);

	static bool Tonelli_Shanks(mpz_t n, mpz_t p);

private:

};

#endif
