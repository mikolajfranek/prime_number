#include "Fermat.h"

void Fermat::Factor(string input){

	//declare
	mpz_t n, q, p, nmod2, y, yrem, x, xrem, xmul2, z;

	//init
	mpz_inits(n, q, p, nmod2, y, yrem, x, xrem, xmul2, z, NULL);

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
		mpz_pow_ui(z, x, 2);
		mpz_sub(z, z, n);
		mpz_sqrtrem(y, yrem, z);
		while(mpz_cmp_ui(yrem, 0) != 0){
			mpz_mul_ui(xmul2, x, 2);
			mpz_add_ui(xmul2, xmul2, 1);
			mpz_add(z, z, xmul2);
			mpz_sqrtrem(y, yrem, z);
			mpz_add_ui(x, x, 1);
		}
		mpz_add(q, x, y);
		mpz_sub(p, x, y);
	}

	//check
	Algorithm::CheckResult(n, q, p);

	//clear
	mpz_clears(n, q, p, nmod2, y, yrem, x, xrem, xmul2, z, NULL);
}
