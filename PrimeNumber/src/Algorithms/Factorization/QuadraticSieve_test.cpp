#include "QuadraticSieve.h"

// Define benchmark
static void BM_QuadraticSieve(benchmark::State& state) {
	for (auto _ : state){
		QuadraticSieve::Factor(MyHelper::GetSemiPrime(state.range(0)));
	}
}
/* register the function as benchmark with arguments */
BENCHMARK(BM_QuadraticSieve)->Arg(10)->Arg(20)->Arg(30);
