#include "TrialDivision.h"

namespace Factorization {
	// Define benchmark
	static void BM_FactorizationTrialDivision(benchmark::State& state) {
		for (auto _ : state){
			Abstracts::Factorization *factorization = new Factorization::TrialDivision();
			factorization->Factor(Other::MyHelper::GetSemiPrime(state.range(0)));
			factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationTrialDivision)->Arg(10)->Arg(20);
}
