#ifndef MAIN_H_
#define MAIN_H_

/* general */
#include <numeric>
#include <unordered_map>
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
#include "../../../_old/PrimeNumber/src/Components/Abstracts/IFile.h"
#include "../../../_old/PrimeNumber/src/Components/Files/FileWriter.h"

/* elements */
#include "../../../_old/PrimeNumber/src/Elements/PrimeOfQuadraticResidue.h"
#include "../../../_old/PrimeNumber/src/Elements/ElementOfQuadraticSieve.h"

/* other */
#include "../../../_old/PrimeNumber/src/Elements/MyHelper.h"
#include "../../../_old/PrimeNumber/src/Elements/TestData.h"

/* solver */
#include "../../../_old/PrimeNumber/src/Algorithms/Solver/TonelliShanks.h"
#include "../../../_old/PrimeNumber/src/Algorithms/Solver/GaussianElimination.h"

/* primes below limit */
#include "Algorithms/Abstracts/IPrimesBelowUpperBound.h"
#include "Algorithms/PrimesBelowUpperBound/SieveOfEratosthenes.h"

/* primality */
#include "Algorithms/Abstracts/IPrimality.h"
#include "Algorithms/Primality/TrialDivision.h"

/* factorization */
#include "../../../_old/PrimeNumber/src/Algorithms/Abstracts/IFactorization.h"
#include "../../../_old/PrimeNumber/src/Algorithms/Factorization/TrialDivision.h"
#include "../../../_old/PrimeNumber/src/Algorithms/Factorization/Fermat.h"
#include "../../../_old/PrimeNumber/src/Algorithms/Factorization/QuadraticSieve.h"

#endif
