#include "QuadraticSieve.h"

namespace Factorization {
	// Define benchmark
	static void BM_FactorizationQuadraticSieve(benchmark::State& state) {
		for (auto _ : state){
			Abstracts::Factorization *factorization = new Factorization::QuadraticSieve();
			factorization->Factor(Other::MyHelper::GetSemiPrime(state.range(0)));
			factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationQuadraticSieve)
		->Arg(10)
		->Arg(20)
		->Arg(30);
}
