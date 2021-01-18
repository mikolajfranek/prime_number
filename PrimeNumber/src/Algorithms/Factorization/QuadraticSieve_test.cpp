#include "QuadraticSieve.h"

namespace AlgorithmsFactorization {
	// Define benchmark
	static void BM_FactorizationQuadraticSieve(benchmark::State& state) {
		for (auto _ : state){
			AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::QuadraticSieve();
			factorization->Factor(Elements::MyHelper::GetSemiPrime(state.range(0)));
			factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	/*
	 BENCHMARK(BM_FactorizationQuadraticSieve)
		->Arg(20);
	 */
}
