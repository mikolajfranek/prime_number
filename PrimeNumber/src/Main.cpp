#include "Main.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::Fermat();
	factorization->Factor(Elements::MyHelper::GetSemiPrime(20));
	factorization->CheckResult(true);
	delete factorization;
	return 0;
}
