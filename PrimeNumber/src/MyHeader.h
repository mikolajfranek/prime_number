#ifndef CONFIGURATIONS_MYHEADER_H_
#define CONFIGURATIONS_MYHEADER_H_

/* general */
#include <vector>
#include <string>
#include <cstring>
#include <numeric>
#include <math.h>

/* gmp */
#include <gmp.h>

/* benchmark */
#include <benchmark/benchmark.h>

/* using */
using namespace std;

/* elements */
#include "Elements/Prime.h"
#include "Elements/QuadraticResidue.h"

/* other */
#include "Other/MyHelper.h"

/* solver */
#include "Algorithms/Solver/TonelliShanks.h"
#include "Algorithms/Solver/GaussianElimination.h"

/* primes below limit */
#include "Algorithms/PrimesBelowLimit/SieveOfEratosthenes.h"

/* primality */
#include "Algorithms/Primality/TrialDivision.h"

/* factorization */
#include "Algorithms/Factorization/TrialDivision.h"
#include "Algorithms/Factorization/Fermat.h"
#include "Algorithms/Factorization/QuadraticSieve.h"

#endif
