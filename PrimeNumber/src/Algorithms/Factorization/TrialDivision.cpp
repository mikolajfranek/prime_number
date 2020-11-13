#include "TrialDivision.h"

namespace Factorization {

	TrialDivision::TrialDivision() {}

	TrialDivision::~TrialDivision() {}

	void TrialDivision::Factor(string input) {

		//declare
		mpz_t n3, n4, b;

		//init
		mpz_set_str(n0, input.c_str(), 10);
		mpz_inits(n3, n4, b, NULL);

		//algorithm
		mpz_mod_ui(n4, n0, 2);
		if(mpz_cmp_ui(n4, 0) == 0){
			mpz_set_ui(n1, 2);
			mpz_div_ui(n2, n0, 2);
		}else{
			mpz_mod_ui(n4, n0, 3);
			if(mpz_cmp_ui(n4, 0) == 0){
				mpz_set_ui(n1, 3);
				mpz_div_ui(n2, n0, 3);
			}else{
				mpz_sqrt(n3, n0);
				short a = 4;
				bool isPrime = true;
				for(mpz_set_ui(b, 5); mpz_cmp(b, n3) <= 0; mpz_add_ui(b, b, a)){
					mpz_mod(n4, n0, b);
					if(mpz_cmp_ui(n4, 0) == 0){
						mpz_set(n1, b);
						mpz_div(n2, n0, b);
						isPrime = false;
						break;
					}
					a = 6 - a;
				}
				if(isPrime == true){
					mpz_set_ui(n1, 1);
					mpz_set(n2, n0);
				}
			}
		}

		//clear
		mpz_clears(n3, n4, b, NULL);
	}
}
