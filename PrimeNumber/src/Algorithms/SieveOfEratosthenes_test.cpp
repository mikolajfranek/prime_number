#include "SieveOfEratosthenes.h"

// Define benchmark
static void BM_SieveOfEratosthenes(benchmark::State& state) {
	for (auto _ : state){
		SieveOfEratosthenes::Factor(MyConfiguration::GetSemiPrime(state.range(0)));
	}
}
/* register the function as benchmark with arguments */
BENCHMARK(BM_SieveOfEratosthenes)->Arg(10)->Arg(20)->Arg(30);
