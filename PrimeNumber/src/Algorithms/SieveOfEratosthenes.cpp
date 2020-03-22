#include "SieveOfEratosthenes.h"

void SieveOfEratosthenes::Factor(string input){

	//declare
	mpz_t z_n;
	mpz_t z_nmod2;
	mpz_t z_p;
	mpz_t z_q;
	mpz_t z_iterator;
	mpz_t z_nsqrt;
	mpz_t z_nmoditerator;

	//init
	mpz_init_set_str(z_n, input.c_str(), 10);
	mpz_init(z_nmod2);
	mpz_init(z_p);
	mpz_init(z_q);
	mpz_init_set_str(z_iterator, "3", 10);
	mpz_init(z_nsqrt);
	mpz_init(z_nmoditerator);

	//start algorithm
	mpz_mod_ui(z_nmod2, z_n, 2);
	if(mpz_cmp_ui(z_nmod2, 0) == 0){
		mpz_div_ui(z_q, z_n, 2);
		mpz_set_ui(z_p, 2);
	}else{
		bool isPrime = true;
		mpz_sqrt(z_nsqrt, z_n); //Set n_sqrt to the truncated integer part of the square root of z_n.
		for(; mpz_cmp(z_iterator, z_nsqrt) <= 0; mpz_add_ui(z_iterator, z_iterator, 2)){
			mpz_mod(z_nmoditerator, z_n, z_iterator);
			if(mpz_cmp_ui(z_nmoditerator, 0) == 0){
				mpz_div(z_q, z_n, z_iterator);
				mpz_set(z_p, z_iterator);
				isPrime = false;
				break;
			}
		}
		if(isPrime){
			mpz_set(z_q, z_n);
			mpz_set_ui(z_p, 1);
		}
	}

	Algorithm::CheckResult(z_n, z_p, z_q);

	//clear
	mpz_clear(z_n);
	mpz_clear(z_nmod2);
	mpz_clear(z_p);
	mpz_clear(z_q);
	mpz_clear(z_iterator);
	mpz_clear(z_nsqrt);
	mpz_clear(z_nmoditerator);
}
