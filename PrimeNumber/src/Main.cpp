#include "Algorithms/Factorization/TrialDivision.h"
#include "Algorithms/Factorization/Fermat.h"
#include "Algorithms/Factorization/QuadraticSieve.h"
#include "Configurations/MyHeader.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){
	QuadraticSieve::Factor("15347");
	return 0;
}

