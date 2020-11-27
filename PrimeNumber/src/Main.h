#ifndef MAIN_H_
#define MAIN_H_

/* general */
#include <cstring>
#include <numeric>

/* gmp */
#include <gmp.h>

/* mpfr */
#include <mpfr.h>

/* benchmark */
#include <benchmark/benchmark.h>

/* using */
using namespace std;

/* elements */
#include "Elements/QuadraticResidue.h"
#include "Elements/ElementOfSieve.h"

/* other */
#include "Elements/MyHelper.h"

/* solver */
#include "Algorithms/Solver/TonelliShanks.h"
#include "Algorithms/Solver/GaussianElimination.h"

/* primes below limit */
#include "Abstracts/PrimesBelowUpperBound.h"
#include "Algorithms/PrimesBelowUpperBound/SieveOfEratosthenes.h"

/* primality */
#include "Abstracts/Primality.h"
#include "Algorithms/Primality/TrialDivision.h"

/* factorization */
#include "Abstracts/Factorization.h"
#include "Algorithms/Factorization/TrialDivision.h"
#include "Algorithms/Factorization/Fermat.h"
#include "Algorithms/Factorization/QuadraticSieve.h"

#endif
