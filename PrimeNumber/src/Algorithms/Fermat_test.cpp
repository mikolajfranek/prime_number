#include "Fermat.h"

// Define benchmark
static void BM_Fermat(benchmark::State& state) {
	for (auto _ : state){
		Fermat::Factor(MyConfiguration::GetSemiPrime(state.range(0)));
	}
}
/* register the function as benchmark with arguments */
BENCHMARK(BM_Fermat)->Arg(10)->Arg(20)->Arg(30);
