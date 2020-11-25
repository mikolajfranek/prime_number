#include "Fermat.h"

namespace Factorization {

	Fermat::Fermat() {}

	Fermat::~Fermat() {}

	void Fermat::Factor(string input){

		//declare
		mpz_t m3, m4, m5, r0;

		//init
		mpz_set_str(m0, input.c_str(), 10);
		mpz_inits(m3, m4, m5, r0, NULL);

		//algorithm
		mpz_mod_ui(m5, m0, 2);
		if(mpz_cmp_ui(m5, 0) == 0){
			mpz_set_ui(m1, 2);
			mpz_div_ui(m2, m0, 2);
		}else{
			mpz_sqrtrem(m3, m5, m0);
			if(mpz_cmp_ui(m5, 0) != 0){
				mpz_add_ui(m3, m3, 1);
			}
			mpz_pow_ui(m4, m3, 2);
			mpz_sub(m4, m4, m0);
			mpz_sqrtrem(r0, m5, m4);
			while(mpz_cmp_ui(m5, 0) != 0){
				mpz_mul_ui(m5, m3, 2);
				mpz_add_ui(m5, m5, 1);
				mpz_add(m4, m4, m5);
				mpz_sqrtrem(r0, m5, m4);
				mpz_add_ui(m3, m3, 1);
			}
			mpz_sub(m1, m3, r0);
			mpz_add(m2, m3, r0);
		}

		//clear
		mpz_clears(m3, m4, m5, r0, NULL);
	}
}
