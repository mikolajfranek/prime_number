#include "Fermat.h"

void Fermat::Factor(string input){

	//declare
	mpz_t n, nmod2, q, p, y, yrem, x, xrem, xpow2, xpow2minusn;

	//init
	mpz_inits(n, nmod2, q, p, y, yrem, x, xrem, xpow2, xpow2minusn);

	//set
	mpz_set_str(n, input.c_str(), 10);

	//start algorithm
	mpz_mod_ui(nmod2, n, 2);
	if(mpz_cmp_ui(nmod2, 0) == 0){
		mpz_div_ui(q, n, 2);
		mpz_set_ui(p, 2);
	}else{
		mpz_sqrtrem(x, xrem, n);
		if(mpz_cmp_ui(xrem, 0) != 0){
			mpz_add_ui(x, x, 1);
		}
		while(true){
			mpz_pow_ui(xpow2, x, 2);
			mpz_sub(xpow2minusn, xpow2, n);
			mpz_sqrtrem(y, yrem, xpow2minusn);
			if(mpz_cmp_ui(yrem, 0) == 0){
				mpz_add(q, x, y);
				mpz_sub(p, x, y);
				break;
			}
			mpz_add_ui(x, x, 1);
		}
	}

	//check
	Algorithm::CheckResult(n, q, p);

	//clear
	mpz_clears(n, nmod2, q, p, y, yrem, x, xrem, xpow2, xpow2minusn);
}
