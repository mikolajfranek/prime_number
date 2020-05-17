#include "TrialDivision.h"

// Define benchmark
static void BM_TrialDivision(benchmark::State& state) {
	for (auto _ : state){
		TrialDivision::Factor(MyHelper::GetSemiPrime(state.range(0)));
	}
}
/* register the function as benchmark with arguments */
BENCHMARK(BM_TrialDivision)->Arg(10)->Arg(20)->Arg(30);
