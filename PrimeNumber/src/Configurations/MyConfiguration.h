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

class MyConfiguration {
public:
	static string GetSemiPrime(int numberOfDigits);
};

#endif
