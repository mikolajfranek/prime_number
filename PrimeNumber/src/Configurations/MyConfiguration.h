/* general */
#include <string>
#include <iostream>

/* gmp */
#include <gmp.h>
#include <gmpxx.h>

/* benchmark */
#include <benchmark/benchmark.h>

/* using */
using namespace std;

#ifndef CONFIGURATIONS_MYCONFIGURATION_H_
#define CONFIGURATIONS_MYCONFIGURATION_H_

#define NUMBER_FACTORING(ALGORITHM) 				\
	int main(){ 									\
		return NumberFactoring::Main(ALGORITHM); 	\
	} 												\

#define PRIMALITY_TESTING(ALGORITHM) 				\
	int main(){ 									\
		return PrimalityTesting::Main(ALGORITHM); 	\
	} 												\


class MyConfiguration {
public:
	enum NUMBER_FACTORING {SIEVE_OF_ERATOSTHENES, FERMAT};
	enum PRIMALITY_TESTING {EXAMPLE};
	static string GetSemiPrime(int numberOfDigits);
};

#endif
