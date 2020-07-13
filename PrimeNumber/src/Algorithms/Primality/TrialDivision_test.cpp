#include "TrialDivision.h"

namespace Primality {
	// Define benchmark
	static void BM_PrimalityTrialDivisionPrime(benchmark::State& state) {
		for (auto _ : state){
			TrialDivision::IsPrime(Other::MyHelper::GetPrime(state.range(0)), true);
		}
	}
	static void BM_PrimalityTrialDivisionSemiPrime(benchmark::State& state) {
		for (auto _ : state){
			TrialDivision::IsPrime(Other::MyHelper::GetSemiPrime(state.range(0)), false);
		}
	}
	/* register the function as benchmark with arguments */
	BENCHMARK(BM_PrimalityTrialDivisionPrime)->Arg(10)->Arg(20)->Arg(30);
	BENCHMARK(BM_PrimalityTrialDivisionSemiPrime)->Arg(10)->Arg(20)->Arg(30);
}
