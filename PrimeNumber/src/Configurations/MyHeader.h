#ifndef CONFIGURATIONS_MYHEADER_H_
#define CONFIGURATIONS_MYHEADER_H_

/* general */
#include <string>
#include <unordered_set>

/* gmp */
#include <gmp.h>
#include <gmpxx.h>

/* benchmark */
#include <benchmark/benchmark.h>

/* using */
using namespace std;

/* helper */
#include "MyHelper.h"

/* solver */
#include "../Algorithms/Solver/TonelliShanks.h"
#include "../Algorithms/Solver/GaussianElimination.h"

/* primes below limit */
#include "../Algorithms/PrimesBelowLimit/SieveOfEratosthenes.h"

/* primality */
#include "../Algorithms/Primality/TrialDivision.h"

/* factorization */
#include "../Algorithms/Factorization/TrialDivision.h"
#include "../Algorithms/Factorization/Fermat.h"
#include "../Algorithms/Factorization/QuadraticSieve.h"

#endif
