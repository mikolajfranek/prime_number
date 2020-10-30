#include "MyHeader.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	Abstracts::Factorization *factorization = new Factorization::TrialDivision();
	factorization->Factor(Other::MyHelper::GetSemiPrime(10));
	factorization->CheckResult();
	delete factorization;
	return 0;
}
