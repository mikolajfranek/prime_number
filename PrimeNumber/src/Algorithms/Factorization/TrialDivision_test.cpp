#include "TrialDivision.h"

namespace AlgorithmsFactorization {
	// Define benchmark
	static void BM_FactorizationTrialDivision(benchmark::State& state) {
		for (auto _ : state){
			AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::TrialDivision();
			factorization->Factor(Elements::MyHelper::GetSemiPrime(state.range(0)));
			factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationTrialDivision)
		->Arg(10)
		->Arg(20);
}
