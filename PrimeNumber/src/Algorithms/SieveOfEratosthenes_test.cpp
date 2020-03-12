#include "SieveOfEratosthenes.h"

// Define another benchmark
static void BM_Factor(benchmark::State& state) {
	for (auto _ : state){
		SieveOfEratosthenes::Factor(MyConfiguration::GetSemiPrime(state.range(0)));
	}
}
BENCHMARK(BM_Factor)
->Arg(10)
->Arg(20)
->Arg(40)
->Arg(60)
->Arg(80)
->Arg(100);
