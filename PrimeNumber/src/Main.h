#ifndef MAIN_H_
#define MAIN_H_

/* general */
#include <numeric>
#include <unordered_map>
#include <unordered_set>
#include <fstream>

/* gmp */
#include <gmp.h>

/* mpfr */
#include <mpfr.h>

/* benchmark */
#include <benchmark/benchmark.h>

/* using */
using namespace std;

/* components */
#include "Components/Abstracts/IFile.h"
#include "Components/Files/FileWriter.h"

/* elements */
#include "Elements/PrimeOfQuadraticResidue.h"
#include "Elements/ElementOfQuadraticSieve.h"

/* other */
#include "Elements/MyHelper.h"

/* solver */
#include "Algorithms/Solver/TonelliShanks.h"
#include "Algorithms/Solver/GaussianElimination.h"

/* primes below limit */
#include "Algorithms/Abstracts/IPrimesBelowUpperBound.h"
#include "Algorithms/PrimesBelowUpperBound/SieveOfEratosthenes.h"

/* primality */
#include "Algorithms/Abstracts/IPrimality.h"
#include "Algorithms/Primality/TrialDivision.h"

/* factorization */
#include "Algorithms/Abstracts/IFactorization.h"
#include "Algorithms/Factorization/TrialDivision.h"
#include "Algorithms/Factorization/Fermat.h"
#include "Algorithms/Factorization/QuadraticSieve.h"

#endif
