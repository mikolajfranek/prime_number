#include "../../../../../_old/PrimeNumber/src/Algorithms/Factorization/Fermat.h"

namespace AlgorithmsFactorization {

	Fermat::Fermat() {}

	Fermat::~Fermat() {}

	void Fermat::Factor(string input){

		//parent
		AlgorithmsAbstracts::IFactorization::SetInput(input);

		//declare
		mpz_t m3, n0, n1, r0;

		//init
		mpz_inits(m3, n0, n1, r0, NULL);

		//algorithm
		mpz_mod_ui(n1, this->m0, 2);
		if(mpz_cmp_ui(n1, 0) == 0){
			mpz_set_ui(this->m1, 2);
			mpz_div_ui(this->m2, this->m0, 2);
		}else{
			mpz_sqrtrem(m3, n1, this->m0);
			if(mpz_cmp_ui(n1, 0) != 0){
				mpz_add_ui(m3, m3, 1);
			}
			mpz_pow_ui(n0, m3, 2);
			mpz_sub(n0, n0, this->m0);
			mpz_sqrtrem(r0, n1, n0);
			while(mpz_cmp_ui(n1, 0) != 0){
				mpz_mul_ui(n1, m3, 2);
				mpz_add_ui(n1, n1, 1);
				mpz_add(n0, n0, n1);
				mpz_sqrtrem(r0, n1, n0);
				mpz_add_ui(m3, m3, 1);
			}
			mpz_sub(this->m1, m3, r0);
			mpz_add(this->m2, m3, r0);
		}

		//clear
		mpz_clears(m3, n0, n1, r0, NULL);
	}
}
