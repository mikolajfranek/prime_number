#include "Configurations/MyConfiguration.h"

#include "Algorithms/TrialDivision.h"
#include "Algorithms/Fermat.h"
#include "Algorithms/QuadraticSieve.h"

/* run benchmark macro */
//BENCHMARK_MAIN();



int main(int argc, char *argv[]){

	QuadraticSieve::Factor("15347");

	return 0;
}

