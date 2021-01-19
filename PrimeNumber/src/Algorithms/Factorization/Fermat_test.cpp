#include "Fermat.h"

namespace AlgorithmsFactorization {
	// Define benchmark
	static void BM_FactorizationFermat(benchmark::State& state) {
		for (auto _ : state){
			AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::Fermat();
			factorization->Factor(Elements::MyHelper::GetSemiPrime(state.range(0)));
			//factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationFermat)

		->Arg(20);
}
