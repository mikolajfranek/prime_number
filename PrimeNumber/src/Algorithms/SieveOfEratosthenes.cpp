#include "SieveOfEratosthenes.h"

void SieveOfEratosthenes::Factor(string input){

	//declare
	mpz_t n, q, p, nmod, nsqrt, i;

	//init
	mpz_inits(n, q, p, nmod, nsqrt, i, NULL);

	//set
	mpz_set_str(n, input.c_str(), 10);

	//start algorithm
	mpz_mod_ui(nmod, n, 2);
	if(mpz_cmp_ui(nmod, 0) == 0){
		mpz_div_ui(q, n, 2);
		mpz_set_ui(p, 2);
	}else{
		mpz_mod_ui(nmod, n, 3);
		if(mpz_cmp_ui(nmod, 0) == 0){
			mpz_div_ui(q, n, 3);
			mpz_set_ui(p, 3);
		}else{
			mpz_sqrt(nsqrt, n);
			mpz_set_str(i, "5", 10);
			bool isPrime = true;
			int d = 2;
			while(mpz_cmp(i, nsqrt) <= 0){
				mpz_mod(nmod, n, i);
				if(mpz_cmp_ui(nmod, 0) == 0){
					mpz_div(q, n, i);
					mpz_set(p, i);
					isPrime = false;
					break;
				}
				mpz_add_ui(i, i, d);
				d = 6 - d;
			}
			if(isPrime){
				mpz_set(q, n);
				mpz_set_ui(p, 1);
			}
		}
	}

	//check
	Algorithm::CheckResult(n, q, p);

	//clear
	mpz_clears(n, q, p, nmod, nsqrt, i, NULL);
}
