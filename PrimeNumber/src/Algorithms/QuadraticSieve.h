#include "../Configurations/MyConfiguration.h"
#include "Algorithm.h"

#ifndef ALGORITHMS_QUADRATICSIEVE_H_
#define ALGORITHMS_QUADRATICSIEVE_H_

class QuadraticSieve {
public:
	static void Factor(string n);

	static void Tonelli_Shanks(mpz_t n, mpz_t p, long& r1, long &r2);

private:

};

#endif
