#include "SieveOfEratosthenes.h"
SieveOfEratosthenes::SieveOfEratosthenes() {}

void SieveOfEratosthenes::Factor(string input){

	//declare
	mpz_t n;
	mpz_t p;
	mpz_t q;
	mpz_t iterator;
	mpz_t n_sqrt;
	mpz_t n_mod_iterator;

	//init
	mpz_init_set_str(n, input.c_str(), 10);
	mpz_init(p);
	mpz_init(q);
	mpz_init(n_sqrt);
	mpz_init(n_mod_iterator);

	//start algorithm
	mpz_sqrt(n_sqrt, n); //Set n_sqrt to the truncated integer part of the square root of n.
	for(mpz_init_set_str(iterator, "3", 10); mpz_cmp(iterator, n_sqrt) <= 0; mpz_add_ui(iterator, iterator, 2)){
		mpz_mod(n_mod_iterator, n, iterator);
		if(mpz_cmp_ui(n_mod_iterator, 0) == 0){
			mpz_set(p, iterator);
			mpz_div(q, n, iterator);
			break;
		}
	}

	Algorithm::CheckResult(n, p, q);

	//clear
	mpz_clear(n);
	mpz_clear(p);
	mpz_clear(q);
	mpz_clear(iterator);
	mpz_clear(n_sqrt);
	mpz_clear(n_mod_iterator);
}

SieveOfEratosthenes::~SieveOfEratosthenes() {}
