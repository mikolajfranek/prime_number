#include "Main.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	Abstracts::Factorization *factorization = new Factorization::QuadraticSieve();
	factorization->Factor("15347");//Elements::MyHelper::GetSemiPrime(10));
	factorization->CheckResult();
	delete factorization;
	return 0;
}
