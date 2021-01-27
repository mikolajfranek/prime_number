#include "Fermat.h"

namespace AlgorithmsFactorization {

	Fermat::Fermat() {}

	Fermat::~Fermat() {}

	void Fermat::Factor(string input){

		//parent
		AlgorithmsAbstracts::IFactorization::SetInput(input);

		//declare
		mpz_t m3, m4, n0, r0;

		//init
		mpz_inits(m3, m4, n0, r0, NULL);

		//algorithm
		mpz_mod_ui(n0, this->m0, 2);
		if(mpz_cmp_ui(n0, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			mpz_sqrtrem(m3, n0, this->m0);
			if(mpz_cmp_ui(n0, 0) != 0){
				mpz_add_ui(m3, m3, 1);
			}
			mpz_pow_ui(m4, m3, 2);
			mpz_sub(m4, m4, this->m0);
			mpz_sqrtrem(r0, n0, m4);
			while(mpz_cmp_ui(n0, 0) != 0){
				mpz_mul_ui(n0, m3, 2);
				mpz_add_ui(n0, n0, 1);
				mpz_add(m4, m4, n0);
				mpz_sqrtrem(r0, n0, m4);
				mpz_add_ui(m3, m3, 1);
			}
			mpz_sub(this->m1, m3, r0);
			mpz_add(this->m2, m3, r0);
		}

		//clear
		mpz_clears(m3, m4, n0, r0, NULL);
	}
}
