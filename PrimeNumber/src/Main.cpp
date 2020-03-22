#include "Configurations/MyConfiguration.h"

#include "Algorithms/SieveOfEratosthenes.h"
#include "Algorithms/Fermat.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(){
	Fermat::Factor(MyConfiguration::GetSemiPrime(10));
	return 0;
}
