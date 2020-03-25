#include "Configurations/MyConfiguration.h"

#include "Algorithms/SieveOfEratosthenes.h"
#include "Algorithms/Fermat.h"
#include "Algorithms/QuadraticSieve.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(){
	QuadraticSieve::Factor("35");//MyConfiguration::GetSemiPrime(10));
	return 0;
}
