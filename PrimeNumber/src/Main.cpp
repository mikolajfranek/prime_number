#include "Main.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

#include <iostream>
#include <gmpxx.h>

int main(int argc, char *argv[]){
	AlgorithmsAbstracts::IFactorization *factorization = new AlgorithmsFactorization::QuadraticSieve();
	factorization->Factor(Elements::TestData::GetRSASemiPrime(64));
	factorization->CheckResult(true);
	delete factorization;
	return 0;
}
