#include "Fermat.h"

namespace Factorization {

	Fermat::Fermat() {}

	Fermat::~Fermat() {}

	void Fermat::Factor(string input){

		//declare
		mpz_t n3, n4, n5, r0;

		//init
		mpz_set_str(n0, input.c_str(), 10);
		mpz_inits(n3, n4, n5, r0, NULL);

		//algorithm
		mpz_mod_ui(n5, n0, 2);
		if(mpz_cmp_ui(n5, 0) == 0){
			mpz_set_ui(n1, 2);
			mpz_div_ui(n2, n0, 2);
		}else{
			mpz_sqrt(n3, n0);
			if(mpz_perfect_square_p(n0) != 1){
				mpz_add_ui(n3, n3, 1);
			}
			mpz_pow_ui(n4, n3, 2);
			mpz_sub(n4, n4, n0);
			mpz_sqrt(r0, n4);
			while(mpz_perfect_square_p(n4) != 1){
				mpz_mul_ui(n5, n3, 2);
				mpz_add_ui(n5, n5, 1);
				mpz_add(n4, n4, n5);
				mpz_sqrt(r0, n4);
				mpz_add_ui(n3, n3, 1);
			}
			mpz_sub(n1, n3, r0);
			mpz_add(n2, n3, r0);
		}

		//clear
		mpz_clears(n3, n4, n5, r0, NULL);
	}
}
