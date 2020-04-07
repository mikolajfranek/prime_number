#include "SieveOfEratosthenes.h"

void SieveOfEratosthenes::Factor(string input){

	//declare
	mpz_t n, nmod2, nsqrt, nmoditerator, q, p, iterator;

	//init
	mpz_inits(n, nmod2, nsqrt, nmoditerator, q, p, iterator);

	//set
	mpz_set_str(n, input.c_str(), 10);
	mpz_set_str(iterator, "3", 10);

	//start algorithm
	mpz_mod_ui(nmod2, n, 2);
	if(mpz_cmp_ui(nmod2, 0) == 0){
		mpz_div_ui(q, n, 2);
		mpz_set_ui(p, 2);
	}else{
		bool isPrime = true;
		mpz_sqrt(nsqrt, n);
		for(; mpz_cmp(iterator, nsqrt) <= 0; mpz_add_ui(iterator, iterator, 2)){
			mpz_mod(nmoditerator, n, iterator);
			if(mpz_cmp_ui(nmoditerator, 0) == 0){
				mpz_div(q, n, iterator);
				mpz_set(p, iterator);
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			mpz_set(q, n);
			mpz_set_ui(p, 1);
		}
	}

	//check
	Algorithm::CheckResult(n, q, p);

	//clear
	mpz_clears(n, nmod2, nsqrt, nmoditerator, q, p, iterator);
}
