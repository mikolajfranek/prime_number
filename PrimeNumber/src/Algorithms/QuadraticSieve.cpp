#include "QuadraticSieve.h"

void QuadraticSieve::Factor(string input){

	//declare
	mpz_t z_n;
	mpz_t z_nmod2;
	mpz_t z_p;
	mpz_t z_q;

	//init
	mpz_init_set_str(z_n, input.c_str(), 10);
	mpz_init(z_nmod2);
	mpz_init(z_p);
	mpz_init(z_q);

	//start algorithm
	mpz_mod_ui(z_nmod2, z_n, 2);
	if(mpz_cmp_ui(z_nmod2, 0) == 0){
		mpz_div_ui(z_q, z_n, 2);
		mpz_set_ui(z_p, 2);
	}else{

	}

	Algorithm::CheckResult(z_n, z_p, z_q);

	//clear
	mpz_clear(z_n);
	mpz_clear(z_nmod2);
	mpz_clear(z_p);
	mpz_clear(z_q);
}
