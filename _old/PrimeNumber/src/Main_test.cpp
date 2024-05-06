#include "../../../_old/PrimeNumber/src/Main.h"

#pragma region Factorization
	/* define benchmark */
	static void BM_FactorizationTrialDivision(benchmark::State& state) {
		for (auto _ : state){
			AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::TrialDivision();
			factorization->Factor(Elements::TestData::GetRSASemiPrime(state.range(0)));
			factorization->CheckResult(false);
			delete factorization;
		}
	}
	static void BM_FactorizationFermat(benchmark::State& state) {
		for (auto _ : state){
			AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::Fermat();
			factorization->Factor(Elements::TestData::GetRSASemiPrime(state.range(0)));
			factorization->CheckResult(false);
			delete factorization;
		}
	}
	static void BM_FactorizationQuadraticSieve(benchmark::State& state) {
		for (auto _ : state){
			AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::QuadraticSieve();
			factorization->Factor(Elements::TestData::GetRSASemiPrime(state.range(0)));
			factorization->CheckResult(false);
			delete factorization;
		}
	}
	/* register the functions as benchmark with arguments */
	BENCHMARK(BM_FactorizationTrialDivision)
		->Arg(64);
	BENCHMARK(BM_FactorizationFermat)
		->Arg(64);
	BENCHMARK(BM_FactorizationQuadraticSieve)
		->Arg(64);
#pragma endregion Factorization
