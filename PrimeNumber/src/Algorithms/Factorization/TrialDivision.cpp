#include "TrialDivision.h"

namespace Factorization {

	TrialDivision::TrialDivision() {}

	TrialDivision::~TrialDivision() {}

	void TrialDivision::Factor(string input) {

		//declare
		mpz_t m3, m4, n0;

		//init
		mpz_set_str(m0, input.c_str(), 10);
		mpz_inits(m3, m4, n0, NULL);

		//algorithm
		mpz_mod_ui(m4, m0, 2);
		if(mpz_cmp_ui(m4, 0) == 0){
			mpz_set_ui(m1, 2);
			mpz_div_ui(m2, m0, 2);
		}else{
			mpz_mod_ui(m4, m0, 3);
			if(mpz_cmp_ui(m4, 0) == 0){
				mpz_set_ui(m1, 3);
				mpz_div_ui(m2, m0, 3);
			}else{
				mpz_sqrt(m3, m0);
				short a = 4;
				bool isPrime = true;
				for(mpz_set_ui(n0, 5); mpz_cmp(n0, m3) <= 0; mpz_add_ui(n0, n0, a)){
					mpz_mod(m4, m0, n0);
					if(mpz_cmp_ui(m4, 0) == 0){
						mpz_set(m1, n0);
						mpz_div(m2, m0, n0);
						isPrime = false;
						break;
					}
					a = 6 - a;
				}
				if(isPrime == true){
					mpz_set_ui(m1, 1);
					mpz_set(m2, m0);
				}
			}
		}

		//clear
		mpz_clears(m3, m4, n0, NULL);
	}
}
