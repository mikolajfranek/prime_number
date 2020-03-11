#include "SieveOfEratosthenes.h"

// Define another benchmark
static void BM_Factor(benchmark::State& state) {
	SieveOfEratosthenes::Factor(MyConfiguration::GetSemiPrime(state.range(0)));
}
BENCHMARK(BM_Factor)
->Arg(10);
