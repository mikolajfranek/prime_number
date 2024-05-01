#include "Main.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::Fermat();
	factorization->Factor(Elements::TestData::GetRSASemiPrime(64));
	factorization->CheckResult(true);
	delete factorization;
	return 0;
}
