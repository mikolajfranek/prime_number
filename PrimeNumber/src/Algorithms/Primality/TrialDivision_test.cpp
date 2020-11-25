#include "TrialDivision.h"

namespace Primality {
	// Define benchmark
	static void BM_PrimalityTrialDivision_IsPrime(benchmark::State& state) {
		for (auto _ : state){
			Abstracts::Primality *primality = new Primality::TrialDivision();
			primality->CheckResult(primality->IsPrime(Other::MyHelper::GetPrime(state.range(0))), true);
			delete primality;
		}
	}
	static void BM_PrimalityTrialDivision_IsNotPrime(benchmark::State& state) {
		for (auto _ : state){
			Abstracts::Primality *primality = new Primality::TrialDivision();
			primality->CheckResult(primality->IsPrime(Other::MyHelper::GetSemiPrime(state.range(0))), false);
			delete primality;
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_PrimalityTrialDivision_IsPrime)
		->Arg(10)
		->Arg(20);
	BENCHMARK(BM_PrimalityTrialDivision_IsNotPrime)
		->Arg(10)
		->Arg(20);
}
