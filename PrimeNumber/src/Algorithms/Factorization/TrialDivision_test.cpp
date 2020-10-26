#include "TrialDivision.h"

namespace Factorization {
	// Define benchmark
	static void BM_FactorizationTrialDivision(benchmark::State& state) {
		TrialDivision trialDivision;
		for (auto _ : state){
			trialDivision.Factor(Other::MyHelper::GetSemiPrime(state.range(0)));
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationTrialDivision)->Arg(10)->Arg(20);
}
