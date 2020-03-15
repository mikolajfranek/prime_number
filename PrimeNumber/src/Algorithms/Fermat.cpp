#include "Fermat.h"

void Fermat::Factor(string input){

	//declare
	mpz_t z_n;
	mpz_t z_p;
	mpz_t z_q;
	mpz_t z_y;
	mpz_t z_yrem;
	mpz_t z_x;
	mpz_t z_xrem;
	mpz_t z_xpow2;
	mpz_t z_xpow2minusn;

	//init
	mpz_init_set_str(z_n, input.c_str(), 10);
	mpz_init(z_p);
	mpz_init(z_q);
	mpz_init(z_y);
	mpz_init(z_yrem);
	mpz_init(z_x);
	mpz_init(z_xrem);
	mpz_init(z_xpow2);
	mpz_init(z_xpow2minusn);

	//start algorithm
	mpz_sqrtrem(z_x, z_xrem, z_n);
	if(mpz_cmp_ui(z_xrem, 0) != 0){
		mpz_add_ui(z_x, z_x, 1);
	}
	while(true){
		mpz_pow_ui(z_xpow2, z_x, 2);
		mpz_sub(z_xpow2minusn, z_xpow2, z_n);
		mpz_sqrtrem(z_y, z_yrem, z_xpow2minusn);
		if(mpz_cmp_ui(z_yrem, 0) == 0){
			mpz_sub(z_p, z_x, z_y);
			mpz_add(z_q, z_x, z_y);
			break;
		}
		mpz_add_ui(z_x, z_x, 1);
	}

	Algorithm::CheckResult(z_n, z_p, z_q);

	//clear
	mpz_clear(z_n);
	mpz_clear(z_p);
	mpz_clear(z_q);
	mpz_clear(z_y);
	mpz_clear(z_yrem);
	mpz_clear(z_x);
	mpz_clear(z_xrem);
	mpz_clear(z_xpow2);
	mpz_clear(z_xpow2minusn);
}
