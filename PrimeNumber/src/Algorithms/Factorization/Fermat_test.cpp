#include "Fermat.h"

namespace Factorization {
	// Define benchmark
	static void BM_FactorizationFermat(benchmark::State& state) {
		for (auto _ : state){
			Abstracts::Factorization *factorization = new Factorization::Fermat();
			factorization->Factor(Elements::MyHelper::GetSemiPrime(state.range(0)));
			factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationFermat)
		->Arg(10)
		->Arg(20)
		->Arg(30);
}
