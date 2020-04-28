#ifndef CONFIGURATIONS_MYCONFIGURATION_H_
#define CONFIGURATIONS_MYCONFIGURATION_H_

/* general */
#include <string>
#include <vector>
#include <cmath>
#include <numeric> /* iota */

/* gmp */
#include <gmp.h>
#include <gmpxx.h>

/* benchmark */
#include <benchmark/benchmark.h>

/* using */
using namespace std;

class MyConfiguration {
public:
	static string GetSemiPrime(int numberOfDigits);
};

#endif
