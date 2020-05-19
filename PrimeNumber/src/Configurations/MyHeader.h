#ifndef CONFIGURATIONS_MYHEADER_H_
#define CONFIGURATIONS_MYHEADER_H_

/* general */
#include <string>
#include <vector>
#include <cmath>
#include <numeric>

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

#endif
