#include "Algorithms/Factorization/TrialDivision.h"
#include "Algorithms/Factorization/Fermat.h"
#include "Algorithms/Factorization/QuadraticSieve.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	//QuadraticSieve::Factor("15345");
	QuadraticSieve::Factor(MyHelper::GetSemiPrime(10));

	return 0;
}

