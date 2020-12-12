#include "QuadraticSieve.h"

namespace Factorization {
	// Define benchmark
	static void BM_FactorizationQuadraticSieve(benchmark::State& state) {
		for (auto _ : state){
			Abstracts::Factorization *factorization = new Factorization::QuadraticSieve();
			factorization->Factor(Elements::MyHelper::GetSemiPrime(state.range(0)));
			factorization->CheckResult();
			delete factorization;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_FactorizationQuadraticSieve)
		->Arg(20)
		->Arg(30)
		->Arg(40)
		->Arg(50)
		->Arg(60)
		->Arg(70)
		->Arg(80)
		->Arg(90)
		->Arg(100)
		->Arg(110);
}
