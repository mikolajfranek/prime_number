#include "Main.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	Abstracts::Factorization *factorization = new Factorization::QuadraticSieve();
	factorization->Factor(Elements::MyHelper::GetSemiPrime(40));
	factorization->CheckResult();
	delete factorization;
	return 0;
}
