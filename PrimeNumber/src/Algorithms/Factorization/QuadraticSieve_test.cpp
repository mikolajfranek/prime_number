#include "QuadraticSieve.h"

namespace Factorization {
	// Define benchmark
	static void BM_FactorizationQuadraticSieve(benchmark::State& state) {
		for (auto _ : state){
			Abstracts::Factorization *factorization = new Factorization::QuadraticSieve();
			factorization->Factor("9754399201265819");//Elements::MyHelper::GetSemiPrime(state.range(0)));
			factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationQuadraticSieve)
		->Arg(20)
		->Arg(30);
}
