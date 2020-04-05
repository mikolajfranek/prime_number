#include "Configurations/MyConfiguration.h"

#include "Algorithms/SieveOfEratosthenes.h"
#include "Algorithms/Fermat.h"
#include "Algorithms/QuadraticSieve.h"

/* run benchmark macro */
//BENCHMARK_MAIN();

int main(int argc, char *argv[]){

	//mpz_t n, p;
	//mpz_init_set_str(n, "5", 10);
	//mpz_init_set_str(p, "41", 10);

	//QuadraticSieve::Tonelli_Shanks(n, p);//MyConfiguration::GetSemiPrime(10));

	//mpz_clear(n);
	//mpz_clear(p);

	//15347

	QuadraticSieve::Factor("11");


	return 0;
}
